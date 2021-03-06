#ifndef Text_H
#define Text_H

#include "Types.h"


#define t (Text *)"\x00\x00\x00\x80"
#define isSpace(ch) (ch == ' ' || ch== '\t')
 
typedef struct Text{
	uint32 reference;
	char string[0];
}Text;

void textDump(Text *text);

Text *textNew(char *charStr);
Text *textAssign(Text *text);
Text *textDel(Text *text);


#endif // Text_H