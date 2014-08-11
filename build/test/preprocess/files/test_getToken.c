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



void test_getToken_should_get_number_token_from_string_with_space_infront_and_left_empty_space(void){



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

}



void test_getToken_should_get_234_from_string_contain_alphabets_with_space_in_between_and_left_spacejason(void){



 Text *testTokenizer = textNew("  234 jason");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)53);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((testToken->type)), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_throw_error_when_characters_is_behind(void){

 int e;

 Text *testTokenizer = textNew("234jason");

 String *strTokenizer = stringNew(testTokenizer);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *testToken = getToken(strTokenizer);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_throw_error_from_string_combine_with_alphabets_and_operators(void){

 int e;

 Text *testTokenizer = textNew("2!3+4-jason");

 String *strTokenizer = stringNew(testTokenizer);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *testToken = getToken(strTokenizer);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_throw_an_error_for_string_start_with_alphabet_first(void){

 int e;

 Text *testTokenizer = textNew("jason234");

 String *strTokenizer = stringNew(testTokenizer);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *testToken = getToken(strTokenizer);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_get_operator_token_and_return_ADD_OP_and_left_empty_space(void){



 Text *text = textNew("+");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)103);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strToken), 106, ((void *)0));

}



void test_getToken_should_get_operator_token_with_space_at_front_and_return_ADD_OP_and_left_empty_space(void){



 Text *text = textNew("                   +");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)116);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);



}



void test_getToken_should_get_operator_token_and_number_token(void){



 Text *text = textNew("1+2");

 String *strToken = stringNew(text);

 Token *testToken;



 testToken = getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)129);;};

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)130, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("+2"), (strToken), 132, ((void *)0));



 testToken = getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)135);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((testToken->type)), (((void *)0)), (_U_UINT)136, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator*)testToken)->info->symbol), (((void *)0)), (_U_UINT)137);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((((Operator*)testToken)->info->id)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((((Operator*)testToken)->info->precedence)), (((void *)0)), (_U_UINT)139, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("2"), (strToken), 140, ((void *)0));



 testToken = getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)143);;};

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strToken), 146, ((void *)0));

}



void test_getToken_should_get_operator_token_number_token_and_identieifer_token(void){



 Text *text = textNew("1+jason");

 String *strToken = stringNew(text);

 Token *testToken;



 testToken = getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)156);;};

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("+jason"), (strToken), 159, ((void *)0));



 testToken = getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)162);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((testToken->type)), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator*)testToken)->info->symbol), (((void *)0)), (_U_UINT)164);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((((Operator*)testToken)->info->id)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((((Operator*)testToken)->info->precedence)), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("jason"), (strToken), 167, ((void *)0));





 testToken= getToken(strToken);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)171);;};

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((((Identifier*)testToken)->type)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("jason"), (const char*)(((Identifier*)testToken)->name->string), (((void *)0)), (_U_UINT)173);

 assertStringEqual((""), (strToken), 174, ((void *)0));

}



void test_getToken_should_throw_error_for_string_operator_and_characters(void){

 int e;

 Text *text = textNew("*apple");

 String *strToken = stringNew(text);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *opeToken = getToken(strToken);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space(void){



 Text *text = textNew("&&");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)196, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)197);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)198, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)199, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strToken), 200, ((void *)0));



}



void test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space_and_characters_and_numbers(void){



 Text *text = textNew("&& orange  777");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)210, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)211);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)212, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)213, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" orange  777"), (strToken), 214, ((void *)0));



}



void test_getToken_should_get_operators_token_with_space_at_front_and_return_LOGICAL_AND_OP_and_left_empty_space_and_characters_and_numbers(void){



 Text *text = textNew("               && orange  777");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)225);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)226, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)227, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space(void){



 Text *text = textNew("||");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)236, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("||"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)237);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_OR_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)238, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)239, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (strToken), 240, ((void *)0));

}



void test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space_and_characters(void){



 Text *text = textNew("|| orange guava");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)249, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("||"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)250);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_OR_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)251, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)252, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" orange guava"), (strToken), 253, ((void *)0));



}



