#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"
#include "CharSet.h"
#include "CException.h"


void setUp(void){}



void tearDown(void){}



void test_numberNew_should_get_single_digit_value_and_type(void) {



 Number *number=numberNew(5);



 if ((((number)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)18);;};

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((number->value)), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number->type)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_more_than_single_digit_value_and_type(void) {



 Number *number=numberNew(5000);



 if ((((number)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)27);;};

 UnityAssertEqualNumber((_U_SINT)((5000)), (_U_SINT)((number->value)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number->type)), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

}



void test_numberNew_should_get_negative_value_and_type(void) {



 Number *number=numberNew(-5);



 if ((((number)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)36);;};

 UnityAssertEqualNumber((_U_SINT)((-5)), (_U_SINT)((number->value)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number->type)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

}



void test_identifierNew_should_identifier_the_content(void){

 Text *text = textNew("Jason");

 Identifier *identifier = identifierNew(text);



 if ((((identifier)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)45);;};

 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((identifier->name)), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier->type)), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier->number)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);



}



void test_identifierNew_should_identifier_the_content2(void){

 Text *text = textNew("Chuah");

 Identifier *identifier = identifierNew(text);



 if ((((identifier)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)56);;};

 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((identifier->name)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier->type)), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier->number)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);



}



void test_identifierNew_should_identifier_the_content_three(void){



 Text *text = textNew("apple123");

 Identifier *identifier = identifierNew(text);



 if ((((identifier)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)68);;};

 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((identifier->name)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier->type)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((identifier->number)), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewBySymbol_should_identify_the_symbol(void){





 Operator *operator = operatorNewBySymbol("+");



 if ((((operator)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)80);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(operator->info->symbol), (((void *)0)), (_U_UINT)82);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol(void){





 Operator *operator = operatorNewBySymbol("-");



 if ((((operator)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)92);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("-"), (const char*)(operator->info->symbol), (((void *)0)), (_U_UINT)94);

 UnityAssertEqualNumber((_U_SINT)((SUB_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol2(void){



 Operator *operator = operatorNewBySymbol("*");



 if ((((operator)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)103);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("*"), (const char*)(operator->info->symbol), (((void *)0)), (_U_UINT)105);

 UnityAssertEqualNumber((_U_SINT)((MUL_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol3(void){



 Operator *operator = operatorNewBySymbol("/");



 if ((((operator)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)114);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("/"), (const char*)(operator->info->symbol), (((void *)0)), (_U_UINT)116);

 UnityAssertEqualNumber((_U_SINT)((DIV_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should__retur_NULL_if_input_invalid_symbol(void){



 Operator *operator = operatorNewBySymbol("@");



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator)), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_identify_the_different_symbol4(void){



 Operator *operator = operatorNewBySymbol("~");



 if ((((operator)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)132);;};

 UnityAssertEqualString((const char*)("~"), (const char*)(operator->info->symbol), (((void *)0)), (_U_UINT)133);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)134, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)136, UNITY_DISPLAY_STYLE_INT);



}



void test_operatorNewByID_should_identify_the_different_symbol(void){



 Operator *operator =operatorNewByID(ADD_OP);

 if ((((operator)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)143);;};

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(operator->info->symbol), (((void *)0)), (_U_UINT)146);



}



void test_operatorNewByID_should_identify_the_different_symbol_two(void){



 Operator *operator =operatorNewByID(BITWISE_AND_OP);

 if ((((operator)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)153);;};

 UnityAssertEqualNumber((_U_SINT)((BITWISE_AND_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)154, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&"), (const char*)(operator->info->symbol), (((void *)0)), (_U_UINT)156);

}



void test_operatorNewByID_should_identify_the_different_symbol_three(void){



 Operator *operator =operatorNewByID(MUL_OP);

 if ((((operator)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)162);;};

 UnityAssertEqualNumber((_U_SINT)((MUL_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("*"), (const char*)(operator->info->symbol), (((void *)0)), (_U_UINT)165);

}



void test_operatorNewByID_should_return_NULL_if_input_the_incorrect_symbol(void){



 Operator *operator =operatorNewByID(111);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);



}
