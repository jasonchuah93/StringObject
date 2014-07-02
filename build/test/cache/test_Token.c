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



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)20);;};

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_more_than_single_digit_value_and_type(void) {



 Number *number1;

 number1=numberNew(5000);



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)30);;};

 UnityAssertEqualNumber((_U_SINT)((5000)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_negative_value_and_type(void) {



 Number *number1;

 number1=numberNew(-5);



 if ((((number1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)40);;};

 UnityAssertEqualNumber((_U_SINT)((-5)), (_U_SINT)((number1->value)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number1->type)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

}



void test_identifierNew_should_identifier_the_content(void){

 Text *text1 = textNew("Jason");

 Identifier *identifier1 = identifierNew(text1);



 if ((((identifier1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)49);;};

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_INT);



}



void test_identifierNew_should_identifier_the_content2(void){

 Text *text1 = textNew("Chuah");

 Identifier *identifier1 = identifierNew(text1);



 if ((((identifier1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)60);;};

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);



}



void test_identifierNew_should_identifier_the_content_three(void){



 Text *text1 = textNew("apple123");

 Identifier *identifier1 = identifierNew(text1);



 if ((((identifier1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)72);;};

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((identifier1->name)), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier1->type)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier1->number)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewBySymbol_should_identify_the_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("+");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)84);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)86);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((operator1->info->precedence)), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("-");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)96);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("-"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)98);

 UnityAssertEqualNumber((_U_SINT)((SUB_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((operator1->info->precedence)), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol2(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("*");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)108);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("*"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)110);

 UnityAssertEqualNumber((_U_SINT)((MUL_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((operator1->info->precedence)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol3(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("/");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)120);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("/"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)122);

 UnityAssertEqualNumber((_U_SINT)((DIV_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((operator1->info->precedence)), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should__retur_NULL_if_input_invalid_symbol(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("@");



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator1)), (((void *)0)), (_U_UINT)132, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol4(void){

 int symbol1;



 Operator *operator1 = operatorNewBySymbol("~");



 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)140);;};

 UnityAssertEqualString((const char*)("~"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)141);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)142, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)143, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((operator1->info->precedence)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewByID_should_identify_the_different_symbol(void){



 Operator *operator1 =operatorNewByID(ADD_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)151);;};

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)153, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)154);



}



void test_operatorNewByID_should_identify_the_different_symbol2(void){



 Operator *operator1 =operatorNewByID(BITWISE_AND_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)161);;};

 UnityAssertEqualNumber((_U_SINT)((BITWISE_AND_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)164);



}



void test_operatorNewByID_should_identify_the_different_symbol3(void){



 Operator *operator1 =operatorNewByID(MUL_OP);

 if ((((operator1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)171);;};

 UnityAssertEqualNumber((_U_SINT)((MUL_OP)), (_U_SINT)((operator1->info->id)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator1->type)), (((void *)0)), (_U_UINT)173, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("*"), (const char*)(operator1->info->symbol), (((void *)0)), (_U_UINT)174);

}



void test_operatorNewByID_should_return_NULL_if_input_the_incorrect_symbol(void){



 Operator *operator1 =operatorNewByID(111);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator1)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);



}
