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

 Text *name;



 name=textNew("testing");

 textDump(name);



 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((name->reference)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);



}



void test_textAssign(void){



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



 UnityAssertEqualNumber((_U_SINT)((0X80000000)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((name3->reference)), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((name2->reference)), (_U_SINT)((name3->reference)), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

}



void test_textDelete_should_delete_only_1(void){



 Text *name1;

 Text *name2;

 name1=textNew("jason");

 textDump(name1);

 printf("-----name1-----\n");

 name2= textAssign(name2);

 printf("-----name2------\n");

 textDump(name1);

 textDump(name2);

 printf("-----name3-----\n");

 name2=textDel(name2);

 textDump(name2);



 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

}



void test_textDelete_should_delete_all_text(void){



 Text *name1;

 Text *name2;



 name1= textNew("jas");

 textDump(name1);

 name2= textAssign(name1);

 textDump(name1);

 textDump(name2);

 name2=textDel(name2);

 textDump(name2);

 name1=textDel(name1);

 textDump(name1);



 if ((((name1)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)113);;};



}



void test_stringNew_should_return_string(void){



 Text *new=textNew("Jason");

 textDump(new);

 String *string = stringNew(new);

 stringDump(string);



 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);

}



void test_stringAssign_should_return_reference(void){



 Text *name1 = textNew("jason");

 textDump(name1);

 String *string1 = stringNew(name1);

 String *string2 = stringAssign(string1);

 stringDump(string1);

 stringDump(string2);



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string2->reference)), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)139, UNITY_DISPLAY_STYLE_INT);



}



void test_stringDelete_should_delete_only_one(void)

{

 Text *name1=textNew("jason");

 textDump(name1);



 String *string1 = stringNew(name1);

 stringDump(string1);



 String *string2 = stringAssign(string1);

 stringDump(string2);



 string1 = stringDel(string1);

 stringDump(string1);





 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);



}



void xtest_stringDelete_should_delete_all_return_null(void)

{

 Text *name1=textNew("jason");

 textDump(name1);



 String *string1 = stringNew(name1);

 stringDump(string1);



 String *string2 = stringAssign(string1);

 stringDump(string2);



 string1 = stringDel(string1);

 stringDump(string1);



 string2 = stringDel(string2);

 stringDump(string2);



 if ((((string2)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)179);;};



}





void test__text_explore(void){



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



}





void test_stringSkip_given_Hello_and_skip_2_should_become_lo(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""Hello");

 str->start ++;

 str->length--;

 stringSkip(str,2);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)236, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

}



void test_stringSkip_given_beyond_ra_and_skip_2_should_make_start_equals_2_length_equals_0(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""ra");

 str->start +=3;

 str->length-=3;

 stringSkip(str,2);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)245, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)246, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimLeft_given_hello_prefixed_with_2_space_should_remove_the_spaces(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""	hello	");

 stringTrimLeft(str);

 str->start ++;

 str->length--;

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)254, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)255, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimLeft_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""	\thello	");

 stringTrimLeft(str);

 str->start ++;

 str->length--;

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimRight_given_hello_prefixed_with_2_space_should_remove_the_spaces(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""	hello	");

 str->start ++;

 str->length--;

 stringTrimLeft(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)272, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)273, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimRight_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""	hello\t	");

 str->start ++;

 str->length--;

 stringTrimLeft(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)281, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)282, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrim_given_hello_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){

 String *str = stringNew((Text *)"\x00\x00\x00\x80""\t \t hello \t \t\t");

 stringTrimLeft(str);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)288, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)289, UNITY_DISPLAY_STYLE_INT);

}



void test_textNew_should_create_a_text_with_reference_of_1(void){

 Text *name = textNew("Jackson");

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((name->reference)), (((void *)0)), (_U_UINT)294, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("Jackson"), (const char*)(name->string), (((void *)0)), (_U_UINT)295);

}



void test_textNew_should_create_a_text_with_reference_of(void){

 Text *name = (Text *)"\x00\x00\x00\x80""Michael";

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((name->reference)), (((void *)0)), (_U_UINT)300, UNITY_DISPLAY_STYLE_INT);

}



void test_textAssign_dynamic_text_should_increate_reference_to_2(void){



 Text *name1 = textNew("Jackson");

 Text *name2 = textAssign(name1);

 UnityAssertEqualNumber((_U_SINT)(_UP)((name1)), (_U_SINT)(_UP)((name2)), (((void *)0)), (_U_UINT)307, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)308, UNITY_DISPLAY_STYLE_INT);



}
