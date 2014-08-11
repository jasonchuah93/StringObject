#include "unity.h"
#include "Text.h"
#include "StringObject.h"
#include "CustomTypeAssert.h"


typedef struct FakeText{

 uint32 reference;

 char string[80];

}FakeText;



void setUp(void){}



void tearDown(void){}



void test_StringDump_explore(void){



 FakeText fakeText={

  .reference = 10,

  .string = "hello world!"



  };



 String str={

  .reference = 20,

  .text= (Text *)&fakeText,

  .start=11,

  .length =100



  };





 stringDump(&str);



}





void test_stringNew_should_create_string_with_static_text(void){



 Text *new=(Text *)"\x00\x00\x00\x80""Exia";

 String *string = stringNew(new);

 UnityAssertEqualNumber((_U_SINT)((0X80000000)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

}



void test_stringNew_should_create_string_with_dynamic_text(void){



 Text *new=textNew("00Raiser");

 String *string = stringNew(new);

 UnityAssertEqualNumber((_U_SINT)((0X02)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

}







void test_stringAssign_should_increase_reference(void){



 Text *name1 = textNew("Unicorn");

 String *string1 = stringNew(name1);

 String *string2 = stringAssign(string1);

 String *string3 = stringAssign(string2);

 String *string4 = stringAssign(string3);

 String *string5 = stringAssign(string4);



 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string2->reference)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

}



void test_stringAssign_should_not_increase_reference(void){



 Text *name1 = (Text *)"\x00\x00\x00\x80""Banshee";



 String *string1 = stringNew(name1);

 String *string2 = stringAssign(string1);

 String *string3 = stringDel(string2);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((string2->reference)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

}





void test_stringDelete_should_delete_reference(void){



 Text * name1=textNew("Strike");

 String *string1=stringNew(name1);

 String *string2= stringAssign(string1);

 String *string3= stringAssign(string2);

 String *string4= stringAssign(string3);

 String *string5= stringAssign(string4);

 String *string6=stringDel(string1);

 String *string7= stringDel(string1);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDelete_should_not_delete_reference_for_text(void){



 Text * name1=(Text *)"\x00\x00\x00\x80""QanTa";

 String *string1=stringNew(name1);

 String *string2= stringAssign(string1);

 String *string3= stringAssign(string2);

 String *string4= stringAssign(string3);

 String *string5= stringAssign(string4);

 String *string6=stringDel(string1);

 String *string7= stringDel(string1);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

}





void test_stringDelete_should_delete_all_reference_and_return_null(void){



 Text * name1=textNew("Infinite");

 String *string1=stringNew(name1);

 String *string2= stringAssign(string1);

 String *string3= stringAssign(string2);

 String *string4= stringAssign(string3);

 String *string5= stringAssign(string4);

 String *string6=stringDel(string1);

 String *string7= stringDel(string1);

 String *string8= stringDel(string1);

 String *string9= stringDel(string1);

 String *string10= stringDel(string1);

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((string10)), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_INT);

}





void test_stringSkip_given_Hello_and_skip_2_should_become_llo(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""Hello");

 str->start ++;

 str->length--;

 stringSkip(str,2);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT);



}



void test_stringSkip_given_gundam_and_skip_4_should_become_am(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""gundam");

 str->start ++;

 str->length--;

 stringSkip(str,4);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)150, UNITY_DISPLAY_STYLE_INT);

}



void test_stringSkip_given_gundam_and_skip_6_should_return_null(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""gundam");

 str->start ++;

 str->length--;

 stringSkip(str,6);



 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)161, UNITY_DISPLAY_STYLE_INT);

}



void test_stringSkip_given_beyond_ra_and_skip_2_should_make_start_equals_2_length_equals_0(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""ra");

 str->start +=3;

 str->length-=3;

 stringSkip(str,2);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);



}



