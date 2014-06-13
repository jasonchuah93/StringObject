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



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_more_than_single_digit_value_and_type(void) {



 Number *number1;

 number1=numberNew(5000);



 UnityAssertEqualNumber((_U_SINT)((5000)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_negative_value_and_type(void) {



 Number *number1;

 number1=numberNew(-5);



 UnityAssertEqualNumber((_U_SINT)((-5)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

}
