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





 UnityAssertEqualNumber((_U_SINT)((0X80000000)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);







}



void test_stringNew_should_create_string_with_dynamic_text(void){







 Text *new=textNew("00Raiser");



 String *string = stringNew(new);





 UnityAssertEqualNumber((_U_SINT)((0X02)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);







}







void test_stringAssign_should_increase_reference(void){









 Text *name1 = textNew("Unicorn");



 String *string1 = stringNew(name1);

 String *string2 = stringAssign(string1);



 String *string3 = stringAssign(string2);



 String *string4 = stringAssign(string3);



 String *string5 = stringAssign(string4);





 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string2->reference)), (((void *)0)), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);







}



void test_stringAssign_should_not_increase_reference(void){







 Text *name1 = (Text *)"\x00\x00\x00\x80""Banshee";



 String *string1 = stringNew(name1);



 String *string2 = stringAssign(string1);

 String *string3 = stringDel(string2);





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((string2->reference)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);







}





void test_stringDelete_should_delete_reference(void)

{



 Text * name1=textNew("Strike");





 String *string1=stringNew(name1);





 String *string2= stringAssign(string1);





 String *string3= stringAssign(string2);





 String *string4= stringAssign(string3);





 String *string5= stringAssign(string4);

 stringDump(string5);



 String *string6=stringDel(string1);





 String *string7= stringDel(string1);





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_INT);







}



void test_stringDelete_should_not_delete_reference_for_text(void)

{

 printf("-----Test for stringDelete should not delete reference for text-----\n");

 Text * name1=(Text *)"\x00\x00\x00\x80""QanTa";





 String *string1=stringNew(name1);





 String *string2= stringAssign(string1);





 String *string3= stringAssign(string2);





 String *string4= stringAssign(string3);





 String *string5= stringAssign(string4);





 String *string6=stringDel(string1);





 String *string7= stringDel(string1);





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT);







}





void test_stringDelete_should_delete_all_reference_and_return_null(void)

{



 Text * name1=textNew("Infinite");

 textDump(name1);



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





 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((string10)), (((void *)0)), (_U_UINT)222, UNITY_DISPLAY_STYLE_INT);









}





void test_stringSkip_given_Hello_and_skip_2_should_become_llo(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""Hello");

 str->start ++;

 str->length--;

 stringSkip(str,2);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)238, UNITY_DISPLAY_STYLE_INT);







}



void test_stringSkip_given_gundam_and_skip_4_should_become_am(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""gundam");

 str->start ++;

 str->length--;

 stringSkip(str,4);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)251, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)252, UNITY_DISPLAY_STYLE_INT);







}



void test_stringSkip_given_gundam_and_skip_6_should_return_null(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""gundam");

 str->start ++;

 str->length--;

 stringSkip(str,6);



 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)265, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)266, UNITY_DISPLAY_STYLE_INT);







}



void test_stringSkip_given_beyond_ra_and_skip_2_should_make_start_equals_2_length_equals_0(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""ra");

 str->start +=3;

 str->length-=3;

 stringSkip(str,2);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)279, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)280, UNITY_DISPLAY_STYLE_INT);







}



void test_stringTrimLeft_given_Amazing_prefixed_with_2_space_should_remove_the_spaces(){



 Text *new=textNew("  Amazing");

 String *string1 = stringNew(new);

 stringTrimLeft(string1);



 string1->start ++;

 string1->length--;

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)294, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)295, UNITY_DISPLAY_STYLE_INT);





}



void test_stringTrimLeft_given_Saviour_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""	\tSaviour	");

 stringTrimLeft(str);



 str->start ++;

 str->length--;

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)307, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)308, UNITY_DISPLAY_STYLE_INT);







}



void test_stringTrimRight_given_Comet_postfixed_with_3_space_should_remove_the_spaces(){



 String *str = stringNew((Text *)"\x00\x00\x00\x80""  Comet \t   ");

 str->start ++;

 str->length--;

 stringTrimRight(str);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)321, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)322, UNITY_DISPLAY_STYLE_INT);







}



void test_stringTrimRight_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){





 String *str = stringNew((Text *)"\x00\x00\x00\x80""	hello\t	");

 str->start ++;

 str->length--;

 stringTrimRight(str);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)336, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)337, UNITY_DISPLAY_STYLE_INT);







}



