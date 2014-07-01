#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"
#include "CharSet.h"
#include "CException.h"


void setUp(void){}

void tearDown(void){}



void test_getToken_should_get_number_token_from_string_and_left_empty_space(void){



 Text *testTokenizer = textNew("234");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)18);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strTokenizer), 21, ((void *)0));

}



void test_getToken_should_get_234_from_string_with_space_in_between_and_left_space567(void){



 Text *testTokenizer = textNew("234 567");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)29);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 567"), (strTokenizer), 32, ((void *)0));



}



void test_getToken_should_get_234_from_string_contain_alphabets_with_space_in_between_and_left_spacejason(void){



 Text *testTokenizer = textNew("234 jason");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)41);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" jason"), (strTokenizer), 44, ((void *)0));

}



void test_getToken_should_get_234_from_string_with_alphabets_and_left_jason(void){



 Text *testTokenizer = textNew("234jason");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)52);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("jason"), (strTokenizer), 55, ((void *)0));

}



void test_getToken_should_throw_error_from_string_combine_with_alphabets_and_operators(void){

 int e;

 Text *testTokenizer = textNew("2!3+4-jason");

 String *strTokenizer = stringNew(testTokenizer);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *testToken = getToken(strTokenizer);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

  return;

}



void test_getToken_should_throw_an_error_for_string_start_with_alphabet_first(void){

 int e;

 Text *testTokenizer = textNew("jason234");

 String *strTokenizer = stringNew(testTokenizer);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *testToken = getToken(strTokenizer);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

  return;

 }



}



void test_getToken_should_get_operator_token_and_return_ADD_OP_and_left_empty_space(void){



 Text *text = textNew("+");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)91);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strToken), 94, ((void *)0));

}



void test_getToken_should_get_operator_token_and_return_MUL_OP_and_left_empty_space_and_characters_and_numbers(void){



 Text *text = textNew("* apple 111");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("*"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)106);

 UnityAssertEqualNumber((_U_SINT)((MUL_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" apple 111"), (strToken), 109, ((void *)0));

}



void test_getToken_should_throw_error_for_string_operator_and_characters(void){

 int e;

 Text *text = textNew("*apple");

 String *strToken = stringNew(text);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *opeToken = getToken(strToken);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space(void){



 Text *text = textNew("&&");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)133, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)134);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)136, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strToken), 137, ((void *)0));



}



void test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space_and_characters_and_numbers(void){



 Text *text = textNew("&& orange  777");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)150);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" orange  777"), (strToken), 153, ((void *)0));



}



void test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space(void){



 Text *text = textNew("||");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("||"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)166);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_OR_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)167, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strToken), 169, ((void *)0));



}



void test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space_and_characters(void){



 Text *text = textNew("|| orange guava");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("||"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)182);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_OR_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)184, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" orange guava"), (strToken), 185, ((void *)0));



}



void test_getToken_should_get_two_different_operators_token_and_throw_an_error(void){

 int e;

 Text *text = textNew("|%");

 String *strToken = stringNew(text);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *opeToken = getToken(strToken);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_get_two_different_operators_token_and_throw_an_error2(void){

 int e;

 Text *text = textNew("+&");

 String *strToken = stringNew(text);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *opeToken = getToken(strToken);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)210, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_get_space_between_two_different_operators_token_and_throw_an_error(void){

 int e;

 Text *text = textNew("/ ^");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("/"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)224);

 UnityAssertEqualNumber((_U_SINT)((DIV_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)225, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)226, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" ^"), (strToken), 227, ((void *)0));



}



void test_getToken_should_get_identifier_token_from_string(void){

 Text *testTokenizer = textNew(" Jason");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);



 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)236);;};

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)(((Identifier*)testToken->type)), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("Jason"), (const char*)(((Identifier*)testToken)->name->string), (((void *)0)), (_U_UINT)238);

 assertStringEqual((""), (strTokenizer), 239, ((void *)0));

}



void xtest_getToken_should_get_identifier_token_and_return_Jason_and_left_016_in_string(void){

 Text *testTokenizer = textNew("Jason 016");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);



 printf("%s\n",((Identifier*)testToken)->name->string);











}
