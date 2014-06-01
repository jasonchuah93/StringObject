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



void test_textNew(void){



 printf("-----------------------------\n");

 printf("-----Test for textNew-----\n");



 Text *name;



 name=textNew("testing");

 textDump(name);



 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((name->reference)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);



}



void test_stringNew_should_return_string(void){



 printf("-----------------------------\n");

 printf("-----Test for stringNew-----\n");



 Text *new=textNew("Jason");

 textDump(new);

 String *string = stringNew(new);

 stringDump(string);



 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

}



void test_textAssign(void){



 printf("-----------------------------\n");

 printf("-----Test for textAssign-----\n");



 Text *name1 = (Text *)"\x00\x00\x00\x80""jason";

 Text *name2;

 Text *name3;

 printf("-----name1-----\n");

 textDump(name1);

 name2= textNew("Chuah");

 printf("-----name2------\n");

 textDump(name2);

 name3 = textAssign(name2);

 printf("-----name3-----\n");

 textDump(name3);



 UnityAssertEqualNumber((_U_SINT)((0X80000000)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((name3->reference)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((name2->reference)), (_U_SINT)((name3->reference)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

}



void test_stringAssign_should_return_reference(void){



 printf("-----------------------------\n");

 printf("-----Test for stringAssign-----\n");



 Text *name1 = textNew("jason");

 textDump(name1);

 String *string1 = stringNew(name1);

 String *string2 = stringAssign(string1);

 stringDump(string1);

 stringDump(string2);



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string2->reference)), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);



}



void test_textDelete_should_delete_and_left_only_1(void){



 printf("-----------------------------\n");

 printf("-----Test for textDelete-----\n");

 Text *name1;

 Text *name2;

 Text *name3;

 name1=(Text *)"\x00\x00\x00\x80""Jason";

 printf("-----name1-----\n");

 textDump(name1);

 name2= textNew("Kwong");

 printf("-----name2------\n");

 textDump(name2);

 name3= textAssign(name2);

 printf("-----name3-----\n");

 textDump(name3);

 name2=textDel(name2);

 printf("-----name4-----\n");

 textDump(name2);

 printf("-----name5-----\n");

 textDump(name3);



 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((name3->reference)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDelete_should_delete_and_only_left_one(void)

{

 printf("-------------------------------\n");

 printf("-----Test for stringDelete-----\n");

 Text *name1;

 name1=textNew("jason");

 textDump(name1);

 printf("-----name1-----\n");

 String *string1;

 string1=stringNew(name1);

 stringDump(string1);

 String *string2;

 string2= stringAssign(string1);

 printf("-----name2-----\n");

 stringDump(string2);

 printf("-----name3-----\n");

 string1=stringDel(string1);

 stringDump(string1);

 printf("-------------------------------\n");

 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

}



void test_textDelete_should_delete_all_text_reference_and_return_null(void){



 printf("---------------------------------------------------------\n");

 printf("-----Test for textDelete and return NULL at the end -----\n");

 Text *name1;

 Text *name2;

 Text *name3;

 name1=(Text *)"\x00\x00\x00\x80""Jason";

 printf("-----name1-----\n");

 textDump(name1);

 name2= textNew("Kwong");

 printf("-----name2------\n");

 textDump(name2);

 name3= textAssign(name2);

 printf("-----name3-----\n");

 textDump(name3);

 name2=textDel(name2);

 printf("-----name4-----\n");

 textDump(name2);

 name2=textDel(name2);

 printf("-----name5-----\n");

 textDump(name2);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((name2)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDelete_should_delete_all_string_reference_and_return_null(void)

{

 printf("---------------------------------------------------------\n");

 printf("-----Test for stringDelete and return NULL at the end -----\n");

 Text *name1;

 name1=textNew("Jason");

 printf("-----name1-----\n");

 textDump(name1);

 String *string1;

 string1 = stringNew(name1);

 printf("-----name2------\n");

 stringDump(string1);

 String *string2;

 string2= stringAssign(string1);

 printf("-----name3-----\n");

 stringDump(string2);

 string1=stringDel(string1);

 printf("-----name4-----\n");

 stringDump(string1);

 string2=stringDel(string2);

 printf("-----name5-----\n");

 stringDump(string2);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((string2)), (((void *)0)), (_U_UINT)215, UNITY_DISPLAY_STYLE_INT);

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





void test_stringSkip_given_Hello_and_skip_2_should_become_lo(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""Hello");

 str->start ++;

 str->length--;

 stringSkip(str,2);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)274, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)275, UNITY_DISPLAY_STYLE_INT);

}



void test_stringSkip_given_beyond_ra_and_skip_2_should_make_start_equals_2_length_equals_0(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""ra");

 str->start +=3;

 str->length-=3;

 stringSkip(str,2);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)283, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)284, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimLeft_given_hello_prefixed_with_2_space_should_remove_the_spaces(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""	hello	");

 stringTrimLeft(str);

 str->start ++;

 str->length--;

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)292, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)293, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimLeft_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""	\thello	");

 stringTrimLeft(str);

 str->start ++;

 str->length--;

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)301, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)302, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimRight_given_hello_prefixed_with_2_space_should_remove_the_spaces(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""	hello	");

 str->start ++;

 str->length--;

 stringTrimRight(str);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)311, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimRight_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""	hello\t	");

 str->start ++;

 str->length--;

 stringTrimRight(str);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)319, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)320, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrim_given_hello_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""\t \t hello \t \t\t");

 stringTrim(str);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)326, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)327, UNITY_DISPLAY_STYLE_INT);

}



void test_textNew_should_create_a_text_with_reference_of_1(void){

 Text *name = textNew("Jackson");

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((name->reference)), (((void *)0)), (_U_UINT)332, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("Jackson"), (const char*)(name->string), (((void *)0)), (_U_UINT)333);

}



void test_textNew_should_create_a_text_with_reference_of(void){

 Text *name = (Text *)"\x00\x00\x00\x80""Michael";

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((name->reference)), (((void *)0)), (_U_UINT)338, UNITY_DISPLAY_STYLE_INT);

}



void test_textAssign_dynamic_text_should_increase_reference_to_2(void){



 Text *name1 = textNew("Jackson");

 Text *name2 = textAssign(name1);

 UnityAssertEqualNumber((_U_SINT)(_UP)((name1)), (_U_SINT)(_UP)((name2)), (((void *)0)), (_U_UINT)345, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)346, UNITY_DISPLAY_STYLE_INT);



}
