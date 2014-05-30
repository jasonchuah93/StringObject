#include "StringObject.h"

void stringDump(String *string){
	uint32 index = 0; len= 0;
	char *fullString = "(NULL)";
	char *actualString = "(NULL)";
	
	if(string == NULL){
		printf("NULL\n");
		return;
	}
	if(string->text !=NULL){
		index = string->start;
		len = string->length;;
		fullString = string->text.string;
		actualString =&fullString[index];
	}
	
	print("[%d] f_str:%s, start:%d, len:%d, str:%s\n",		\
			string->reference,fullString,index,len,actualString);
			
		return;
		
}