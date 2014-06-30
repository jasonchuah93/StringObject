#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "CharSet.h"


void setUp(void) {}

void tearDown(void) {}



void test_getToken_should_get_number_token_from_string(void){



 Text *testTokenizer = textNew("234");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)15);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_234_from_text_with_space(void){



 Text *testTokenizer = textNew("234 567");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)25);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_234_from_text_with_space_and_alphabet(void){



 Text *testTokenizer = textNew("234 jason");

 String *strTokenizer = stringNew(testTokenizer);

 Token *testToken = getToken(strTokenizer);

 if ((((testToken)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)35);;};

 UnityAssertEqualNumber((_U_SINT)((234)), (_U_SINT)((((Number*)testToken)->value)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)(((Number*)testToken->type)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_operator_token_from_string(void){



 Text *text = textNew("+");

 String *strToken = stringNew(text);

 Token *opeToken;

 opeToken = getToken(strToken);



 printf("%s\n",((Operator *)opeToken)->info->symbol);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((opeToken->type)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator*)opeToken)->info->symbol), (((void *)0)), (_U_UINT)50);

}
