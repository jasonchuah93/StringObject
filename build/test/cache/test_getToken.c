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



void xtest_getToken_should_get_number_token_from_string_with_space_infront_and_left_empty_space(void){



 Text *testTokenizer = textNew("                   234");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)29);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);



}



void test_getToken_should_get_234_from_string_with_space_in_between_and_left_space567(void){



 Text *testTokenizer = textNew("234 567");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken;



 testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)42);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 567"), (strTokenizer), 45, ((void *)0));



 stringDump(strTokenizer);

}



void test_getToken_should_get_234_from_string_contain_alphabets_with_space_in_between_and_left_spacejason(void){



 Text *testTokenizer = textNew("  234 jason");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)55);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((testToken->type)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);



}



void test_getToken_should_throw_error_when_characters_is_behind(void){

 int e;

 Text *testTokenizer = textNew("234jason");

 String *strTokenizer = stringNew(testTokenizer);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *testToken = getToken(strTokenizer);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_throw_error_from_string_combine_with_alphabets_and_operators(void){

 int e;

 Text *testTokenizer = textNew("2!3+4-jason");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)79);;};

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("!3+4-jason"), (strTokenizer), 82, ((void *)0));

}



void test_getToken_should_throw_an_error_for_string_start_with_alphabet_first(void){

 int e;

 Text *testTokenizer = textNew("jason234");

 String *strTokenizer = stringNew(testTokenizer);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *testToken = getToken(strTokenizer);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

  return;

 }



}



void test_getToken_should_get_operator_token_and_return_ADD_OP_and_left_empty_space(void){



 Text *text = textNew("+");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)105);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strToken), 108, ((void *)0));

}



void test_getToken_should_get_operator_token_with_space_at_front_and_return_ADD_OP_and_left_empty_space(void){



 Text *text = textNew("                   +");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)118);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);



}



void test_getToken_should_get_operator_token_and_number_token(void){



 Text *text = textNew("1+2");

 String *strToken = stringNew(text);

 Token *testToken;



 testToken = getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)131);;};

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)132, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)133, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("+2"), (strToken), 134, ((void *)0));



 testToken = getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)137);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((testToken->type)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator*)testToken)->info->symbol), (((void *)0)), (_U_UINT)139);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((((Operator*)testToken)->info->id)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((((Operator*)testToken)->info->precedence)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("2"), (strToken), 142, ((void *)0));



 testToken = getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)145);;};

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strToken), 148, ((void *)0));

}



void test_getToken_should_get_operator_token_number_token_and_identieifer_token(void){



 Text *text = textNew("1+jason");

 String *strToken = stringNew(text);

 Token *testToken;



 testToken = getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)158);;};

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("+jason"), (strToken), 161, ((void *)0));



 testToken = getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)164);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((testToken->type)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator*)testToken)->info->symbol), (((void *)0)), (_U_UINT)166);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((((Operator*)testToken)->info->id)), (((void *)0)), (_U_UINT)167, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((((Operator*)testToken)->info->precedence)), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("jason"), (strToken), 169, ((void *)0));





 testToken= getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)173);;};

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((((Identifier*)testToken)->type)), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("jason"), (const char*)(((Identifier*)testToken)->name->string), (((void *)0)), (_U_UINT)175);

 assertStringEqual((""), (strToken), 176, ((void *)0));

}







void test_getToken_should_throw_error_for_string_operator_and_characters(void){

 int e;

 Text *text = textNew("*apple");

 String *strToken = stringNew(text);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *opeToken = getToken(strToken);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space(void){



 Text *text = textNew("&&");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)203);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)204, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)205, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strToken), 206, ((void *)0));



}



void test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space_and_characters_and_numbers(void){



 Text *text = textNew("&& orange  777");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)218, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)219);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)221, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" orange  777"), (strToken), 222, ((void *)0));



}



void test_getToken_should_get_operators_token_with_space_at_front_and_return_LOGICAL_AND_OP_and_left_empty_space_and_characters_and_numbers(void){



 Text *text = textNew("               && orange  777");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)234, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)235);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)236, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space(void){



 Text *text = textNew("||");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)248, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("||"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)249);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_OR_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)250, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)251, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strToken), 252, ((void *)0));



}



