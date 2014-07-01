#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "ErrorCode.h"
#include "CharSet.h"
#include "CException.h"




void setUp(void){}



void tearDown(void){}



void test_numberNew_should_get_single_digit_value_and_type(void) {



 Number *number1;

 number1=numberNew(5);



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)19);;};

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_more_than_single_digit_value_and_type(void) {



 Number *number1;

 number1=numberNew(5000);



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)29);;};

 UnityAssertEqualNumber((_U_SINT)((5000)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_negative_value_and_type(void) {



 Number *number1;

 number1=numberNew(-5);



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)39);;};

 UnityAssertEqualNumber((_U_SINT)((-5)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

}



void test_identifierNew_should_identifier_the_content(void){

 Text *text1 = textNew("Jason");

 Identifier *identifier1 = identifierNew(text1);



 if ((((identifier1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)48);;};

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);



}



void test_identifierNew_should_identifier_the_content2(void){

 Text *text1 = textNew("Chuah");

 Identifier *identifier1 = identifierNew(text1);



 if ((((identifier1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)59);;};

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);



}



void test_identifierNew_should_identifier_the_content_three(void){



 Text *text1 = textNew("apple123");

 Identifier *identifier1 = identifierNew(text1);



 if ((((identifier1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)71);;};

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewBySymbol_should_identify_the_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("+");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)83);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)85);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((operator1->info->precedence)), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("-");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)95);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("-"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)97);

 UnityAssertEqualNumber((_U_SINT)((SUB_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((operator1->info->precedence)), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol2(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("*");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)107);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("*"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)109);

 UnityAssertEqualNumber((_U_SINT)((MUL_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((operator1->info->precedence)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol3(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("/");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)119);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("/"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)121);

 UnityAssertEqualNumber((_U_SINT)((DIV_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((operator1->info->precedence)), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should__retur_NULL_if_input_invalid_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("@");



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator1)), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol4(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("~");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)139);;};

 UnityAssertEqualString((const char*)("~"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)140);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)142, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((operator1->info->precedence)), (((void *)0)), (_U_UINT)143, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewByID_should_identify_the_different_symbol(void){



 Operator *operator1 =operatorNewByID(ADD_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)150);;};

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)153);



}



void test_operatorNewByID_should_identify_the_different_symbol2(void){



 Operator *operator1 =operatorNewByID(BITWISE_AND_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)160);;};

 UnityAssertEqualNumber((_U_SINT)((BITWISE_AND_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)161, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)163);



}



void test_operatorNewByID_should_identify_the_different_symbol3(void){



 Operator *operator1 =operatorNewByID(MUL_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)170);;};

 UnityAssertEqualNumber((_U_SINT)((MUL_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("*"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)173);

}



void test_operatorNewByID_should_return_NULL_if_input_the_incorrect_symbol(void){



 Operator *operator1 =operatorNewByID(111);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator1)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);



}
