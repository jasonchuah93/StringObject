#include "unity.h"
#include "Text.h"
#include "StringObject.h"
#include "Token.h"
#include "CharSet.h"
#include "CException.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"

void setUp(void){}
void tearDown(void){}

void test_getToken_should_get_number_token_from_string_and_left_empty_space(void){
	
	Text *testTokenizer = textNew("234");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
	TEST_ASSERT_EQUAL_String("",strTokenizer);
}

void test_getToken_should_get_234_from_string_with_space_in_between_and_left_space567(void){
	
	Text *testTokenizer = textNew("234 567");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
	TEST_ASSERT_EQUAL_String(" 567",strTokenizer);
	
}

void test_getToken_should_get_234_from_string_contain_alphabets_with_space_in_between_and_left_spacejason(void){
	
	Text *testTokenizer = textNew("234 jason");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
	TEST_ASSERT_EQUAL_String(" jason",strTokenizer);
}

void test_getToken_should_get_234_from_string_with_alphabets_and_left_jason(void){
	
	Text *testTokenizer = textNew("234jason");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
	TEST_ASSERT_EQUAL_String("jason",strTokenizer);
}

void test_getToken_should_throw_error_from_string_combine_with_alphabets_and_operators(void){
	int e;
	Text *testTokenizer = textNew("2!3+4-jason");
	String *strTokenizer = stringNew(testTokenizer);
	Try{
		Token *testToken = getToken(strTokenizer);
	}Catch(e)
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED,e);
		return;
}

void test_getToken_should_throw_an_error_for_string_start_with_alphabet_first(void){
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

void test_getToken_should_get_operator_token_and_return_ADD_OP_and_left_empty_space(void){
	
	Text *text = textNew("+");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("+",((Operator*)opeToken)->info->symbol);
	TEST_ASSERT_EQUAL(ADD_OP,((Operator*)opeToken)->info->id);
	TEST_ASSERT_EQUAL(80,((Operator*)opeToken)->info->precedence);
	TEST_ASSERT_EQUAL_String("",strToken);
}

void test_getToken_should_get_operator_token_and_return_MUL_OP_and_left_empty_space_and_characters_and_numbers(void){
	
	Text *text = textNew("* apple 111");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("*",((Operator*)opeToken)->info->symbol);
	TEST_ASSERT_EQUAL(MUL_OP,((Operator*)opeToken)->info->id);
	TEST_ASSERT_EQUAL(100,((Operator*)opeToken)->info->precedence);
	TEST_ASSERT_EQUAL_String(" apple 111",strToken);
}

void test_getToken_should_throw_error_for_string_operator_and_characters(void){
	int e;
	Text *text = textNew("*apple");
	String *strToken = stringNew(text);
	Try{
		Token *opeToken = getToken(strToken);
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED,e);
		return;
	}
}	

void test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space(void){
	
	Text *text = textNew("&&");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("&&",((Operator*)opeToken)->info->symbol);
	TEST_ASSERT_EQUAL(LOGICAL_AND_OP,((Operator*)opeToken)->info->id);
	TEST_ASSERT_EQUAL(30,((Operator*)opeToken)->info->precedence);
	TEST_ASSERT_EQUAL_String("",strToken);
	
}
	
void test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space_and_characters_and_numbers(void){
	
	Text *text = textNew("&& orange  777");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("&&",((Operator*)opeToken)->info->symbol);
	TEST_ASSERT_EQUAL(LOGICAL_AND_OP,((Operator*)opeToken)->info->id);
	TEST_ASSERT_EQUAL(30,((Operator*)opeToken)->info->precedence);
	TEST_ASSERT_EQUAL_String(" orange  777",strToken);
	
}

void test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space(void){
	
	Text *text = textNew("||");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("||",((Operator*)opeToken)->info->symbol);
	TEST_ASSERT_EQUAL(LOGICAL_OR_OP,((Operator*)opeToken)->info->id);
	TEST_ASSERT_EQUAL(20,((Operator*)opeToken)->info->precedence);
	TEST_ASSERT_EQUAL_String("",strToken);
	
}

void test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space_and_characters(void){
	
	Text *text = textNew("|| orange guava");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("||",((Operator*)opeToken)->info->symbol);
	TEST_ASSERT_EQUAL(LOGICAL_OR_OP,((Operator*)opeToken)->info->id);
	TEST_ASSERT_EQUAL(20,((Operator*)opeToken)->info->precedence);
	TEST_ASSERT_EQUAL_String(" orange guava",strToken);
	
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
	TEST_ASSERT_EQUAL(DIV_OP,((Operator*)opeToken)->info->id);
	TEST_ASSERT_EQUAL(100,((Operator*)opeToken)->info->precedence);
	TEST_ASSERT_EQUAL_String(" ^",strToken);
	
}

void test_getToken_should_get_identifier_token_from_string(void){
	Text *testTokenizer = textNew(" Jason");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,(Identifier*)testToken->type);
	TEST_ASSERT_EQUAL_STRING("Jason",((Identifier*)testToken)->name->string);
	TEST_ASSERT_EQUAL_String("",strTokenizer);
}

void xtest_getToken_should_get_identifier_token_and_return_Jason_and_left_016_in_string(void){
	Text *testTokenizer = textNew("Jason 016");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	
	printf("%s\n",((Identifier*)testToken)->name->string);
	
	//TEST_ASSERT_NOT_NULL(testToken);
	//TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,(Identifier*)testToken->type);
	//TEST_ASSERT_EQUAL_STRING("Jason",((Identifier*)testToken)->name->string);
	//TEST_ASSERT_EQUAL_String(" Chuah",strTokenizer);
}



