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
	
	TEST_ASSERT_EQUAL(5,number1->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,number1->type);
}

void test_numberNew_should_get_more_than_single_digit_value_and_type(void) {
 
	Number *number1;
	number1=numberNew(5000);
	
	TEST_ASSERT_EQUAL(5000,number1->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,number1->type);
}

void test_numberNew_should_get_negative_value_and_type(void) {
 
	Number *number1;
	number1=numberNew(-5);
	
	TEST_ASSERT_EQUAL(-5,number1->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,number1->type);
}

void test_identifierNew_should_identifier_the_content(void){
	Text *text1 = textNew("Jason");
	Identifier *identifier1;
	identifier1=identifierNew(text1);
	
	TEST_ASSERT_EQUAL(text1,identifier1->name);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier1->type);
	TEST_ASSERT_EQUAL(NULL,identifier1->number->value);

}

void xtest_identifierNew_should_identifier_the_content_two(void){
	Text *text1 = textNew("Chuah");
	Identifier *identifier1;
	identifier1=identifierNew(text1);
	
	TEST_ASSERT_EQUAL(text1,identifier1->name);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier1->type);
	TEST_ASSERT_EQUAL(NULL,identifier1->number->value);

}


void test_operatorNewBySymbol_should_identify_the_symbol(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("+");
	
	symbol1=strcmp("+",operator1->info->symbol);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL(1,symbol1);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("-");
	
	symbol1=strcmp("-",operator1->info->symbol);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL(1,symbol1);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol2(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("*");
	
	symbol1=strcmp("*",operator1->info->symbol);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL(1,symbol1);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol3(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("/");
	
	symbol1=strcmp("/",operator1->info->symbol);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL(1,symbol1);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol4(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("~");
	
	symbol1=strcmp("~",operator1->info->symbol);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL(1,symbol1);
}
