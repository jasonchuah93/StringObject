#include <stdio.h>
#include<string.h>
#include <malloc.h>
#include "StringObject.h"


void textDump(Text *text){
	if(text ==NULL){
		printf("(NULL)");
		return;
	}
	printf("text[%x]:%s\n",text->reference,text->string);
}

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

Text *textAssign(Text *text){
	if(text->reference !=0x80000000){
		text->reference++;
		
	}
	return text;
}
		
Text *textNew(char *charStr){
	Text *text = (Text *)malloc(strlen(charStr)+4+1);
		//Character string copy from charStr to text->string
		//...
	strcpy(text->string,charStr); //destination source
	text->reference=1;
	return text;
}

Text *textDel(Text *text){

	//if text->reference is not equals to 0x80000000 do//
	//normal text deletion
	// elso do nothing
	
	if(text->reference <0x80000000 &&text->reference >0){
		text->reference--;
		if(text->reference == 0){
		free(text);
		return NULL;
		}
	
	}
	
	return text;
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
	char stringStart;
	char stringEnd;
	char newString;
	
	char isAlphabet = string->text->string[i];
	
	while(string->text->string[i]!=0){
		if((string->text->string[i]!=delimiters[j]) || (isAlphabet <= 'a' && isAlphabet >='z')){
			string->start++;
			string->length--;
		}
		else if(string->text->string[i] == delimiters[0]){
			
			return string;
		}
		
		i++;
		
	}	
	
	return string;
}

String *stringRemoveWordContaining(String *string,char containSet[]){
	int i =0 ,j=0 ;
	String *newString = stringNew(string->text);
	newString->start=0;
	newString->length=0;
	
	while(string->text->string[i] != 0)
	{
		if((string->text->string[i]==containSet[j])){
			string->start++;
			string->length--;
			newString->length++;
		}
		else{
			break;
		}
	i++;
	j++;
	}
	return newString;
}

int stringIsEqual(String *string1,String *string2){
	int i,input;
	int stringStart;
	stringStart = string1->text->string[i + string1->start];
	int stringEnd;
	stringEnd = string2->text->string[i + string2->start];
	
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

	return 0;
	
}

int stringIsEqualCaseInSensitive(String *string1,String *string2){
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
