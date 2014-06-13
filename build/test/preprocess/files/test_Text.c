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



 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");

 printf("-                                               -\n");

}



void test_textNew_should_create_a_dynamic_text(void){





 printf("-----Test for textNew to make a dynamic text-----\n");



 Text *text;



 text=textNew("Justice");

 textDump(text);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_INT);

 printf("-                                               -\n");



}



void test_textAssign_should_increase_text_reference(void){









 Text *name1;

 Text *name2;

 Text *name3;

 Text *name4;

 Text *name5;



 name1= textNew("Arios");



 name2 = textAssign(name1);



 name3 = textAssign(name2);



 name4 = textAssign(name3);



 name5 = textAssign(name4);





 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((name3->reference)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((name4->reference)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((name5->reference)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);







}



void test_textAssign_should__not_increase_text_reference(void){







 Text *name1;

 Text *name2;





 name1=(Text *)"\x00\x00\x00\x80""Dynames";

 printf("-----name1-----\n");



 name2 = textAssign(name1);

 printf("-----name2-----\n");





 UnityAssertEqualNumber((_U_SINT)((0X80000000)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0X80000000)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((name1->reference)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);







}



void test_textDelete_should_delete_reference_for_dynamic_text(void){





 Text *name1;

 Text *name2;

 Text *name3;

 Text *name4;

 Text *name5;

 Text *name6;

 Text *name7;



 name1=textNew("Destiny");





 name2= textAssign(name1);





 name3=textAssign(name2);





 name4=textAssign(name3);





 name5=textAssign(name4);





 name6=textDel(name1);





 name7=textDel(name1);





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);









}



void test_textDelete_should_not_delete_reference_for_static_text(void){





 Text *name1;



 name1=(Text *)"\x00\x00\x00\x80""Legend";





 Text *name2 = textDel(name1);





 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);









}



void test_textDelete_should_delete_all_reference_and_return_null(void){







 Text *name1=textNew("Impulse");





 Text *name2= textAssign(name1);





 Text *name3=textAssign(name2);





 Text *name4=textAssign(name3);





 Text *name5=textAssign(name4);





 Text *name6=textDel(name1);





 Text *name7=textDel(name1);





 Text *name8=textDel(name1);





 Text *name9=textDel(name1);





 Text *name10=textDel(name1);







 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((name10)), (((void *)0)), (_U_UINT)204, UNITY_DISPLAY_STYLE_INT);









}



void test_text_explore(void){









 Text *name1 = (Text *)"\x00\x00\x00\x80""James ho";

 Text *name2;

 Text *name3;

 Text *msg;

 String *str1;

 String *str2;



 name2 = textNew("jason");



 printf("---------\n");

 name3 =textAssign(name2);





 name2 =textDel(name2);





 name3 = textDel(name3);







 name1 = textDel(name1);









 msg=textNew("hello");





 str1=stringNew(msg);





 str2=stringAssign(str1);







 str2=stringDel(str2);







 msg=textDel(msg);





}



void test_textNew_should_create_a_text_with_reference_of_1(void){

 Text *name = textNew("Jackson");

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((name->reference)), (((void *)0)), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("Jackson"), (const char*)(name->string), (((void *)0)), (_U_UINT)263);



}



void test_textAssign_dynamic_text_should_increase_reference_to_2(void){



 Text *name1 = textNew("Jackson");

 Text *name2 = textAssign(name1);

 UnityAssertEqualNumber((_U_SINT)(_UP)((name1)), (_U_SINT)(_UP)((name2)), (((void *)0)), (_U_UINT)271, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)272, UNITY_DISPLAY_STYLE_INT);



}
