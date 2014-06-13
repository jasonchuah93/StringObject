#include <stdio.h>
#include<string.h>
#include <malloc.h>
#include "Text.h"

void textDump(Text *text){
	if(text ==NULL){
		printf("(NULL)");
		return;
	}
	printf("text[%x]:%s\n",text->reference,text->string);
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