#include <stdio.h>
#include<string.h>
#include <malloc.h>
#include "Text.h"
#include "StringObject.h"

/*
 * Use to display the data user input 
 *
 * Input:
 *   text is the in Text type 
 */
 
void textDump(Text *text){
	if(text == NULL){
		printf("(NULL)");
		return;
	}
	printf("text[%x]:%s\n",text->reference,text->string);
}

/**
 * Use to increase reference of the text
 *
 * Input:
 * 	text which user input
 */
Text *textAssign(Text *text){
	if(text->reference !=0x80000000){
		text->reference++;
		
	}
	return text;
}

/**
 * Use to convert the char type of the string into text type
 *
 * Input:
 * 	charStr is the string user input
 */
  		
Text *textNew(char *charStr){
	Text *text = (Text *)malloc(strlen(charStr)+4+1);
		//Character string copy from charStr to text->string
		//...
	strcpy(text->string,charStr); //destination source
	text->reference=1;
	return text;
}

/**
 * Use to delete one text reference 
 *
 * Input:
 *	text which user input
 */

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

