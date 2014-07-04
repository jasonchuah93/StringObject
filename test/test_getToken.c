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

void xtest_getToken_should_get_number_token_from_string_with_space_infront_and_left_empty_space(void){
	
	Text *testTokenizer = textNew("                   234");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
	
}

void test_getToken_should_get_234_from_string_with_space_in_between_and_left_space567(void){
	
	Text *testTokenizer = textNew("234 567");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken;
	
	testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
	TEST_ASSERT_EQUAL_String(" 567",strTokenizer);
	
	stringDump(strTokenizer);
}

void test_getToken_should_get_234_from_string_contain_alphabets_with_space_in_between_and_left_spacejason(void){
	
	Text *testTokenizer = textNew("  234 jason");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,testToken->type);
	
}

void test_getToken_should_throw_error_when_characters_is_behind(void){
	int e;
	Text *testTokenizer = textNew("234jason");
	String *strTokenizer = stringNew(testTokenizer);
	Try{
		Token *testToken = getToken(strTokenizer);
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED,e);
		return;
	}
}

void test_getToken_should_throw_error_from_string_combine_with_alphabets_and_operators(void){
	int e;
	Text *testTokenizer = textNew("2!3+4-jason");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(2,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
	TEST_ASSERT_EQUAL_String("!3+4-jason",strTokenizer);
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
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("+",((Operator*)opeToken)->info->symbol);
	TEST_ASSERT_EQUAL(ADD_OP,((Operator*)opeToken)->info->id);
	TEST_ASSERT_EQUAL(80,((Operator*)opeToken)->info->precedence);
	TEST_ASSERT_EQUAL_String("",strToken);
}

void test_getToken_should_get_operator_token_with_space_at_front_and_return_ADD_OP_and_left_empty_space(void){
	
	Text *text = textNew("                   +");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("+",((Operator*)opeToken)->info->symbol);
	TEST_ASSERT_EQUAL(ADD_OP,((Operator*)opeToken)->info->id);
	TEST_ASSERT_EQUAL(80,((Operator*)opeToken)->info->precedence);
	
}

void test_getToken_should_get_operator_token_and_number_token(void){
	
	Text *text = textNew("1+2");
	String *strToken = stringNew(text);
	Token *testToken;
	//1
	testToken = getToken(strToken);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(1,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
	TEST_ASSERT_EQUAL_String("+2",strToken);
	//+
	testToken = getToken(strToken);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,testToken->type);
	TEST_ASSERT_EQUAL_STRING("+",((Operator*)testToken)->info->symbol);
	TEST_ASSERT_EQUAL(ADD_OP,((Operator*)testToken)->info->id);
	TEST_ASSERT_EQUAL(80,((Operator*)testToken)->info->precedence);
	TEST_ASSERT_EQUAL_String("2",strToken);
	//2
	testToken = getToken(strToken);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(2,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
	TEST_ASSERT_EQUAL_String("",strToken);
}

void test_getToken_should_get_operator_token_number_token_and_identieifer_token(void){
	
	Text *text = textNew("1+jason");
	String *strToken = stringNew(text);
	Token *testToken;
	//1
	testToken = getToken(strToken);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(1,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
	TEST_ASSERT_EQUAL_String("+jason",strToken);
	//+
	testToken = getToken(strToken);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,testToken->type);
	TEST_ASSERT_EQUAL_STRING("+",((Operator*)testToken)->info->symbol);
	TEST_ASSERT_EQUAL(ADD_OP,((Operator*)testToken)->info->id);
	TEST_ASSERT_EQUAL(80,((Operator*)testToken)->info->precedence);
	TEST_ASSERT_EQUAL_String("jason",strToken);
	
	//jason
	testToken= getToken(strToken);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,((Identifier*)testToken)->type);
	TEST_ASSERT_EQUAL_STRING("jason",((Identifier*)testToken)->name->string);
	TEST_ASSERT_EQUAL_String("",strToken);
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

void test_getToken_should_get_operators_token_with_space_at_front_and_return_LOGICAL_AND_OP_and_left_empty_space_and_characters_and_numbers(void){
	
	Text *text = textNew("               && orange  777");
	String *strToken = stringNew(text);
	Token *opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("&&",((Operator*)opeToken)->info->symbol);
	TEST_ASSERT_EQUAL(LOGICAL_AND_OP,((Operator*)opeToken)->info->id);
	TEST_ASSERT_EQUAL(30,((Operator*)opeToken)->info->precedence);
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
	Text *text = textNew("               +&");
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
	
	TEST_ASSERT_NOT_NULL(opeToken);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("/",((Operator*)opeToken)->info->symbol);
	TEST_ASSERT_EQUAL(DIV_OP,((Operator*)opeToken)->info->id);
	TEST_ASSERT_EQUAL(100,((Operator*)opeToken)->info->precedence);
	TEST_ASSERT_EQUAL_String(" ^",strToken);
	
}

void test_getToken_should_get_identifier_token_from_string(void){
	Text *testTokenizer = textNew("Jason 016");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	
	stringDump(strTokenizer);
	
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,((Identifier*)testToken)->type);
	TEST_ASSERT_EQUAL_STRING("Jason",((Identifier*)testToken)->name->string);
	TEST_ASSERT_EQUAL_String(" 016",strTokenizer);
}

void test_tokenDel_should_delete_Number_token_and_return_empty_string(void){
	Text *text1 = textNew("123");
	String *string1 = stringNew(text1);
	Token *testToken;
	testToken = getToken(string1);
	
	tokenDel(testToken);
	stringDump(string1);
	
	TEST_ASSERT_EQUAL(NULL,((Number*)testToken)->type);
}

void test_tokenDel_should_delete_Identifier_token_and_return_empty_string(void){
	Text *text1 = textNew("Jason");
	String *string1 = stringNew(text1);
	Token *testToken;
	testToken = getToken(string1);
	
	tokenDel(testToken);
	stringDump(string1);
	
	TEST_ASSERT_EQUAL(NULL,((Identifier*)testToken)->type);
}

void test_tokenDel_should_delete_Operator_token_and_return_empty_string(void){
	Text *text1 = textNew("&&");
	String *string1 = stringNew(text1);
	Token *testToken;
	testToken = getToken(string1);
	
	tokenDel(testToken);
	stringDump(string1);
	
	TEST_ASSERT_EQUAL(NULL,((Operator*)testToken)->type);
}

void test_tokenDel_should_delete_All_token_and_return_empty_string(void){
	Text *text1 = textNew("123 Jason &&");
	String *string1 = stringNew(text1);
	Token *testToken;
	testToken = getToken(string1);
	
	tokenDel(testToken);
	stringDump(string1);
	
	TEST_ASSERT_EQUAL(NULL,((Number*)testToken)->type);
	TEST_ASSERT_EQUAL(NULL,((Identifier*)testToken)->type);
	TEST_ASSERT_EQUAL(NULL,((Operator*)testToken)->type);
}
