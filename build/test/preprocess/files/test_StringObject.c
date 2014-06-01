#include "unity.h"
#include "StringObject.h"




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



void test_textDump_explore(void){



 FakeText fakeText={

 .reference=0x3,

 .string = "dummy"

 };



 textDump((Text*)&fakeText);



}



void test_textNew_should_create_a_static_text(void){





 printf("-----Test for textNew to make a static text-----\n");



 Text *text;



 text=(Text *)"\x00\x00\x00\x80""Freedom";

 textDump(text);



 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");

}



void test_textNew_should_create_a_dynamic_text(void){





 printf("-----Test for textNew to make a dynamic text-----\n");



 Text *text;



 text=textNew("Justice");

 textDump(text);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");

}



void test_stringNew_should_create_string_with_static_text(void){



 printf("-----Test for stringNew to create string from static text-----\n");



 Text *new=(Text *)"\x00\x00\x00\x80""Exia";

 textDump(new);

 String *string = stringNew(new);

 stringDump(string);



 UnityAssertEqualNumber((_U_SINT)((0X80000000)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringNew_should_create_string_with_dynamic_text(void){



 printf("-----Test for stringNew to create string from dynamic text-----\n");



 Text *new=textNew("00Raiser");

 textDump(new);

 String *string = stringNew(new);

 stringDump(string);



 UnityAssertEqualNumber((_U_SINT)((0X02)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_textAssign_should_increase_text_reference(void){



 printf("-----Test for textAssign to increase text reference-----\n");





 Text *name1;

 Text *name2;

 Text *name3;

 Text *name4;

 Text *name5;



 name1= textNew("Arios");

 textDump(name1);

 name2 = textAssign(name1);

 textDump(name2);

 name3 = textAssign(name2);

 textDump(name3);

 name4 = textAssign(name3);

 textDump(name4);

 name5 = textAssign(name4);

 textDump(name5);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)132, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((name3->reference)), (((void *)0)), (_U_UINT)133, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((name4->reference)), (((void *)0)), (_U_UINT)134, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((name5->reference)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_textAssign_should__not_increase_text_reference(void){



 printf("-----Test for textAssign to not to increase text reference-----\n");



 Text *name1;

 Text *name2;





 name1=(Text *)"\x00\x00\x00\x80""Dynames";

 printf("-----name1-----\n");

 textDump(name1);

 name2 = textAssign(name1);

 printf("-----name2-----\n");

 textDump(name2);



 UnityAssertEqualNumber((_U_SINT)((0X80000000)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0X80000000)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((name1->reference)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringAssign_should_increase_reference(void){





 printf("-----Test for stringAssign to increase reference-----\n");



 Text *name1 = textNew("Unicorn");

 textDump(name1);

 String *string1 = stringNew(name1);

 String *string2 = stringAssign(string1);

 stringDump(string2);

 String *string3 = stringAssign(string2);

 stringDump(string3);

 String *string4 = stringAssign(string3);

 stringDump(string4);

 String *string5 = stringAssign(string4);

 stringDump(string5);



 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string2->reference)), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)184, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x05)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringAssign_should_not_increase_reference(void){



 printf("-----Test for stringAssign to not to increase reference-----\n");



 Text *name1 = (Text *)"\x00\x00\x00\x80""Banshee";

 textDump(name1);

 String *string1 = stringNew(name1);

 stringDump(string1);

 String *string2 = stringAssign(string1);

 String *string3 = stringDel(string2);

 stringDump(string3);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((string2->reference)), (((void *)0)), (_U_UINT)204, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((string3->reference)), (((void *)0)), (_U_UINT)205, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_textDelete_should_delete_reference_for_dynamic_text(void){



 printf("-----Test for textDelete should delete reference on dynamic text -----\n");

 Text *name1;

 Text *name2;

 Text *name3;

 Text *name4;

 Text *name5;

 Text *name6;

 Text *name7;



 name1=textNew("Destiny");

 textDump(name1);



 name2= textAssign(name1);

 textDump(name2);



 name3=textAssign(name2);

 textDump(name3);



 name4=textAssign(name3);

 textDump(name4);



 name5=textAssign(name4);

 textDump(name5);



 name6=textDel(name1);

 textDump(name6);



 name7=textDel(name1);

 textDump(name7);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)243, UNITY_DISPLAY_STYLE_INT);



 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_textDelete_should_not_delete_reference_for_static_text(void){



 printf("-----Test for textDelete should not delete reference on static text -----\n");

 Text *name1;



 name1=(Text *)"\x00\x00\x00\x80""Legend";

 textDump(name1);



 Text *name2 = textDel(name1);

 textDump(name2);



 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)261, UNITY_DISPLAY_STYLE_INT);



 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringDelete_should_delete_reference(void)

{

 printf("-----Test for stringDelete should delete reference-----\n");

 Text * name1=textNew("Strike");

 textDump(name1);



 String *string1=stringNew(name1);

 stringDump(string1);



 String *string2= stringAssign(string1);

 stringDump(string2);



 String *string3= stringAssign(string2);

 stringDump(string3);



 String *string4= stringAssign(string3);

 stringDump(string4);



 String *string5= stringAssign(string4);

 stringDump(string5);



 String *string6=stringDel(string1);

 stringDump(string6);



 String *string7= stringDel(string1);

 stringDump(string7);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)295, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringDelete_should__not_delete_reference_for_text(void)

{

 printf("-----Test for stringDelete should not delete reference for text-----\n");

 Text * name1=(Text *)"\x00\x00\x00\x80""QanTa";

 textDump(name1);



 String *string1=stringNew(name1);

 stringDump(string1);



 String *string2= stringAssign(string1);

 stringDump(string2);



 String *string3= stringAssign(string2);

 stringDump(string3);



 String *string4= stringAssign(string3);

 stringDump(string4);



 String *string5= stringAssign(string4);

 stringDump(string5);



 String *string6=stringDel(string1);

 stringDump(string6);



 String *string7= stringDel(string1);

 stringDump(string7);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)328, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_textDelete_should_delete_all_reference_and_return_null(void){



 printf("-----Test for textDelete should delete all reference and return NULL -----\n");



 Text *name1=textNew("Impulse");

 textDump(name1);



 Text *name2= textAssign(name1);

 textDump(name2);



 Text *name3=textAssign(name2);

 textDump(name3);



 Text *name4=textAssign(name3);

 textDump(name4);



 Text *name5=textAssign(name4);

 textDump(name5);



 Text *name6=textDel(name1);

 textDump(name6);



 Text *name7=textDel(name1);

 textDump(name7);



 Text *name8=textDel(name1);

 textDump(name8);



 Text *name9=textDel(name1);

 textDump(name9);



 Text *name10=textDel(name1);

 textDump(name10);

 printf(" \n");



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((name10)), (((void *)0)), (_U_UINT)369, UNITY_DISPLAY_STYLE_INT);



 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringDelete_should_delete_all_reference_and_return_null(void)

{

 printf("-----Test for stringDelete should delete all reference-----\n");

 Text * name1=textNew("Infinite");

 textDump(name1);



 String *string1=stringNew(name1);

 stringDump(string1);



 String *string2= stringAssign(string1);

 stringDump(string2);



 String *string3= stringAssign(string2);

 stringDump(string3);



 String *string4= stringAssign(string3);

 stringDump(string4);



 String *string5= stringAssign(string4);

 stringDump(string5);



 String *string6=stringDel(string1);

 stringDump(string6);



 String *string7= stringDel(string1);

 stringDump(string7);



 String *string8= stringDel(string1);

 stringDump(string8);



 String *string9= stringDel(string1);

 stringDump(string9);



 String *string10= stringDel(string1);

 stringDump(string10);

 printf("\n");

 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((string10)), (((void *)0)), (_U_UINT)412, UNITY_DISPLAY_STYLE_INT);



 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_text_explore(void){



 printf("-----------------------------\n");

 printf("-----Test for textExplore-----\n");



 Text *name1 = (Text *)"\x00\x00\x00\x80""James ho";

 Text *name2;

 Text *name3;

 Text *msg;

 String *str1;

 String *str2;

 textDump(name1);

 name2 = textNew("jason");

 textDump(name2);

 printf("---------\n");

 name3 =textAssign(name2);

 textDump(name2);

 textDump(name3);

 name2 =textDel(name2);

 textDump(name2);

 textDump(name3);

 name3 = textDel(name3);

 textDump(name3);

 printf("---------\n");

 printf("name3: %p\n",name3);

 name1 = textDel(name1);

 textDump(name1);



 printf("xxxxxxxxx\n");

 printf("xxxxxxxxx\n");

 msg=textNew("hello");

 textDump(msg);

 printf("xxxxxxxxx\n");

 str1=stringNew(msg);

 stringDump(str1);

 printf("xxxxxxxxx\n");

 str2=stringAssign(str1);

 stringDump(str1);

 stringDump(str2);

 printf("---------\n");

 str2=stringDel(str2);

 stringDump(str2);

 textDump(msg);

 printf("---------\n");

 msg=textDel(msg);

 textDump(msg);

 printf("-----------------------------\n");

}





void test_stringSkip_given_Hello_and_skip_2_should_become_llo(){

 printf("-----Test for stringSkip on hello and become llo-----\n");

 String *str = stringNew((Text *)"\x00\x00\x00\x80""Hello");

 str->start ++;

 str->length--;

 stringSkip(str,2);

 stringDump(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)476, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)477, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringSkip_given_gundam_and_skip_4_should_become_am(){

 printf("-----Test for stringSkip on gundam and become am-----\n");

 String *str = stringNew((Text *)"\x00\x00\x00\x80""gundam");

 str->start ++;

 str->length--;

 stringSkip(str,4);

 stringDump(str);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)490, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)491, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringSkip_given_gundam_and_skip_6_should_return_null(){

 printf("-----Test for stringSkip on gundam and return null-----\n");

 String *str = stringNew((Text *)"\x00\x00\x00\x80""gundam");

 str->start ++;

 str->length--;

 stringSkip(str,6);

 stringDump(str);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)504, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)505, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringSkip_given_beyond_ra_and_skip_2_should_make_start_equals_2_length_equals_0(){

 printf("-----Test for stringSkip beyond ra for start = 2 and length = 0---\n");

 String *str = stringNew((Text *)"\x00\x00\x00\x80""ra");

 str->start +=3;

 str->length-=3;

 stringSkip(str,2);

 stringDump(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)518, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)519, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringTrimLeft_given_Amazing_prefixed_with_2_space_should_remove_the_spaces(){

 printf("-----Test for stringTrimLeft Amazing to remove the space -----\n");

 Text *new=textNew("  Amazing");

 String *string1 = stringNew(new);

 stringTrimLeft(string1);

 stringDump(string1);

 string1->start ++;

 string1->length--;

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)533, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)534, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");

}



void test_stringTrimLeft_given_Saviour_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){

 printf("-----Test for stringTrimLeft Saviour to remove the space and tab -----\n");

 String *str = stringNew((Text *)"\x00\x00\x00\x80""	\tSaviour	");

 stringTrimLeft(str);

 stringDump(str);

 str->start ++;

 str->length--;

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)546, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)547, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringTrimRight_given_Comet_postfixed_with_3_space_should_remove_the_spaces(){

 printf("-----Test for stringTrimRight Comet to remove the spaces -----\n");

 String *str = stringNew((Text *)"\x00\x00\x00\x80""  Comet \t   ");

 str->start ++;

 str->length--;

 stringTrimRight(str);

 stringDump(str);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)560, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)561, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringTrimRight_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){



 printf("-----Test for stringTrimRight Hello to remove the spaces and tab -----\n");

 String *str = stringNew((Text *)"\x00\x00\x00\x80""	hello\t	");

 str->start ++;

 str->length--;

 stringTrimRight(str);

 stringDump(str);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)575, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)576, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringTrim_given_hello_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){



 printf("-----Test for stringTrim both sides Hello to remove the spaces and tab -----\n");

 String *str = stringNew((Text *)"\x00\x00\x00\x80""\t \t \t hello \t \t ");

 stringTrim(str);

 stringDump(str);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)588, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)589, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringTrim_given_Kamaguchi_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){



 printf("-----Test for stringTrim both sides Hello to remove the spaces and tab -----\n");

 String *str = stringNew((Text *)"\x00\x00\x00\x80""\t \t Kamguchi \t \t\t");

 stringTrim(str);

 stringDump(str);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)601, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((17)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)602, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_stringTrim_given_Ferraro_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){



 printf("-----Test for stringTrim both sides Hello to remove the spaces and tab -----\n");

 String *str = stringNew((Text *)"\x00\x00\x00\x80""\t \t \t Ferrari \t \t\t");

 stringTrim(str);

 stringDump(str);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)614, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((18)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)615, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");



}



void test_textNew_should_create_a_text_with_reference_of_1(void){

 Text *name = textNew("Jackson");

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((name->reference)), (((void *)0)), (_U_UINT)623, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("Jackson"), (const char*)(name->string), (((void *)0)), (_U_UINT)624);



}



void test_textAssign_dynamic_text_should_increase_reference_to_2(void){



 Text *name1 = textNew("Jackson");

 Text *name2 = textAssign(name1);

 UnityAssertEqualNumber((_U_SINT)(_UP)((name1)), (_U_SINT)(_UP)((name2)), (((void *)0)), (_U_UINT)632, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)633, UNITY_DISPLAY_STYLE_INT);



}