void test_getToken_should_get_two_different_operators_token_and_throw_an_error(void){

 int e;

 Text *text = textNew("|%");

 String *strToken = stringNew(text);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  Token *opeToken = getToken(strToken);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)265, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)278, UNITY_DISPLAY_STYLE_INT);

  return;

 }

}



void test_getToken_should_get_space_between_two_different_operators_token_and_throw_an_error(void){

 int e;

 Text *text = textNew("/ ^");

 String *strToken = stringNew(text);

 Token *opeToken = getToken(strToken);



 if ((((opeToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)289);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)290, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("/"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)291);

 UnityAssertEqualNumber((_U_SINT)((DIV_OP)), (_U_SINT)((((Operator*)opeToken)->info->id)), (((void *)0)), (_U_UINT)292, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((((Operator*)opeToken)->info->precedence)), (((void *)0)), (_U_UINT)293, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" ^"), (strToken), 294, ((void *)0));



}



void test_getToken_should_get_identifier_token_from_string(void){

 Text *testTokenizer = textNew("Jason 016");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);



 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)303);;};

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((((Identifier*)testToken)->type)), (((void *)0)), (_U_UINT)304, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("Jason"), (const char*)(((Identifier*)testToken)->name->string), (((void *)0)), (_U_UINT)305);

 assertStringEqual((" 016"), (strTokenizer), 306, ((void *)0));

}



void test_tokenDel_should_delete_Number_token_and_return_empty_string(void){

 Text *text1 = textNew("123");

 String *string1 = stringNew(text1);

 Token *testToken = getToken(string1);



 tokenDel(testToken);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)316, UNITY_DISPLAY_STYLE_INT);

}



void test_tokenDel_should_delete_Identifier_token_and_return_empty_string(void){

 Text *text1 = textNew("Jason");

 String *string1 = stringNew(text1);

 Token *testToken = getToken(string1);



 tokenDel(testToken);

 UnityAssertEqualString((const char*)("b"), (const char*)(((Identifier*)testToken)->name), (((void *)0)), (_U_UINT)325);

}



void test_tokenDel_should_delete_Operator_token_and_return_empty_string(void){

 Text *text = textNew("&&");

 String *string = stringNew(text);

 Token *testToken = getToken(string);



 tokenDel(testToken);



 UnityAssertEqualNumber((_U_SINT)((EMPTY_OP)), (_U_SINT)((((Operator*)testToken)->info->id)), (((void *)0)), (_U_UINT)335, UNITY_DISPLAY_STYLE_INT);

}



void test_tokenDel_should_getToken_for_left_parenthesis(void){

 Text *text = textNew("(16)");

 String *string = stringNew(text);

 Token *testToken;





 testToken = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((testToken->type)), (((void *)0)), (_U_UINT)345, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("("), (const char*)(((Operator*)testToken)->info->symbol), (((void *)0)), (_U_UINT)346);

 UnityAssertEqualNumber((_U_SINT)((OPENING_BRACKET_OP)), (_U_SINT)((((Operator*)testToken)->info->id)), (((void *)0)), (_U_UINT)347, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((((Operator*)testToken)->info->precedence)), (((void *)0)), (_U_UINT)348, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("16)"), (string), 349, ((void *)0));





 testToken = getToken(string);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)353);;};

 UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)354, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)355, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((")"), (string), 356, ((void *)0));





 testToken = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((testToken->type)), (((void *)0)), (_U_UINT)360, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)(")"), (const char*)(((Operator*)testToken)->info->symbol), (((void *)0)), (_U_UINT)361);

 UnityAssertEqualNumber((_U_SINT)((CLOSING_BRACKET_OP)), (_U_SINT)((((Operator*)testToken)->info->id)), (((void *)0)), (_U_UINT)362, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((((Operator*)testToken)->info->precedence)), (((void *)0)), (_U_UINT)363, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 364, ((void *)0));

}
