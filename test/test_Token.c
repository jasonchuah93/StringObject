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
	
	TEST_ASSERT_NOT_NULL(number1);
	TEST_ASSERT_EQUAL(5,number1->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,number1->type);
}

void test_numberNew_should_get_more_than_single_digit_value_and_type(void) {
 
	Number *number1;
	number1=numberNew(5000);
	
	TEST_ASSERT_NOT_NULL(number1);
	TEST_ASSERT_EQUAL(5000,number1->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,number1->type);
}

void test_numberNew_should_get_negative_value_and_type(void) {
 
	Number *number1;
	number1=numberNew(-5);
	
	TEST_ASSERT_NOT_NULL(number1);
	TEST_ASSERT_EQUAL(-5,number1->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,number1->type);
}

void test_identifierNew_should_identifier_the_content(void){
	Text *text1 = textNew("Jason");
	Identifier *identifier1;
	identifier1=identifierNew(text1);
	
	TEST_ASSERT_EQUAL(text1,identifier1->name);
	TEST_ASSERT_NOT_NULL(identifier1);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier1->type);
	TEST_ASSERT_EQUAL(NULL,identifier1->number->value);

}

void test_identifierNew_should_identifier_the_content_two(void){
	Text *text1 = textNew("Chuah");
	Identifier *identifier1;
	identifier1=identifierNew(text1);
	
	TEST_ASSERT_EQUAL(text1,identifier1->name);
	TEST_ASSERT_NOT_NULL(identifier1);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier1->type);
	TEST_ASSERT_EQUAL(NULL,identifier1->number->value);

}

void test_identifierNew_should_identifier_the_content_three(void){
	Text *text1 = textNew("apple123");
	Identifier *identifier1;
	identifier1=identifierNew(text1);
	
	TEST_ASSERT_EQUAL(text1,identifier1->name);
	TEST_ASSERT_NOT_NULL(identifier1);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier1->type);
	TEST_ASSERT_EQUAL(NULL,identifier1->number->value);

}

void xtest_operatorNewBySymbol_should_identify_the_symbol(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("+");
	
	symbol1=strcmp("+",operator1->info->symbol);
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL(1,symbol1);
}

void xtest_operatorNewBySymbol_should_identify_the_different_symbol(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("-");
	
	symbol1=strcmp("-",operator1->info->symbol);
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL(1,symbol1);
}

void xtest_operatorNewBySymbol_should_identify_the_different_symbol2(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("*");
	
	symbol1=strcmp("*",operator1->info->symbol);
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL(1,symbol1);
}

void xtest_operatorNewBySymbol_should_identify_the_different_symbol3(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("/");
	
	symbol1=strcmp("/",operator1->info->symbol);
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL(1,symbol1);
}

void xtest_operatorNewBySymbol_should_identify_the_different_symbol4(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("~");
	
	symbol1=strcmp("~",operator1->info->symbol);
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL(1,symbol1);
}

void test_operatorNewByID_should_identify_the_different_symbol(void){
	
	Operator *operator1 =operatorNewByID(ADD_OP);
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(ADD_OP,operator1->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	
}

void test_operatorNewByID_should_identify_the_different_symbol2(void){
	
	Operator *operator1 =operatorNewByID(BITWISE_AND_OP);
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(BITWISE_AND_OP,operator1->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	
}

void test_operatorNewByID_should_identify_the_different_symbol3(void){
	
	Operator *operator1 =operatorNewByID(MUL_OP);
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(MUL_OP,operator1->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
}

void test_getToken_should_get_number_token_from_string(void){
	
	Text *testTokenizer = textNew("234");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
}

void test_getToken_should_get_more_number_token_from_string(void){
	
	Text *testTokenizer = textNew("234567");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234567,((Number*)testToken)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,(Number*)testToken->type);
}

void test_getToken_should_get_more_number_token_from_string_got_space(void){
	
	Text *testTokenizer = textNew("234 567");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(234,((Number*)testToken)->value);
	printf("%d\n",((Number*)testToken)->value);
	
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

void test_getToken_should_get_operator_token_from_string2(void){
	
	Text *text = textNew("&&");
	String *strToken = stringNew(text);
	Token *opeToken;
	opeToken = getToken(strToken);
	
	printf("%s\n",((Operator *)opeToken)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,opeToken->type);
	TEST_ASSERT_EQUAL_STRING("&&",((Operator*)opeToken)->info->symbol);
	
}

void xtest_getToken_should_get_operator_token_from_string3(void){
	int symbol1;
	
	Text *testTokenizer = textNew("||");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,(Operator*)testToken->type);
	
}

void test_getToken_should_get_identifier_token_from_string(void){
	Text *testTokenizer = textNew("Jason");
	String *strTokenizer = stringNew(testTokenizer);
	Token *testToken = getToken(strTokenizer);
	
	TEST_ASSERT_NOT_NULL(testToken);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,(Identifier*)testToken->type);
}

