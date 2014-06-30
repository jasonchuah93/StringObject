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



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)15);;};

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_more_than_single_digit_value_and_type(void) {



 Number *number1;

 number1=numberNew(5000);



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)25);;};

 UnityAssertEqualNumber((_U_SINT)((5000)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_negative_value_and_type(void) {



 Number *number1;

 number1=numberNew(-5);



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)35);;};

 UnityAssertEqualNumber((_U_SINT)((-5)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

}



void test_identifierNew_should_identifier_the_content(void){

 Text *text1 = textNew("Jason");

 Identifier *identifier1 = identifierNew(text1);



 if ((((identifier1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)44);;};

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number)), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);



}



void test_identifierNew_should_identifier_the_content2(void){

 Text *text1 = textNew("Chuah");

 Identifier *identifier1 = identifierNew(text1);



 if ((((identifier1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)55);;};

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number)), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);



}



void test_identifierNew_should_identifier_the_content_three(void){



 Text *text1 = textNew("apple123");

 Identifier *identifier1 = identifierNew(text1);



 if ((((identifier1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)67);;};

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewBySymbol_should_identify_the_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("+");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)79);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)81);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("-");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)89);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("-"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)91);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol2(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("*");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)99);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("*"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)101);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol3(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("/");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)109);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("/"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)111);

}



void test_operatorNewBySymbol_should__retur_NULL_if_input_invalid_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("@");



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator1)), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);





}



void test_operatorNewBySymbol_should_identify_the_different_symbol4(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("~");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)129);;};

 UnityAssertEqualString((const char*)("~"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)130);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewByID_should_identify_the_different_symbol(void){



 Operator *operator1 =operatorNewByID(ADD_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)138);;};

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)139, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewByID_should_identify_the_different_symbol2(void){



 Operator *operator1 =operatorNewByID(BITWISE_AND_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)147);;};

 UnityAssertEqualNumber((_U_SINT)((BITWISE_AND_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewByID_should_identify_the_different_symbol3(void){



 Operator *operator1 =operatorNewByID(MUL_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)156);;};

 UnityAssertEqualNumber((_U_SINT)((MUL_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewByID_should_return_NULL_if_input_the_incorrect_symbol(void){



 Operator *operator1 =operatorNewByID(111);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator1)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);



}
