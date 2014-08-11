#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Token.h"
#include "CharSet.h"
#include "StringObject.h"
#include "Text.h"
#include "CException.h"
#include "ErrorCode.h"


#define MAIN_OPERATOR_TABLE_SIZE (sizeof(mainOperatorTable)/(sizeof(OperatorInfo))
#define ALTERNATIVE_OPERATOR_TABLE_SIZE (sizeof(alternativeOperatorTable)/(sizeof(OperatorInfo))

OperatorInfo mainOperatorTable[] = {
  {.symbol="~", .id=BITWISE_NOT_OP, .precedence=150, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="!", .id=LOGICAL_NOT_OP, .precedence=150, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="*", .id=MUL_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="/", .id=DIV_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="%", .id=MOD_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="+", .id=ADD_OP, .precedence=80, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="-", .id=SUB_OP, .precedence=80, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="&", .id=BITWISE_AND_OP, .precedence=60, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="^", .id=BITWISE_XOR_OP, .precedence=50, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="|", .id=BITWISE_OR_OP, .precedence=40, .affix=INFIX, .assoc=LEFT_TO_RIGHT},  
  {.symbol="&&", .id=LOGICAL_AND_OP, .precedence=30, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="||", .id=LOGICAL_OR_OP, .precedence=20, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  // All other symbols MUST have higher precedence than those below:
  {.symbol="(", .id=OPENING_BRACKET_OP, .precedence=10, .affix=PREFIX, .assoc=RIGHT_TO_LEFT},
  {.symbol=")", .id=CLOSING_BRACKET_OP, .precedence=9,  .affix=POSTFIX, .assoc=LEFT_TO_RIGHT}
};

OperatorInfo alternativeOperatorTable[] = {
  {.symbol="+", .id=PLUS_OP, .precedence=150, .affix=PREFIX, .assoc=RIGHT_TO_LEFT},
  {.symbol="-", .id=MINUS_OP, .precedence=150, .affix=PREFIX, .assoc=RIGHT_TO_LEFT}
};

/**
 * Create a Number token initialized to the value given.
 *
 * Input:
 *   value is the value to initialized with
 */
Number *numberNew(int value) {
  Number *numbers=malloc(sizeof(value));
 
  numbers->type=NUMBER_TOKEN;
  numbers->value=value;
  
  return numbers;
}

/**
 * Create an Operator token identified by symbol.
 *
 * Input:
 *   symbol is symbol in string of characters, i.e., "*"
 *          and "&&".
 */
Operator *operatorNewBySymbol(char *symbol) {
  
  Operator *operators = malloc(sizeof(operators));
  
  operators->type=OPERATOR_TOKEN;
	int i=0;
	
	while(mainOperatorTable[i].symbol!=0){
	if(strcmp(mainOperatorTable[i].symbol,symbol)==0)
	{
		operators->info = &mainOperatorTable[i];
		return operators;
	}
	i++;
	}
	return NULL;
	
}

/**
 * Create an Operator token identified by the ID.
 *
 * Input:
 *   symbol is symbol in string of characters, i.e., MUL_OP
 *          and CLOSING_BRACKET_OP.
 */
Operator *operatorNewByID(OperatorID id) {
 
 Operator *operators=malloc(sizeof(operators));
  
  operators->type=OPERATOR_TOKEN;
	int i=0;
	while(mainOperatorTable[i].id!=0){
	if(mainOperatorTable[i].id==id)
	{
		operators->info = &mainOperatorTable[i];
		return operators;
	}
	i++;
	}
	return NULL;
}

/**
 * Create an Identifier token initialized with the name
 * given.
 *
 * Input:
 *   name is the name of the identifier.
 *	Return identifier data.
 */

 Identifier *identifierNew(Text *name) {
	
	Identifier *identifier = malloc(sizeof(identifier));
	
	identifier->name = name;
	identifier->type = IDENTIFIER_TOKEN;
	identifier->number = NULL;
	
	return identifier;
	
}

/**
 * Return the one token from the String. The String is updated.
 * If the string is empty, NULL is return.
 *
 * Input:
 *   str  is the String object
 *
 * Possible returned token:
 *    Number, Operator, and Identifier tokens
 */
Token *getToken(String *str) {
	Number *num;
	Operator *op;
	Identifier *id;
	int number;
	int length;
	String *stringRemoveWordContain;
	Token *newToken;
	char opeToken[3];
	Text *strSubInText;
	
	
	stringTrimLeft(str);
	//Number Token
	if(stringCharAtInSet(str,0,numberSet))
	{
		stringRemoveWordContain = stringRemoveWordContaining(str,numberSet);
		
		if(isSpace(stringCharAt(str,0)) || str->length==0 ||str->start!=0)
		{
			number = stringToInteger(stringRemoveWordContain);
			num = numberNew(number);
			newToken = (Token*)num;
			
		}
		else{
			free(stringRemoveWordContain);
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}
		return newToken;
	}	
	
	
	//Operator Token
	else if(stringCharAtInSet(str,0,operatorSet))
	{
		
		opeToken[0]=(char)stringRemoveChar(str);
		opeToken[1]=0;
		//This condition need to place before isSpace condition as the opeToken[0] will first look for the opeToken[1] if the user input '&' or '|'
		
		if(isSpace(stringCharAt(str,0)) || (str->length==0) || (str->start!=0))
		{
			if(opeToken[0]!=stringCharAt(str,str->start))
			{
				if(opeToken[0]=='&')
				{
					opeToken[1]='&';
					opeToken[2]=0;
					str->start++;
					str->length--;
				}
				else if(opeToken[0]=='|')
				{
					opeToken[1]='|';
					opeToken[2]=0;
					str->start++;
					str->length--;
				}
			}
			
			op = operatorNewBySymbol(opeToken);	
			newToken = (Token*)op;
			
		}
		else
		{	
			
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}
		return newToken;
	}
	
	//Identifier Token
	
	else if(stringCharAtInSet(str,0,alphabetSet))
	{
		stringRemoveWordContain = stringRemoveWordContaining(str,alphabetSet);
		
		
		if(isSpace(stringCharAt(str,0))||str->length==0 ||str->start!=0 )
		{
			strSubInText = stringSubstringInText(stringRemoveWordContain,stringRemoveWordContain->start,stringRemoveWordContain->length);
			id = identifierNew(strSubInText);
			newToken = (Token*)id;
			
		}
		
		else
		{
			free(stringRemoveWordContain);
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}	
		return newToken;
	}
	
	else
		//free(stringRemoveWordContain);
		Throw(ERR_NUMBER_NOT_WELL_FORMED);
	
	
	
}

/**
 * Delete a token
 *
 * Input:
 *   token	the token to delete
 *
 */
 
void tokenDel(Token *token)
{
	
	if(token->type == NUMBER_TOKEN)
	{	
		((Number *)token)->value=0;
		free(token);
	}else if(token->type == IDENTIFIER_TOKEN)
	{	
		textDel(((Identifier*)token)->name);
		if(((Identifier*)token)->number)
		{
			tokenDel((Token*)(((Identifier*)token)->number));
			
		}
		free(token);
	}else if(token->type == OPERATOR_TOKEN)
	{
		if(((Operator *)token)->info != NULL){
		((Operator *)token)->info->id = EMPTY_OP;
		}
	}

	//free(token);
}

void tokenDump(Token *token){
	
	if(token==NULL)
	{
		printf("NULL token\n");
		return;
	}
	
	if(token->type == NUMBER_TOKEN){
		printf("Number Token=%d\n",((Number*)token)->value);
	}else if(token->type == OPERATOR_TOKEN){		
		printf("Operator Token=%s, precedence=%d, affix=%d\n",
					((Operator*)token)->info->symbol,
					((Operator*)token)->info->precedence,
					((Operator*)token)->info->affix);
	}else if(token->type == IDENTIFIER_TOKEN){
		printf("Identifier Token=%s\n",((Identifier*)token)->name);
	}else{
		printf("Unknown Token\n");
	}
}