void test_stringTrim_given_hello_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){





 String *str = stringNew((Text *)"\x00\x00\x00\x80""\t \t \t hello \t \t ");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)349, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT);







}



void test_stringTrim_given_Kamaguchi_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){





 String *str = stringNew((Text *)"\x00\x00\x00\x80""\t \t Kamguchi \t \t\t");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)362, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((17)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)363, UNITY_DISPLAY_STYLE_INT);







}



void test_stringTrim_given_Ferraro_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){





 String *str = stringNew((Text *)"\x00\x00\x00\x80""\t \t \t Ferrari \t \t\t");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)375, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((18)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)376, UNITY_DISPLAY_STYLE_INT);







}







void test_stringRemove_should_remove_first_char_within_a_string(void){



 Text * name1=textNew("knight");





 String *string1=stringNew(name1);





 stringRemoveChar(string1);





 UnityAssertEqualNumber((_U_SINT)(('k')), (_U_SINT)((string1->text->string[0])), (((void *)0)), (_U_UINT)395, UNITY_DISPLAY_STYLE_INT);





}



void test_stringRemove_should_remove_three_char_within_a_string(void){



 Text * name1=textNew("knight");





 String *string1=stringNew(name1);





 stringRemoveChar(string1);



 stringRemoveChar(string1);



 stringRemoveChar(string1);





 UnityAssertEqualNumber((_U_SINT)(('k')), (_U_SINT)((string1->text->string[0])), (((void *)0)), (_U_UINT)415, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('n')), (_U_SINT)((string1->text->string[1])), (((void *)0)), (_U_UINT)416, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('i')), (_U_SINT)((string1->text->string[2])), (((void *)0)), (_U_UINT)417, UNITY_DISPLAY_STYLE_INT);





}



void test_stringRemove_should_remove_five_char_within_a_string(void){



 Text * name1=textNew("knight");





 String *string1=stringNew(name1);





 stringRemoveChar(string1);



 stringRemoveChar(string1);



 stringRemoveChar(string1);



 stringRemoveChar(string1);



 stringRemoveChar(string1);





 UnityAssertEqualNumber((_U_SINT)(('k')), (_U_SINT)((string1->text->string[0])), (((void *)0)), (_U_UINT)441, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('n')), (_U_SINT)((string1->text->string[1])), (((void *)0)), (_U_UINT)442, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('i')), (_U_SINT)((string1->text->string[2])), (((void *)0)), (_U_UINT)443, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('g')), (_U_SINT)((string1->text->string[3])), (((void *)0)), (_U_UINT)444, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('h')), (_U_SINT)((string1->text->string[4])), (((void *)0)), (_U_UINT)445, UNITY_DISPLAY_STYLE_INT);







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





 UnityAssertEqualNumber((_U_SINT)(('k')), (_U_SINT)((string1->text->string[0])), (((void *)0)), (_U_UINT)476, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('n')), (_U_SINT)((string1->text->string[1])), (((void *)0)), (_U_UINT)477, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('i')), (_U_SINT)((string1->text->string[2])), (((void *)0)), (_U_UINT)478, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('g')), (_U_SINT)((string1->text->string[3])), (((void *)0)), (_U_UINT)479, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('h')), (_U_SINT)((string1->text->string[4])), (((void *)0)), (_U_UINT)480, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('t')), (_U_SINT)((string1->text->string[5])), (((void *)0)), (_U_UINT)481, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((a)), (((void *)0)), (_U_UINT)482, UNITY_DISPLAY_STYLE_INT);





}



void test_stringLength_should_get_the_correct_length(void){





 int input ;

 Text * name1=textNew("pikachu");



 String *string1=stringNew(name1);



 input = stringLength(string1);





 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)498, UNITY_DISPLAY_STYLE_INT);





}



void test_stringLength_should_get_the_correct_length2(void){





 int input ;

 Text * name1=textNew("     pikachu");



 String *string1=stringNew(name1);



 input = stringLength(string1);





 UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)514, UNITY_DISPLAY_STYLE_INT);





}



