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



void test_identifierNew_should_identifier_the_content(void){

 Text *text1 = textNew("Jason");

 Identifier *identifier1;

 identifier1=identifierNew(text1);



 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number->value)), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);



}



void xtest_identifierNew_should_identifier_the_content_two(void){

 Text *text1 = textNew("Chuah");

 Identifier *identifier1;

 identifier1=identifierNew(text1);



 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number->value)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);



}





void test_operatorNewBySymbol_should_identify_the_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("+");



 symbol1=strcmp("+",operator1->info->symbol);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((symbol1)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("-");



 symbol1=strcmp("-",operator1->info->symbol);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((symbol1)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol2(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("*");



 symbol1=strcmp("*",operator1->info->symbol);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((symbol1)), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol3(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("/");



 symbol1=strcmp("/",operator1->info->symbol);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((symbol1)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol4(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("~");



 symbol1=strcmp("~",operator1->info->symbol);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((symbol1)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

}
