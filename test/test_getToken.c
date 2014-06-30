#include "unity.h"
#include "Text.h"
#include "StringObject.h"
#include "Token.h"
#include "CharSet.h"
#include "CException.h"
#include "ErrorCode.h"

void setUp(void){}
void tearDown(void){}

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

void test_getToken_should_get_234_from_text_with_space_and_alphabets(void){
	
	Text *testTokenizer = textNew("234 jason");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
}

void test_getToken_should_get_234_from_text_with_alphabets(void){
	
	Text *testTokenizer = textNew("234jason");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
}

void test_getToken_should_get_2_from_text_with_alphabets_and_operators(void){
	int e;
	Text *testTokenizer = textNew("2!3+4-jason");
	String *strTokenizer = stringNew(testTokenizer);
	Try{
		Token *testToken = getToken(strTokenizer);
	}Catch(e)
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED,e);
		return;
}

void test_getToken_should_throw_an_error_for_this_expression(void){
	int e;
	Text *testTokenizer = textNew("jason234");
	String *strTokenizer = stringNew(testTokenizer);
	Try{
		Token *testToken = getToken(strTokenizer);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED,e);
		return;
	}
	
}

void test_getToken_should_get_operator_token_and_return_ADD_OP(void){
	
	Text *text = textNew("+");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("+",((Operator*)opeToken)->info->symbol);
}

void test_getToken_should_get_operator_token_and_return_MUL_OP(void){
	
	Text *text = textNew("*");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("*",((Operator*)opeToken)->info->symbol);
}

void test_getToken_should_get_double_operators_token_and_return_LOGICAL_AND_OP(void){
	
	Text *text = textNew("&&");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("&&",((Operator*)opeToken)->info->symbol);
	
}

void test_getToken_should_get_double_operators_token_and_return_LOGICAL_OR_OP(void){
	
	Text *text = textNew("||");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("||",((Operator*)opeToken)->info->symbol);
	
}

void test_getToken_should_get_two_different_operators_token_and_throw_an_error(void){
	int e;
	Text *text = textNew("|%");
	String *strToken = stringNew(text);
	
	Try{
		Token *opeToken = getToken(strToken);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED,e);
		return;
	}
}

void test_getToken_should_get_two_different_operators_token_and_throw_an_error2(void){
	int e;
	Text *text = textNew("+&");
	String *strToken = stringNew(text);
	
	Try{
		Token *opeToken = getToken(strToken);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED,e);
		return;
	}
}

void test_getToken_should_get_space_between_two_different_operators_token_and_throw_an_error(void){
	int e;
	Text *text = textNew("/ ^");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("/",((Operator*)opeToken)->info->symbol);
}