void test_stringLength_should_get_the_correct_length3(void){





 int input ;

 Text * name1=textNew("     \t \t \t \t \t \t \t pikachu");



 String *string1=stringNew(name1);



 input = stringLength(string1);





 UnityAssertEqualNumber((_U_SINT)((26)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)530, UNITY_DISPLAY_STYLE_INT);





}



void test_stringRemoveWordNotContaining_should_test_input_and_start_with_alphabet(void){

 printf("-----Test for stringRemoveWordNotContaining -----\n");

 Text * name1=(Text *)"\x00\x00\x00\x80""Bulldog";

 String *string1= stringNew(name1);

 String *string2= stringRemoveWordNotContaining(string1,"gd");

 stringDump(string1);

 stringDump(string2);

 printf("-                                               -\n");

 printf("-                                               -\n");

}



void test_stringRemoveWordNotContaining_should_test_input_and_start_with_alphabet2(void){

 printf("-----Test for stringRemoveWordNotContaining -----\n");

 Text * name1=textNew("BaskinRobbin");

 String *string1= stringNew(name1);

 string1->start++;

 string1->length--;



 String *string2= stringRemoveWordNotContaining(string1,"onb");

 stringDump(string2);

 stringDump(string1);



 printf("-                                               -\n");

 printf("-                                               -\n");

}



void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet1(void){



 Text *name1=textNew("apple");

 String *string1=stringNew(name1);



 String *string2 = stringRemoveWordContaining(string1,"ap");

 stringDump(string1);

 stringDump(string2);

 UnityAssertEqualNumber((_U_SINT)(('a')), (_U_SINT)((string2->text->string[string2->start])), (((void *)0)), (_U_UINT)569, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string2->start)), (((void *)0)), (_U_UINT)570, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string2->length)), (((void *)0)), (_U_UINT)571, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)573, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)574, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}



void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet2(void){



 Text *name1=textNew("1234ABCD56");

 String *string1=stringNew(name1);



 String *string2 = stringRemoveWordContaining(string1,"1234");

 stringDump(string2);

 stringDump(string1);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string2->start)), (((void *)0)), (_U_UINT)587, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string2->length)), (((void *)0)), (_U_UINT)588, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)590, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)591, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}



void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet3(void){



 Text *name1=textNew("1234ABCD56");

 String *string1=stringNew(name1);



 String *string2 = stringRemoveWordContaining(string1,"2134");

 stringDump(string2);

 stringDump(string1);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string2->start)), (((void *)0)), (_U_UINT)604, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string2->length)), (((void *)0)), (_U_UINT)605, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)607, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)608, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}



void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet4(void){



 Text *name1=textNew("1234ABCD56");

 String *string1=stringNew(name1);



 String *string2 = stringRemoveWordContaining(string1,"3214");

 stringDump(string2);

 stringDump(string1);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string2->start)), (((void *)0)), (_U_UINT)621, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string2->length)), (((void *)0)), (_U_UINT)622, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)624, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)625, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

}



void xtest_stringRemoveWordContaining_should_test_input_and_start_with_alphabet5(void){



 Text *name1=textNew("1234ABCD56");

 String *string1=stringNew(name1);



 String *string2 = stringRemoveWordContaining(string1,"ABCD");

 stringDump(string2);

 stringDump(string1);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string2->start)), (((void *)0)), (_U_UINT)638, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string2->length)), (((void *)0)), (_U_UINT)639, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)641, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)642, UNITY_DISPLAY_STYLE_INT);

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



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)663, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)664, UNITY_DISPLAY_STYLE_INT);

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



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)684, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)685, UNITY_DISPLAY_STYLE_INT);

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



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)705, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)706, UNITY_DISPLAY_STYLE_INT);

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

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)726, UNITY_DISPLAY_STYLE_INT);



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

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)747, UNITY_DISPLAY_STYLE_INT);



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

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)768, UNITY_DISPLAY_STYLE_INT);



 printf("-                                               -\n");

}



void test_stringCharAt_should_return_negative_one_if_startIndex_is_more_than_lenght(void)

