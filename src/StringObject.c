#include <stdio.h>
#include<string.h>
#include <malloc.h>
#include "StringObject.h"
#include "Text.h"
#include <stdlib.h>

void stringDump(String *string){
	uint32 index = 0, len= 0;
	char *fullString = "(NULL)";
	char *actualString = "(NULL)";
	
	if(string == NULL){
		printf("NULL\n");
		return;
	}
	if(string->text !=NULL){
		int actualLength;
		
		fullString = string->text->string;
		index = string->start;
		if(index <= strlen(fullString)){
		actualString =&fullString[index];
		actualLength=strlen(actualString);
		len = string->length;
		if(len > actualLength)
			{
				len=actualLength;
			}
		}
		else{
			actualString = "";
		}
		
	}
	
	printf("[0x%x] f_str:[%x]:%s, start:%d, len:%d, str:%.*s\n",		\
			string->reference,string->text->reference,fullString,	\
			index,string->length,len,actualString);
			
	return;
		
}



String *stringNew(Text *text){
	String *str=malloc(sizeof(String));
	str->text = textAssign(text);
	str->reference =1;
	str->start =0;
	str->length =strlen(text->string);
	return str;
}

String *stringAssign(String *string){
	
	if(string->reference != 0x80000000 ){
		string->reference++;
		
	}
	return string;
}

String *stringDel(String *string){
	
	string->reference--;
	
	if(string->reference ==0 ){
		free(string);
		return NULL;
	}
	
	return string;
}

void stringSkip(String *string,int numOfChar2Skip){
	int fullLength = strlen(string->text->string);
	if(string){
		if(string->start +numOfChar2Skip < fullLength){
			string->start=numOfChar2Skip;
		}
		else{ 
			string->start=fullLength;
			string->length =0;
		}
	
	}
}

void stringTrimLeft(String *string){
	int i=0;
	int ch;
	ch=string->text->string[0];
	while(isSpace(ch))
	{
		i++;
		ch=string->text->string[i];
		string->start++;
	}

}

void stringTrimRight(String *string){
	int i=0;
	int ch;
	ch=string->text->string[0];
	while(!isSpace(ch))
	{
		i--;
		ch=string->start+string->text->string[i];
		string->length--;
	}
}

void stringTrim(String *string){
	stringTrimLeft(string);
	stringTrimRight(string);
}

//Test 2

/**
*Remove one character from String and return it.
*The string is updated to reflect the change.
*input :
*	str :	is String Object
*					
*	Return the character removed if the string is not empty 
*	Otherwise return -1
*	
**/

int stringRemoveChar(String *string){
	
	char stringStart;
	char stringEnd;
	
	stringStart=string->text->string[string->start];
	stringEnd=string->text->string[string->length];
	
	while(stringStart != stringEnd > string->text->string[0])
	{
			string->start++;
			string->length--;
			return stringStart;
	}
	
	return -1;
} 
	
int stringLength(String *string){
	return string->length;
}

String *stringRemoveWordNotContaining(String *string,char *delimiters){
	
	int i=0,j=0;
	String *newString = stringNew(string->text);
	String *deletedString = stringNew(string->text);
	deletedString->start=string->start;
	deletedString->length=0;
	char isAlphabet = string->text->string[i];
	
	while(isAlphabet!=0){
		while(delimiters[j]!=0){
		if(string->text->string[i]!=delimiters[j]){
			goto here;
		}
		else{
			
			deletedString->start=string->start;
			deletedString->length=i-string->start;
			string->start=i;
			string->length=string->length-deletedString->length;
			return deletedString;
			
			}
		here:
		j++;
		
		}
		i++;
		j=0;
		
		}
}

String *stringRemoveWordContaining(String *string,char containSet[]){
	int i =0 ,j=0 ,value=0;
	String *newString = stringNew(string->text);
	newString->start=string->start;
	newString->length=0;
	
	while(string->text->string[i] != 0){
	while(containSet[j]!=0){
		if((string->text->string[i]==containSet[j])){
			string->start++;
			string->length--;
			newString->length++;
			goto here;
		}
		else{
			value++;
		}
		j++;
	}
	if(value>=newString->length)
	{
		goto come;
	}
		here:
		j=0;
		i++;	
	}
	come:
	return newString;
}

int stringIsEqual(String *string1,String *string2){
	int i,input;
	int stringStart;
	stringStart = string1->text->string[i + string1->start];
	int stringEnd;
	stringEnd = string2->text->string[i + string2->start];
	
	if(string1->start == string2->start){
		return 1;
	}
	
	if(string1->length == string2->length){
		return 1;
	}
	
	string1->length = string2->length;
	input = string1->length;

	for(i = 0; i < input; i++){
		if( stringStart != stringEnd ){
			return 0;
		}
		
	}

	
	
}
int stringIsEqualCaseInsensitive(String *string1,String *string2){
	int i;
	for(i=0;string1->text->string[i];i++)
	{
		string1->text->string[i]= tolower(string1->text->string[i]);
	}
	
	for(i=0;string2->text->string[i];i++)
	{
		string2->text->string[i]= tolower(string2->text->string[i]);
	}
	
	stringIsEqual(string1,string2);
	
}

/**
*Return the character at the specified relative index
of the string

input :
	str :	is String Object
	relativeIndex : is the relative index into the string.
					this value must be positive.
					
	Return the character at the relative index if exists.
	Otherwise return -1.If relativeIndex is less than 0, return -1
	as well
**/

int stringCharAt(String *str,int relativeIndex){
	char finalIndex;
	if(relativeIndex < 0 || str->start+relativeIndex >= str->length){
		return -1;
	}
	else{
		
		finalIndex=str->text->string[str->start+relativeIndex];
	}
		return finalIndex;
}
/**
*Determine if the character specified by the relative index in the
*String is in the given set of characters
*input :
*	str :	is String Object
*	relativeIndex : is the relative index into the string.
*					this value must be positive.
*					
*	set 	is the set of character delimited by NULL
*	Return 1 if the character is within the set.
*	Otherwise return 0.
**/
int stringCharAtInSet(String *str,int relativeIndex,char set[]){
	int j=0;
	
	int string1=str->text->string[str->start+relativeIndex];
	
	while(set[j]!=0){
		if(string1==set[j]){
			return 1;
		}
		j++;
	}
	return 0;
}

int stringToInteger(String *str){
	
	int relativePosition,length;
	char *stringInteger; //In string form
	int integerString; //In integer form
	
	relativePosition=str->start;
	length=str->length;
	stringInteger=stringSubstringInChar(str,relativePosition,length);
	integerString=atoi(stringInteger);
	free(stringInteger);
	return integerString;
}

char *stringSubstringInChar(String *str,int relativePosition,int length){
	
	char *subString = malloc(sizeof(char)*(length+1));
	int i=0,j=0;
	
	
	if(length <= str->length){
	for(i=0,j = relativePosition;j <= relativePosition+length-1;i++,j++)
	{
		subString[i]=str->text->string[j];
		
	}
	}
	else{
		return " ";
	}
	subString[i]=0;
	return subString;
}

Text *stringSubstringInText(String *str,int relativePosition,int length){
	char *charStr=stringSubstringInChar(str,relativePosition,length);
	Text *Newtext=textNew(charStr);
	free(charStr);
	return Newtext;

}




  	

