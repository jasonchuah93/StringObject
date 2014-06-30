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
 */

 Identifier *identifierNew(Text *name) {
	
	Identifier *identifiers = malloc(sizeof(identifiers));
	
	identifiers->type = IDENTIFIER_TOKEN;
	identifiers->name = name;
	identifiers->number = NULL;
	
	return identifiers;
	
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
	Operator *op;
	int number;
	int length;
	String *alphabet;
	String *stringRemoveWordContain;
	Token *newToken;
	char opeToken[3];
	
	//Number Token
	if(stringCharAtInSet(str,str->start,numberSet))
	{	
		stringRemoveWordContain = stringRemoveWordContaining(str,numberSet);
		
		if((isSpace(stringCharAt(str,0)))||(str->length==0)||(str->start!=0))
		{
			number = stringToInteger(stringRemoveWordContain);
			newToken=(Token*)numberNew(number);
		}
		else{
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
			free(newToken);
		}
	}	
	//Operator Token
	else if(stringCharAtInSet(str,0,operatorSet))
	{
		opeToken[0]=(char)stringRemoveChar(str);
		opeToken[1]=0;
		//This condition need to place before isSpace condition as the opeToken[0] will first look for the opeToken[1] if the user input '&' or '|'
		if(opeToken[0]!=stringCharAt(str,0))
		{
			if(opeToken[0] == '&')
			{
				opeToken[1]='&';
				opeToken[2]=0;
			}
			else if(opeToken[0] == '|')
			{
				opeToken[1]='|';
				opeToken[2]=0;
			}
			
		}
		
		if((isSpace(stringCharAt(str,0)))||(str->length==0)||(str->start!=0))
		{
			op = operatorNewBySymbol(opeToken);			
			newToken = (Token*)op;
		}
		else
		{
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
			free(newToken);
		}
	}
	/*
	//Identifier Token
	else if(stringCharAtInSet(str,str->start,alphabetSet))
	{
		alphabet=stringRemoveWordContaining(str,alphabetSet);
		return (Token*)identifierNew(stringSubstringInText(str,0,length));
	}
	*/
	
	return newToken; 
	
}