void test_stringTrimLeft_given_Amazing_prefixed_with_2_space_should_remove_the_spaces(){



 Text *new=textNew("  Amazing");

 String *string1 = stringNew(new);

 stringTrimLeft(string1);



 string1->start ++;

 string1->length--;

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)184, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimLeft_given_Saviour_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""	\tSaviour	");

 stringTrimLeft(str);



 str->start ++;

 str->length--;

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)195, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)196, UNITY_DISPLAY_STYLE_INT);



}



void test_stringTrimRight_given_Comet_postfixed_with_3_space_should_remove_the_spaces(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""  Comet \t   ");

 str->start ++;

 str->length--;

 stringTrimRight(str);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)207, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)208, UNITY_DISPLAY_STYLE_INT);



}



void test_stringTrimRight_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){





 String *str = stringNew((Text *)"\x00\x00\x00\x80""	hello\t	");

 str->start ++;

 str->length--;

 stringTrimRight(str);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)221, UNITY_DISPLAY_STYLE_INT);



}



void test_stringTrim_given_hello_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){





 String *str = stringNew((Text *)"\x00\x00\x00\x80""\t \t \t hello \t \t ");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);



}



void test_stringTrim_given_Kamaguchi_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){





 String *str = stringNew((Text *)"\x00\x00\x00\x80""\t \t Kamguchi \t \t\t");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)242, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((17)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)243, UNITY_DISPLAY_STYLE_INT);



}



void test_stringTrim_given_Ferraro_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){





 String *str = stringNew((Text *)"\x00\x00\x00\x80""\t \t \t Ferrari \t \t\t");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)253, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((18)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)254, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemove_should_remove_first_char_within_a_string(void){



 Text * name1=textNew("knight");

 String *string1=stringNew(name1);

 stringRemoveChar(string1);

 UnityAssertEqualNumber((_U_SINT)(('k')), (_U_SINT)((string1->text->string[0])), (((void *)0)), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemove_should_remove_three_char_within_a_string(void){



 Text * name1=textNew("knight");

 String *string1=stringNew(name1);

 stringRemoveChar(string1);

 stringRemoveChar(string1);

 stringRemoveChar(string1);

 UnityAssertEqualNumber((_U_SINT)(('k')), (_U_SINT)((string1->text->string[0])), (((void *)0)), (_U_UINT)272, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('n')), (_U_SINT)((string1->text->string[1])), (((void *)0)), (_U_UINT)273, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('i')), (_U_SINT)((string1->text->string[2])), (((void *)0)), (_U_UINT)274, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemove_should_remove_five_char_within_a_string(void){



 Text * name1=textNew("knight");

 String *string1=stringNew(name1);

 stringRemoveChar(string1);

 stringRemoveChar(string1);

 stringRemoveChar(string1);

 stringRemoveChar(string1);

 stringRemoveChar(string1);



 UnityAssertEqualNumber((_U_SINT)(('k')), (_U_SINT)((string1->text->string[0])), (((void *)0)), (_U_UINT)287, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('n')), (_U_SINT)((string1->text->string[1])), (((void *)0)), (_U_UINT)288, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('i')), (_U_SINT)((string1->text->string[2])), (((void *)0)), (_U_UINT)289, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('g')), (_U_SINT)((string1->text->string[3])), (((void *)0)), (_U_UINT)290, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('h')), (_U_SINT)((string1->text->string[4])), (((void *)0)), (_U_UINT)291, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemove_should_remove_all_char_within_a_string(void){





 char a;

 Text * name1=textNew("knight");



 String *string1=stringNew(name1);

 stringRemoveChar(string1);

 stringRemoveChar(string1);

 stringRemoveChar(string1);

 stringRemoveChar(string1);

 stringRemoveChar(string1);

 stringRemoveChar(string1);

 a=stringRemoveChar(string1);



 UnityAssertEqualNumber((_U_SINT)(('k')), (_U_SINT)((string1->text->string[0])), (((void *)0)), (_U_UINT)309, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('n')), (_U_SINT)((string1->text->string[1])), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('i')), (_U_SINT)((string1->text->string[2])), (((void *)0)), (_U_UINT)311, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('g')), (_U_SINT)((string1->text->string[3])), (((void *)0)), (_U_UINT)312, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('h')), (_U_SINT)((string1->text->string[4])), (((void *)0)), (_U_UINT)313, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('t')), (_U_SINT)((string1->text->string[5])), (((void *)0)), (_U_UINT)314, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((a)), (((void *)0)), (_U_UINT)315, UNITY_DISPLAY_STYLE_INT);

}



