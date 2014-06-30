#include "unity.h"
#include "Text.h"
#include "StringObject.h"
#include "Token.h"
#include "CharSet.h"

void setUp(void) {}
void tearDown(void) {}

void test_getToken_should_get_number_token_from_string(void){
	
	Text *testTokenizer = textNew("234");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
}

void test_getToken_should_get_234_from_text_with_space(void){
	
	Text *testTokenizer = textNew("234 567");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
}

void test_getToken_should_get_234_from_text_with_space_and_alphabet(void){
	
	Text *testTokenizer = textNew("234 jason");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
}

void test_getToken_should_get_operator_token_from_string(void){
	
	Text *text = textNew("+");
	String *strToken = stringNew(text);
	Token *opeToken;
	opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("+",((Operator*)opeToken)->info->symbol);
}