{

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=5;



 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((stringCharAt(string1,0))), (((void *)0)), (_U_UINT)779, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAt_should_return_relative_character(void)

{

 int input;

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=0;



 input = stringCharAt(string1,2);



 UnityAssertEqualNumber((_U_SINT)(('l')), (_U_SINT)((input)), (((void *)0)), (_U_UINT)791, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAt_should_return_relative_character2(void)

{

 int input;

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=1;



 input = stringCharAt(string1,3);



 UnityAssertEqualNumber((_U_SINT)(('o')), (_U_SINT)((input)), (((void *)0)), (_U_UINT)803, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAtInSet_should_return_negative_one(void){

 int input;

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=0;



 input = stringCharAtInSet(string1,1,"abcd");



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)814, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAtInSet_should_return_relative_character2(void){

 int input;

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=0;



 input = stringCharAtInSet(string1,2,"abeld");



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)825, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAtInSet_should_return_relative_character3(void){

 int input;

 Text *name1=textNew("Hello");

 String *string1=stringNew(name1);

 string1->start=1;



 input = stringCharAtInSet(string1,3,"abo");



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)836, UNITY_DISPLAY_STYLE_INT);

}



void test_stringSubstringInChar_Phone016_should_return_016(void){



 char *input;

 Text *name1=textNew("Phone016");

 String *string1=stringNew(name1);



 input = stringSubstringInChar(string1,5,3);

 printf("%s\n",input);



 UnityAssertEqualString((const char*)("016"), (const char*)(input), (((void *)0)), (_U_UINT)848);

}



void test_stringSubstringInChar2_HandPhone016123_should_return_Phone016123(void){



 char *input;

 Text *name1=textNew("HandPhone016123");

 String *string1=stringNew(name1);



 input = stringSubstringInChar(string1,4,13);

 printf("%s\n",input);



 UnityAssertEqualString((const char*)("Phone016123"), (const char*)(input), (((void *)0)), (_U_UINT)860);

}



void test_stringSubstringInChar_Phone016_should_return_NULL_if_length_of_string_exceeded(void){



 char *input;

 Text *name1=textNew("Phone016");

 String *string1=stringNew(name1);



 input = stringSubstringInChar(string1,1,10);

 printf("%s\n",input);



 UnityAssertEqualString((const char*)(" "), (const char*)(input), (((void *)0)), (_U_UINT)872);

}



void test_stringSubstringInText_Phone016_should_return_016(void){



 Text *name1=textNew("Phone016");

 String *string1=stringNew(name1);



 Text *stringText = stringSubstringInText(string1,5,3);





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringText->reference)), (((void *)0)), (_U_UINT)883, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("016"), (const char*)(stringText->string), (((void *)0)), (_U_UINT)884);



}



void test_stringSubstringInText_should_get_substring(void){



 Text *name1=textNew("HandPhone016123");

 String *string1=stringNew(name1);



 Text *stringText = stringSubstringInText(string1,6,6);





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringText->reference)), (((void *)0)), (_U_UINT)896, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("one016"), (const char*)(stringText->string), (((void *)0)), (_U_UINT)897);



}



void test_stringSubstringInText_should_return_empty_string(void){



 Text *name1=textNew("HandPhone016123");

 String *string1=stringNew(name1);



 Text *stringText = stringSubstringInText(string1,6,20);





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringText->reference)), (((void *)0)), (_U_UINT)909, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)(" "), (const char*)(stringText->string), (((void *)0)), (_U_UINT)910);



}



void test_stringToInteger_should_return_integer_type(void){

 int input;

 Text *name1=textNew("HandPhone016123");

 String *string1=stringNew(name1);

 string1->start=10;

 string1->length=5;



 input=stringToInteger(string1);



 UnityAssertEqualNumber((_U_SINT)((16123)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)923, UNITY_DISPLAY_STYLE_INT);

}



void test_stringToInteger_should_return_integer_type2(void){

 int input;

 Text *name1=textNew("Hand016123Phone");

 String *string1=stringNew(name1);

 string1->start=5;

 string1->length=4;



 input=stringToInteger(string1);



 UnityAssertEqualNumber((_U_SINT)((1612)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)935, UNITY_DISPLAY_STYLE_INT);

}



void test_stringToInteger_should_return_integer_type3(void){

 int input;

 Text *name1=textNew("Hand016123Phone");

 String *string1=stringNew(name1);

 string1->start=5;

 string1->length=4;



 input=stringToInteger(string1);



 UnityAssertEqualNumber((_U_SINT)((1612)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)947, UNITY_DISPLAY_STYLE_INT);

}
