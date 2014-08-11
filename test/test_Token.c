#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "CharSet.h"
#include "CException.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"

void setUp(void){}

void tearDown(void){}

void test_numberNew_should_get_single_digit_value_and_type(void) {
 
	Number *number=numberNew(5);
	
	TEST_ASSERT_NOT_NULL(number);
	TEST_ASSERT_EQUAL(5,number->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,number->type);
}

void test_numberNew_should_get_more_than_single_digit_value_and_type(void) {
 
	Number *number=numberNew(5000);
	
	TEST_ASSERT_NOT_NULL(number);
	TEST_ASSERT_EQUAL(5000,number->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,number->type);
}

void test_numberNew_should_get_negative_value_and_type(void) {
 
	Number *number=numberNew(-5);
	
	TEST_ASSERT_NOT_NULL(number);
	TEST_ASSERT_EQUAL(-5,number->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,number->type);
}

void test_identifierNew_should_identifier_the_content(void){
	Text *text = textNew("Jason");
	Identifier *identifier = identifierNew(text);
	
	TEST_ASSERT_NOT_NULL(identifier);
	TEST_ASSERT_EQUAL(text,identifier->name);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier->type);
	TEST_ASSERT_EQUAL(NULL,identifier->number);

}

void test_identifierNew_should_identifier_the_content2(void){
	Text *text = textNew("Chuah");
	Identifier *identifier = identifierNew(text);
	
	TEST_ASSERT_NOT_NULL(identifier);
	TEST_ASSERT_EQUAL(text,identifier->name);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier->type);
	TEST_ASSERT_EQUAL(NULL,identifier->number);

}

void test_identifierNew_should_identifier_the_content_three(void){
	
	Text *text = textNew("apple123");
	Identifier *identifier = identifierNew(text);

	TEST_ASSERT_NOT_NULL(identifier);
	TEST_ASSERT_EQUAL(text,identifier->name);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier->type);
	TEST_ASSERT_EQUAL(NULL,identifier->number);
	
}

void test_operatorNewBySymbol_should_identify_the_symbol(void){
	
	
	Operator *operator = operatorNewBySymbol("+");
	
	TEST_ASSERT_NOT_NULL(operator);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL_STRING("+",operator->info->symbol);
	TEST_ASSERT_EQUAL(ADD_OP,operator->info->id);
	TEST_ASSERT_EQUAL(80,operator->info->precedence);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol(void){
	
	
	Operator *operator = operatorNewBySymbol("-");
	
	TEST_ASSERT_NOT_NULL(operator);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL_STRING("-",operator->info->symbol);
	TEST_ASSERT_EQUAL(SUB_OP,operator->info->id);
	TEST_ASSERT_EQUAL(80,operator->info->precedence);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol2(void){
	
	Operator *operator = operatorNewBySymbol("*");
	
	TEST_ASSERT_NOT_NULL(operator);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL_STRING("*",operator->info->symbol);
	TEST_ASSERT_EQUAL(MUL_OP,operator->info->id);
	TEST_ASSERT_EQUAL(100,operator->info->precedence);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol3(void){
	
	Operator *operator = operatorNewBySymbol("/");
	
	TEST_ASSERT_NOT_NULL(operator);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL_STRING("/",operator->info->symbol);
	TEST_ASSERT_EQUAL(DIV_OP,operator->info->id);
	TEST_ASSERT_EQUAL(100,operator->info->precedence);
}

void test_operatorNewBySymbol_should__retur_NULL_if_input_invalid_symbol(void){
	
	Operator *operator = operatorNewBySymbol("@");
	
	TEST_ASSERT_EQUAL(NULL,operator);
}

void test_operatorNewBySymbol_should_identify_the_different_symbol4(void){
	
	Operator *operator = operatorNewBySymbol("~");
	
	TEST_ASSERT_NOT_NULL(operator);
	TEST_ASSERT_EQUAL_STRING("~",operator->info->symbol);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL(BITWISE_NOT_OP,operator->info->id);
	TEST_ASSERT_EQUAL(150,operator->info->precedence);
	
}

void test_operatorNewByID_should_identify_the_different_symbol(void){
	
	Operator *operator =operatorNewByID(ADD_OP);
	TEST_ASSERT_NOT_NULL(operator);
	TEST_ASSERT_EQUAL(ADD_OP,operator->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL_STRING("+",operator->info->symbol);
	
}

void test_operatorNewByID_should_identify_the_different_symbol_two(void){
	
	Operator *operator =operatorNewByID(BITWISE_AND_OP);
	TEST_ASSERT_NOT_NULL(operator);
	TEST_ASSERT_EQUAL(BITWISE_AND_OP,operator->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL_STRING("&",operator->info->symbol);
}

void test_operatorNewByID_should_identify_the_different_symbol_three(void){
	
	Operator *operator =operatorNewByID(MUL_OP);
	TEST_ASSERT_NOT_NULL(operator);
	TEST_ASSERT_EQUAL(MUL_OP,operator->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL_STRING("*",operator->info->symbol);
}

void test_operatorNewByID_should_return_NULL_if_input_the_incorrect_symbol(void){
	
	Operator *operator =operatorNewByID(111);
	
	TEST_ASSERT_EQUAL(NULL,operator);
	
}




