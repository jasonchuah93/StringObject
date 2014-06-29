#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "CharSet.h"








void setUp(void) {}



void tearDown(void) {}



void test_numberNew_should_get_single_digit_value_and_type(void) {



 Number *number1;

 number1=numberNew(5);



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)19);;};

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_more_than_single_digit_value_and_type(void) {



 Number *number1;

 number1=numberNew(5000);



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)29);;};

 UnityAssertEqualNumber((_U_SINT)((5000)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_negative_value_and_type(void) {



 Number *number1;

 number1=numberNew(-5);



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)39);;};

 UnityAssertEqualNumber((_U_SINT)((-5)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

}



void test_identifierNew_should_identifier_the_content(void){

 Text *text1 = textNew("Jason");

 Identifier *identifier1 = identifierNew(text1);



 if ((((identifier1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)48);;};

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);



}



void xtest_identifierNew_should_identifier_the_content2(void){

 Text *text = textNew("Chuah");

 Identifier *identifier1 = identifierNew(text);













}



void xtest_identifierNew_should_identifier_the_content_three(void){



 Text *textA = textNew("apple123");

 Identifier *identifierA = identifierNew(textA);



 if ((((identifierA)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)71);;};

 UnityAssertEqualNumber((_U_SINT)((textA)), (_U_SINT)((identifierA->name)), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifierA->type)), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifierA->number)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewBySymbol_should_identify_the_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("+");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)83);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)85);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("-");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)93);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("-"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)95);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol2(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("*");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)103);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("*"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)105);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol3(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("/");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)113);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("/"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)115);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol4(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("~");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)123);;};

 UnityAssertEqualString((const char*)("~"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)124);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewByID_should_identify_the_different_symbol(void){



 Operator *operator1 =operatorNewByID(ADD_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)132);;};

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)133, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)134, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewByID_should_identify_the_different_symbol2(void){



 Operator *operator1 =operatorNewByID(BITWISE_AND_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)141);;};

 UnityAssertEqualNumber((_U_SINT)((BITWISE_AND_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)142, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)143, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewByID_should_identify_the_different_symbol3(void){



 Operator *operator1 =operatorNewByID(MUL_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)150);;};

 UnityAssertEqualNumber((_U_SINT)((MUL_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_number_token_from_string(void){



 Text *testTokenizer = textNew("234");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)160);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)161, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_more_number_token_from_string(void){



 Text *testTokenizer = textNew("234567");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)170);;};

 UnityAssertEqualNumber((_U_SINT)((234567)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_more_number_token_from_string_got_space(void){



 Text *testTokenizer = textNew("234 567");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)180);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

 printf("%d\n",((Number*)testToken)->value);



 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)184, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_operator_token_from_string(void){



 Text *text = textNew("+");

 String *strToken = stringNew(text);

 Token *opeToken;

 opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)196, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)197);

}



void xtest_getToken_should_get_operator_token_from_string2(void){



 Text *text = textNew("&&");

 String *strToken = stringNew(text);

 Token *opeToken;

 opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)210);



}



void xtest_getToken_should_get_operator_token_from_string3(void){

 int symbol1;



 Text *testTokenizer = textNew("||");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);



 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)221);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)(((Operator*)testToken->type)), (((void *)0)), (_U_UINT)222, UNITY_DISPLAY_STYLE_INT);



}



void xtest_getToken_should_get_identifier_token_from_string(void){

 Text *testTokenizer = textNew("Jason");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);



 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)231);;};

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)(((Identifier*)testToken->type)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);

}