void test_stringLength_should_get_the_correct_length(void){

 int input ;

 Text * name1=textNew("pikachu");



 String *string1=stringNew(name1);

 input = stringLength(string1);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)324, UNITY_DISPLAY_STYLE_INT);

}



void test_stringLength_should_get_the_correct_length2(void){

 int input ;

 Text * name1=textNew("     pikachu");

 String *string1=stringNew(name1);

 input = stringLength(string1);

 UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)332, UNITY_DISPLAY_STYLE_INT);

}



void test_stringLength_should_get_the_correct_length3(void){

 int input;

 Text * name1=textNew("     \t \t \t \t \t \t \t pikachu");

 String *string1=stringNew(name1);

 input = stringLength(string1);

 UnityAssertEqualNumber((_U_SINT)((26)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)340, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining_should_test_input_and_start_with_alphabet(void){

 Text * name1=(Text *)"\x00\x00\x00\x80""Bulldog";

 String *string1= stringNew(name1);

 String *string2= stringRemoveWordNotContaining(string1,"gd");

 assertStringEqual(("dog"), (string1), 347, ((void *)0));

 assertStringEqual(("Bull"), (string2), 348, ((void *)0));

}



void test_stringRemoveWordNotContaining_should_test_input_and_start_with_alphabet2(void){

 Text * name1=textNew("BaskinRobbin");

 String *string1= stringNew(name1);

 string1->start++;

 string1->length--;



 String *string2= stringRemoveWordNotContaining(string1,"onb");

 assertStringEqual(("nRobbin"), (string1), 358, ((void *)0));

 assertStringEqual(("aski"), (string2), 359, ((void *)0));

}



void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet1(void){



 Text *name1=textNew("apple");

 String *string1=stringNew(name1);



 String *string2 = stringRemoveWordContaining(string1,"ap");

 stringDump(string1);

 stringDump(string2);

 UnityAssertEqualNumber((_U_SINT)(('a')), (_U_SINT)((string2->text->string[string2->start])), (((void *)0)), (_U_UINT)370, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string2->start)), (((void *)0)), (_U_UINT)371, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string2->length)), (((void *)0)), (_U_UINT)372, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)374, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)375, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}



void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet2(void){



 Text *name1=textNew("1234ABCD56");

 String *string1=stringNew(name1);



 String *string2 = stringRemoveWordContaining(string1,"1234");

 stringDump(string2);

 stringDump(string1);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string2->start)), (((void *)0)), (_U_UINT)388, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string2->length)), (((void *)0)), (_U_UINT)389, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)391, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)392, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}



void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet3(void){



 Text *name1=textNew("1234ABCD56");

 String *string1=stringNew(name1);



 String *string2 = stringRemoveWordContaining(string1,"2134");

 stringDump(string2);

 stringDump(string1);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string2->start)), (((void *)0)), (_U_UINT)405, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string2->length)), (((void *)0)), (_U_UINT)406, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)408, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)409, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}



void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet4(void){



 Text *name1=textNew("1234ABCD56");

 String *string1=stringNew(name1);



 String *string2 = stringRemoveWordContaining(string1,"3214");

 stringDump(string2);

 stringDump(string1);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string2->start)), (((void *)0)), (_U_UINT)422, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string2->length)), (((void *)0)), (_U_UINT)423, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)425, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)426, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}



void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet5(void){



 Text *name1=textNew("ABCD123456");

 String *string1=stringNew(name1);



 String *string2 = stringRemoveWordContaining(string1,"BDCA");

 stringDump(string2);

 stringDump(string1);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string2->start)), (((void *)0)), (_U_UINT)439, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string2->length)), (((void *)0)), (_U_UINT)440, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)442, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)443, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}





