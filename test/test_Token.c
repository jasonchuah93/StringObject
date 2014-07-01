#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "CharSet.h"
#include "CException.h"
#include "ErrorCode.h"


void setUp(void){}

void tearDown(void){}

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
	Identifier *identifier1 = identifierNew(text1);
	
	TEST_ASSERT_NOT_NULL(identifier1);
	TEST_ASSERT_EQUAL(text1,identifier1->name);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier1->type);
	TEST_ASSERT_EQUAL(NULL,identifier1->number);

}

void test_identifierNew_should_identifier_the_content2(void){
	Text *text1 = textNew("Chuah");
	Identifier *identifier1 = identifierNew(text1);
	
	TEST_ASSERT_NOT_NULL(identifier1);
	TEST_ASSERT_EQUAL(text1,identifier1->name);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier1->type);
	TEST_ASSERT_EQUAL(NULL,identifier1->number);

}

void test_identifierNew_should_identifier_the_content_three(void){
	
	Text *text1 = textNew("apple123");
	Identifier *identifier1 = identifierNew(text1);

	TEST_ASSERT_NOT_NULL(identifier1);
	TEST_ASSERT_EQUAL(text1,identifier1->name);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier1->type);
	TEST_ASSERT_EQUAL(NULL,identifier1->number);
	
}

void test_operatorNewBySymbol_should_identify_the_symbol(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("+");
	
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL_STRING("+",operator1->info->symbol);
	TEST_ASSERT_EQUAL(ADD_OP,operator1->info->id);
	TEST_ASSERT_EQUAL(80,operator1->info->precedence);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("-");
	
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL_STRING("-",operator1->info->symbol);
	TEST_ASSERT_EQUAL(SUB_OP,operator1->info->id);
	TEST_ASSERT_EQUAL(80,operator1->info->precedence);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol2(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("*");
	
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL_STRING("*",operator1->info->symbol);
	TEST_ASSERT_EQUAL(MUL_OP,operator1->info->id);
	TEST_ASSERT_EQUAL(100,operator1->info->precedence);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol3(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("/");
	
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL_STRING("/",operator1->info->symbol);
	TEST_ASSERT_EQUAL(DIV_OP,operator1->info->id);
	TEST_ASSERT_EQUAL(100,operator1->info->precedence);
}

void test_operatorNewBySymbol_should__retur_NULL_if_input_invalid_symbol(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("@");
	
	TEST_ASSERT_EQUAL(NULL,operator1);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol4(void){
	int symbol1;
	
	Operator *operator1 = operatorNewBySymbol("~");
	
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL_STRING("~",operator1->info->symbol);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL(BITWISE_NOT_OP,operator1->info->id);
	TEST_ASSERT_EQUAL(150,operator1->info->precedence);
	
}

void test_operatorNewByID_should_identify_the_different_symbol(void){
	
	Operator *operator1 =operatorNewByID(ADD_OP);
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(ADD_OP,operator1->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL_STRING("+",operator1->info->symbol);
	
}

void test_operatorNewByID_should_identify_the_different_symbol2(void){
	
	Operator *operator1 =operatorNewByID(BITWISE_AND_OP);
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(BITWISE_AND_OP,operator1->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL_STRING("&",operator1->info->symbol);
	
}

void test_operatorNewByID_should_identify_the_different_symbol3(void){
	
	Operator *operator1 =operatorNewByID(MUL_OP);
	TEST_ASSERT_NOT_NULL(operator1);
	TEST_ASSERT_EQUAL(MUL_OP,operator1->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator1->type);
	TEST_ASSERT_EQUAL_STRING("*",operator1->info->symbol);
}

void test_operatorNewByID_should_return_NULL_if_input_the_incorrect_symbol(void){
	
	Operator *operator1 =operatorNewByID(111);
	
	TEST_ASSERT_EQUAL(NULL,operator1);
	
}


