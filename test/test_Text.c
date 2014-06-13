#include "unity.h"
#include "StringObject.h"
#include "Text.h"
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
	
	text=t"Freedom";
	textDump(text);
	
	TEST_ASSERT_EQUAL(0x80000000,text->reference);
	printf("-                                               -\n");
	printf("-                                               -\n");
}

void test_textNew_should_create_a_dynamic_text(void){
	
	
	printf("-----Test for textNew to make a dynamic text-----\n");
	
	Text *text;
	
	text=textNew("Justice");
	textDump(text);
	
	TEST_ASSERT_EQUAL(1,text->reference);
	printf("-                                               -\n");
	
}

void test_textAssign_should_increase_text_reference(void){
	
	//printf("-----Test for textAssign to increase text reference-----\n");
	
	
	Text *name1;
	Text *name2;
	Text *name3;
	Text *name4;
	Text *name5;
	
	name1= textNew("Arios");
	//textDump(name1);
	name2 = textAssign(name1);
	//textDump(name2);
	name3 = textAssign(name2);
	//textDump(name3);
	name4 = textAssign(name3);
	//textDump(name4);
	name5 = textAssign(name4);
	//textDump(name5);
	
	TEST_ASSERT_EQUAL(5,name1->reference);
	TEST_ASSERT_EQUAL(5,name2->reference);
	TEST_ASSERT_EQUAL(5,name3->reference);
	TEST_ASSERT_EQUAL(5,name4->reference);
	TEST_ASSERT_EQUAL(5,name5->reference);
	
	//printf("-                                               -\n");

}

void test_textAssign_should__not_increase_text_reference(void){
	
	//printf("-----Test for textAssign to not to increase text reference-----\n");
	
	Text *name1;
	Text *name2;
	
	
	name1=t"Dynames";
	printf("-----name1-----\n");
	//textDump(name1);
	name2 = textAssign(name1);
	printf("-----name2-----\n");
	//textDump(name2);
	
	TEST_ASSERT_EQUAL(0X80000000,name1->reference);
	TEST_ASSERT_EQUAL(0X80000000,name2->reference);
	TEST_ASSERT_EQUAL(name1->reference,name2->reference);
	
	//printf("-                                               -\n");

}

void test_textDelete_should_delete_reference_for_dynamic_text(void){
	
	//printf("-----Test for textDelete should delete reference on dynamic text -----\n");
	Text *name1;
	Text *name2;
	Text *name3;
	Text *name4;
	Text *name5;
	Text *name6;
	Text *name7;
	
	name1=textNew("Destiny");
	//textDump(name1);
	
	name2= textAssign(name1);
	//textDump(name2);
	
	name3=textAssign(name2);
	//textDump(name3);
	
	name4=textAssign(name3);
	//textDump(name4);
	
	name5=textAssign(name4);
	//textDump(name5);
	
	name6=textDel(name1);
	//textDump(name6);
	
	name7=textDel(name1);
	//textDump(name7);
	
	TEST_ASSERT_EQUAL(3,name1->reference);
	
	//printf("-                                               -\n");
	

}

void test_textDelete_should_not_delete_reference_for_static_text(void){
	
	//printf("-----Test for textDelete should not delete reference on static text -----\n");
	Text *name1;
	
	name1=t"Legend";
	//textDump(name1);
	
	Text *name2 = textDel(name1);
	//textDump(name2);
	
	TEST_ASSERT_EQUAL(0x80000000,name1->reference);
	
	
	//printf("-                                               -\n");

}

void test_textDelete_should_delete_all_reference_and_return_null(void){
	
	//printf("-----Test for textDelete should delete all reference and return NULL -----\n");
	
	Text *name1=textNew("Impulse");
	//textDump(name1);
	
	Text *name2= textAssign(name1);
	//textDump(name2);
	
	Text *name3=textAssign(name2);
	//textDump(name3);
	
	Text *name4=textAssign(name3);
	//textDump(name4);
	
	Text *name5=textAssign(name4);
	//textDump(name5);
	
	Text *name6=textDel(name1);
	//textDump(name6);
	
	Text *name7=textDel(name1);
	//textDump(name7);
	
	Text *name8=textDel(name1);
	//textDump(name8);
	
	Text *name9=textDel(name1);
	//textDump(name9);
	
	Text *name10=textDel(name1);
	//textDump(name10);
	//printf(" \n");
	
	TEST_ASSERT_EQUAL(NULL,name10);
	
	
	//printf("-                                               -\n");

}

void test_text_explore(void){
	
	
	//printf("-----Test for textExplore-----\n");
	
	Text *name1 = t"James ho";
	Text *name2;
	Text *name3;
	Text *msg;
	String *str1;
	String *str2;
	//textDump(name1);
	name2 = textNew("jason");
	//textDump(name2);
	printf("---------\n");
	name3 =textAssign(name2);
	//textDump(name2);
	//textDump(name3);
	name2 =textDel(name2);
	//textDump(name2);
	//textDump(name3);
	name3 = textDel(name3);
	//textDump(name3);
	//printf("---------\n");
	//printf("name3: %p\n",name3);
	name1 = textDel(name1);
	//textDump(name1);
	
	//printf("xxxxxxxxx\n");
	//printf("xxxxxxxxx\n");
	msg=textNew("hello");
	//textDump(msg);
	//printf("xxxxxxxxx\n");
	str1=stringNew(msg);
	//stringDump(str1);
	//printf("xxxxxxxxx\n");
	str2=stringAssign(str1);
	//stringDump(str1);
	//stringDump(str2);
	//printf("---------\n");
	str2=stringDel(str2);
	//stringDump(str2);
	//textDump(msg);
	//printf("---------\n");
	msg=textDel(msg);
	//textDump(msg);
	//printf("-----------------------------\n");
}

void test_textNew_should_create_a_text_with_reference_of_1(void){
	Text *name = textNew("Jackson");
	TEST_ASSERT_EQUAL(1,name->reference);
	TEST_ASSERT_EQUAL_STRING("Jackson",name->string);
	
}

void test_textAssign_dynamic_text_should_increase_reference_to_2(void){

	Text *name1 = textNew("Jackson");
	Text *name2 = textAssign(name1);
	TEST_ASSERT_EQUAL_PTR(name1,name2);
	TEST_ASSERT_EQUAL(2,name1->reference);
	
}