void test_stringIsEqual_should_return_one_if_both_string_is_same(void){

 printf("-----Test for stringIsEqual -----\n");

 int input;

 Text *name1=textNew("pineapple");

 String *string1 = stringNew(name1);



 Text *name2=textNew("apple");

 String *string2 = stringNew(name2);



 string1->start = string1->start+4;

 string1->length = string1->length-4;



 input= stringIsEqual(string1,string2);

 stringDump(string1);

 stringDump(string2);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)464, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)465, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}



void test_stringIsEqual_should_return_one_if_both_string_is_same01(void){

 printf("-----Test for stringIsEqual -----\n");

 int input;

 Text *name1=textNew("apkle");

 String *string1 = stringNew(name1);



 Text *name2=textNew("apple");

 String *string2 = stringNew(name2);



 string1->start = string1->start+4;

 string1->length = string1->length-4;



 input= stringIsEqual(string1,string2);

 stringDump(string1);

 stringDump(string2);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)485, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)486, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}



void test_stringIsEqual_should_return_zero_if_both_string_is_same02(void){

 printf("-----Test for stringIsEqual -----\n");

 int input;

 Text *name1=textNew("apple");

 String *string1 = stringNew(name1);



 Text *name2=textNew("apple ");

 String *string2 = stringNew(name2);



 string1->start = string1->start+4;

 string1->length = string1->length-4;



 input= stringIsEqual(string1,string2);

 stringDump(string1);

 stringDump(string2);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)506, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)507, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}



void test_stringIsEqualCaseInsensitive_should_set_all_alphabet_to_lower_case(void){



 printf("-----Test for stringIsEqualCaseSensitive if text have same case sensitive-----\n");

 int input ;

 printf("Before\n");

 Text *name1=textNew("aPPLE");

 String *string1=stringNew(name1);

 stringDump(string1);



 Text *name2=textNew("ApplE");

 String *string2=stringNew(name2);

 stringDump(string2);

 printf("After\n");

 input = stringIsEqualCaseInsensitive(string1,string2);

 stringDump(string1);

 stringDump(string2);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)527, UNITY_DISPLAY_STYLE_INT);



 printf("-                                               -\n");

}



void test_stringIsEqualCaseInsensitive_should_set_all_alphabet_to_lower_case2(void){



 printf("-----Test for stringIsEqualCaseSensitive if text have same case sensitive 2-----\n");

 int input ;

 printf("Before\n");

 Text *name1=textNew("HandPhone");

 String *string1=stringNew(name1);

 stringDump(string1);



 Text *name2=textNew("hANDpHonE");

 String *string2=stringNew(name2);

 stringDump(string2);

 printf("After\n");

 input = stringIsEqualCaseInsensitive(string1,string2);

 stringDump(string1);

 stringDump(string2);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)548, UNITY_DISPLAY_STYLE_INT);



 printf("-                                               -\n");

}



void test_stringIsEqualCaseInsensitive_should_set_all_alphabet_to_lower_case01(void){



 printf("-----Test for stringIsEqualCaseSensitive if text have same case sensitive 2-----\n");

 int input ;

 printf("Before\n");

 Text *name1=textNew("apple");

 String *string1=stringNew(name1);

 stringDump(string1);



 Text *name2=textNew("ApPLe");

 String *string2=stringNew(name2);

 stringDump(string2);

 printf("After\n");

 input = stringIsEqualCaseInsensitive(string1,string2);

 stringDump(string1);

 stringDump(string2);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)569, UNITY_DISPLAY_STYLE_INT);



 printf("-                                               -\n");

}



void test_stringCharAt_should_return_zero_if_startIndex_is_more_than_lenght(void)

