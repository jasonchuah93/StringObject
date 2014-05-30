#include <stdio.h>
#include<string.h>
#include <malloc.h>
#include "StringObject.h"


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
	char ch=string->text->string[0];
	while(isSpace(ch))
	{
		i++;
		ch=string->text->string[i];
		string->start++;
	
		
}

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
	
	if(string->reference !=0x80000000){
		string->reference++;
		
	}
	return string;
}

String *stringDel(String *string){
	//if text->reference is not equals to 0x80000000 do//
	//normal text deletion
	// elso do nothing
	
	if(string->reference ==0 ){
		if(string->reference){
		printf("free");
		free(string);
		return NULL;
	}
	
	}
	
	return string;
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
		if(text->reference--){
		free(text);
		return NULL;
		}
	
	}
	
	return text;
}


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


void atomic(String *string){


}
