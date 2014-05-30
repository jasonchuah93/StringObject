#ifndef StringObject_H
#define StringObject_H


typedef unsigned int uint32;
typedef int int32;
typedef unsigned char uint8;
typedef char int8;

#define t (Text *)"\x00\x00\x00\x80"

#define isSpace(ch) (ch == ' ' || ch== '\t')
 
typedef struct Text{
	uint32 reference;
	char string[0];
}Text;

typedef struct String{
	uint32 reference;
	Text *text;
	uint32 start;
	uint32 length;
}String;

void stringDump(String *string);
void textDump(Text *text);
void stringSkip(String *string,int numOfChar2Skip);
Text *textAssign(Text *text);
Text *textNew(char *charStr);
Text *textDel(Text *text);
String *stringAssign(String *string);
String *stringDel(String *string);
String *stringNew(Text *text);


#endif // StringObject_H