{

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=5;



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((stringCharAt(string1,0))), (((void *)0)), (_U_UINT)580, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAt_should_return_relative_character(void)

{

 int input;

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=0;



 input = stringCharAt(string1,2);



 UnityAssertEqualNumber((_U_SINT)(('l')), (_U_SINT)((input)), (((void *)0)), (_U_UINT)592, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAt_should_return_relative_character2(void)

{

 int input;

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=1;



 input = stringCharAt(string1,3);



 UnityAssertEqualNumber((_U_SINT)(('o')), (_U_SINT)((input)), (((void *)0)), (_U_UINT)604, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAtInSet_should_return_negative_one(void){

 int input;

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=0;



 input = stringCharAtInSet(string1,1,"abcd");



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)615, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAtInSet_should_return_relative_character2(void){

 int input;

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=0;



 input = stringCharAtInSet(string1,2,"abeld");



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)626, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAtInSet_should_return_relative_character3(void){

 int input;

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=1;



 input = stringCharAtInSet(string1,3,"abo");



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)637, UNITY_DISPLAY_STYLE_INT);

}



void test_stringSubstringInChar_Phone016_should_return_016(void){



 char *input;

 Text *name1=textNew("Phone016");

 String *string1=stringNew(name1);



 input = stringSubstringInChar(string1,5,3);

 printf("%s\n",input);



 UnityAssertEqualString((const char*)("016"), (const char*)(input), (((void *)0)), (_U_UINT)649);

}



void test_stringSubstringInChar2_HandPhone016123_should_return_Phone016123(void){



 char *input;

 Text *name1=textNew("HandPhone016123");

 String *string1=stringNew(name1);



 input = stringSubstringInChar(string1,4,13);

 printf("%s\n",input);



 UnityAssertEqualString((const char*)("Phone016123"), (const char*)(input), (((void *)0)), (_U_UINT)661);

}



void test_stringSubstringInChar_Phone016_should_return_NULL_if_length_of_string_exceeded(void){



 char *input;

 Text *name1=textNew("Phone016");

 String *string1=stringNew(name1);



 input = stringSubstringInChar(string1,1,10);

 printf("%s\n",input);



 UnityAssertEqualString((const char*)(" "), (const char*)(input), (((void *)0)), (_U_UINT)673);

}



void test_stringSubstringInText_Phone016_should_return_016(void){



 Text *name1=textNew("Phone016");

 String *string1=stringNew(name1);



 Text *stringText = stringSubstringInText(string1,5,3);





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringText->reference)), (((void *)0)), (_U_UINT)684, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("016"), (const char*)(stringText->string), (((void *)0)), (_U_UINT)685);



}



void test_stringSubstringInText_should_get_substring(void){



 Text *name1=textNew("HandPhone016123");

 String *string1=stringNew(name1);



 Text *stringText = stringSubstringInText(string1,6,6);





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringText->reference)), (((void *)0)), (_U_UINT)697, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("one016"), (const char*)(stringText->string), (((void *)0)), (_U_UINT)698);



}



void test_stringSubstringInText_should_return_empty_string(void){



 Text *name1=textNew("HandPhone016123");

 String *string1=stringNew(name1);



 Text *stringText = stringSubstringInText(string1,6,20);





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringText->reference)), (((void *)0)), (_U_UINT)710, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)(" "), (const char*)(stringText->string), (((void *)0)), (_U_UINT)711);



}



void test_stringToInteger_should_return_integer_type(void){

 int input;

 Text *name1=textNew("HandPhone016123");

 String *string1=stringNew(name1);

 string1->start=10;

 string1->length=5;



 input=stringToInteger(string1);



 UnityAssertEqualNumber((_U_SINT)((16123)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)724, UNITY_DISPLAY_STYLE_INT);

}



void test_stringToInteger_should_return_integer_type2(void){

 int input;

 Text *name1=textNew("Hand016123Phone");

 String *string1=stringNew(name1);

 string1->start=5;

 string1->length=4;



 input=stringToInteger(string1);



 UnityAssertEqualNumber((_U_SINT)((1612)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)736, UNITY_DISPLAY_STYLE_INT);

}



void test_stringToInteger_should_return_integer_type3(void){

 int input;

 Text *name1=textNew("Hand016123Phone");

 String *string1=stringNew(name1);

 string1->start=5;

 string1->length=4;



 input=stringToInteger(string1);



 UnityAssertEqualNumber((_U_SINT)((1612)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)748, UNITY_DISPLAY_STYLE_INT);

}