void test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space_and_characters(void){



 Text *text = textNew("|| orange guava");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("||"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)265);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_OR_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)266, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)267, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" orange guava"), (strToken), 268, ((void *)0));



}



void test_getToken_should_get_two_different_operators_token_and_throw_an_error(void){

 int e;

 Text *text = textNew("|%");

 String *strToken = stringNew(text);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *opeToken = getToken(strToken);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)280, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_get_two_different_operators_token_and_throw_an_error2(void){

 int e;

 Text *text = textNew("               +&");

 String *strToken = stringNew(text);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *opeToken = getToken(strToken);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)293, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_get_space_between_two_different_operators_token_and_throw_an_error(void){

 int e;

 Text *text = textNew("/ ^");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 if ((((opeToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)306);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)307, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("/"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)308);

 UnityAssertEqualNumber((_U_SINT)((DIV_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)309, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" ^"), (strToken), 311, ((void *)0));



}



void test_getToken_should_get_identifier_token_from_string(void){

 Text *testTokenizer = textNew("Jason 016");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);



 stringDump(strTokenizer);



 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)322);;};

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((((Identifier*)testToken)->type)), (((void *)0)), (_U_UINT)323, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("Jason"), (const char*)(((Identifier*)testToken)->name->string), (((void *)0)), (_U_UINT)324);

 assertStringEqual((" 016"), (strTokenizer), 325, ((void *)0));

}



void test_tokenDel_should_delete_Number_token_and_return_empty_string(void){

 Text *text1 = textNew("123");

 String *string1 = stringNew(text1);

 Token *testToken;

 testToken = getToken(string1);



 tokenDel(testToken);

 stringDump(string1);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((((Number*)testToken)->type)), (((void *)0)), (_U_UINT)337, UNITY_DISPLAY_STYLE_INT);

}



void test_tokenDel_should_delete_Identifier_token_and_return_empty_string(void){

 Text *text1 = textNew("Jason");

 String *string1 = stringNew(text1);

 Token *testToken;

 testToken = getToken(string1);



 tokenDel(testToken);

 stringDump(string1);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((((Identifier*)testToken)->type)), (((void *)0)), (_U_UINT)349, UNITY_DISPLAY_STYLE_INT);

}



void test_tokenDel_should_delete_Operator_token_and_return_empty_string(void){

 Text *text1 = textNew("&&");

 String *string1 = stringNew(text1);

 Token *testToken;

 testToken = getToken(string1);



 tokenDel(testToken);

 stringDump(string1);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((((Operator*)testToken)->type)), (((void *)0)), (_U_UINT)361, UNITY_DISPLAY_STYLE_INT);

}



void test_tokenDel_should_getToken_for_left_parenthesis(void){

 Text *text1 = textNew("(16)");

 String *string1 = stringNew(text1);

 Token *testToken;





 testToken = getToken(string1);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((testToken->type)), (((void *)0)), (_U_UINT)371, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("("), (const char*)(((Operator*)testToken)->info->symbol), (((void *)0)), (_U_UINT)372);

 UnityAssertEqualNumber((_U_SINT)((OPENING_BRACKET_OP)), (_U_SINT)((((Operator*)testToken)->info->id)), (((void *)0)), (_U_UINT)373, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((((Operator*)testToken)->info->precedence)), (((void *)0)), (_U_UINT)374, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("16)"), (string1), 375, ((void *)0));

 stringDump(string1);





 testToken = getToken(string1);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)380);;};

 UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)381, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)382, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((")"), (string1), 383, ((void *)0));

 stringDump(string1);





 testToken = getToken(string1);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((testToken->type)), (((void *)0)), (_U_UINT)388, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)(")"), (const char*)(((Operator*)testToken)->info->symbol), (((void *)0)), (_U_UINT)389);

 UnityAssertEqualNumber((_U_SINT)((CLOSING_BRACKET_OP)), (_U_SINT)((((Operator*)testToken)->info->id)), (((void *)0)), (_U_UINT)390, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((((Operator*)testToken)->info->precedence)), (((void *)0)), (_U_UINT)391, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string1), 392, ((void *)0));

 stringDump(string1);



}
