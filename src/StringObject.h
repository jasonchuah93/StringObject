#ifndef StringObject_H
#define StringObject_H


#include "Types.h"
#include "Text.h"

#define t (Text *)"\x00\x00\x00\x80"
#define isSpace(ch) (ch == ' ' || ch== '\t')
 

typedef struct String{
	uint32 reference;
	Text *text;
	uint32 start;
	uint32 length;
}String;

void stringDump(String *string);

String *stringNew(Text *text);
String *stringAssign(String *string);
String *stringDel(String *string);

void stringTrimLeft(String *string);
void stringTrimRight(String *string);
void stringTrim(String *string);
void stringSkip(String *string,int numOfChar2Skip);

//Test 2 
int stringRemoveChar(String *string);
int stringLength(String *string);
String *stringRemoveWordNotContaining(String *string,char *delimiters);
String *stringRemoveWordContaining(String *string,char containSet[] );
int stringIsEqual(String *string1,String *string2);
int stringIsEqualCaseInsensitive(String *string1,String *string2);
int stringCharAt(String *str,int relativeIndex);
int stringCharAtInSet(String *str,int relativeIndex,char set[]);

int stringToInteger(String *str);
char *stringSubstringInChar(String *str,int relativePosition,int length);
Text *stringSubstringInText(String *str,int relativePosition,int length);
#endif // StringObject_H
