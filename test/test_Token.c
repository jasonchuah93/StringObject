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

