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
	printf("-                                               -\n");
}

void test_stringNew_should_create_string_with_static_text(void){
	
	printf("-----Test for stringNew to create string from static text-----\n");
	
	Text *new=t"Exia";
	textDump(new);
	String *string = stringNew(new);
	stringDump(string);
	
	TEST_ASSERT_EQUAL(0X80000000,new->reference);
	TEST_ASSERT_EQUAL(0x01,string->reference);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_stringNew_should_create_string_with_dynamic_text(void){
	
	printf("-----Test for stringNew to create string from dynamic text-----\n");
	
	Text *new=textNew("00Raiser");
	textDump(new);
	String *string = stringNew(new);
	stringDump(string);
	
	TEST_ASSERT_EQUAL(0X02,new->reference);
	TEST_ASSERT_EQUAL(0x01,string->reference);
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
	
	TEST_ASSERT_EQUAL(5,name1->reference);
	TEST_ASSERT_EQUAL(5,name2->reference);
	TEST_ASSERT_EQUAL(5,name3->reference);
	TEST_ASSERT_EQUAL(5,name4->reference);
	TEST_ASSERT_EQUAL(5,name5->reference);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_textAssign_should__not_increase_text_reference(void){
	
	printf("-----Test for textAssign to not to increase text reference-----\n");
	
	Text *name1;
	Text *name2;
	
	
	name1=t"Dynames";
	printf("-----name1-----\n");
	textDump(name1);
	name2 = textAssign(name1);
	printf("-----name2-----\n");
	textDump(name2);
	
	TEST_ASSERT_EQUAL(0X80000000,name1->reference);
	TEST_ASSERT_EQUAL(0X80000000,name2->reference);
	TEST_ASSERT_EQUAL(name1->reference,name2->reference);
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
	
	TEST_ASSERT_EQUAL(0x05,string1->reference);
	TEST_ASSERT_EQUAL(0x05,string2->reference);
	TEST_ASSERT_EQUAL(0x05,string3->reference);
	TEST_ASSERT_EQUAL(0x05,string3->reference);
	TEST_ASSERT_EQUAL(0x05,string3->reference);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_stringAssign_should_not_increase_reference(void){
	
	printf("-----Test for stringAssign to not to increase reference-----\n");
	
	Text *name1 = t"Banshee";
	textDump(name1);
	String *string1 = stringNew(name1);
	stringDump(string1);
	String *string2 = stringAssign(string1);
	String *string3 = stringDel(string2);
	stringDump(string3);
	
	TEST_ASSERT_EQUAL(1,string1->reference);
	TEST_ASSERT_EQUAL(1,string2->reference);
	TEST_ASSERT_EQUAL(1,string3->reference);
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
	
	TEST_ASSERT_EQUAL(3,name1->reference);
	
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_textDelete_should_not_delete_reference_for_static_text(void){
	
	printf("-----Test for textDelete should not delete reference on static text -----\n");
	Text *name1;
	
	name1=t"Legend";
	textDump(name1);
	
	Text *name2 = textDel(name1);
	textDump(name2);
	
	TEST_ASSERT_EQUAL(0x80000000,name1->reference);
	
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
	
	TEST_ASSERT_EQUAL(3,string1->reference);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_stringDelete_should__not_delete_reference_for_text(void)
{	
	printf("-----Test for stringDelete should not delete reference for text-----\n");
	Text * name1=t"QanTa";
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
	
	TEST_ASSERT_EQUAL(3,string1->reference);
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
	
	TEST_ASSERT_EQUAL(NULL,name10);
	
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
	TEST_ASSERT_EQUAL(NULL,string10);
	
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_text_explore(void){
	
	printf("-----------------------------\n");
	printf("-----Test for textExplore-----\n");
	
	Text *name1 = t"James ho";
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
	String *str = stringNew(t"Hello");
	str->start ++;
	str->length--;
	stringSkip(str,2);
	stringDump(str);
	TEST_ASSERT_EQUAL(2,str->start);
	TEST_ASSERT_EQUAL(4,str->length);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_stringSkip_given_gundam_and_skip_4_should_become_am(){
	printf("-----Test for stringSkip on gundam and become am-----\n");
	String *str = stringNew(t"gundam");
	str->start ++;
	str->length--;
	stringSkip(str,4);
	stringDump(str);
	TEST_ASSERT_EQUAL(4,str->start);
	TEST_ASSERT_EQUAL(5,str->length);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_stringSkip_given_gundam_and_skip_6_should_return_null(){
	printf("-----Test for stringSkip on gundam and return null-----\n");
	String *str = stringNew(t"gundam");
	str->start ++;
	str->length--;
	stringSkip(str,6);
	stringDump(str);
	TEST_ASSERT_EQUAL(6,str->start);
	TEST_ASSERT_EQUAL(0,str->length);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_stringSkip_given_beyond_ra_and_skip_2_should_make_start_equals_2_length_equals_0(){
	printf("-----Test for stringSkip beyond ra for start = 2 and length = 0---\n");
	String *str = stringNew(t"ra");
	str->start +=3;
	str->length-=3;
	stringSkip(str,2);
	stringDump(str);
	TEST_ASSERT_EQUAL(2,str->start);
	TEST_ASSERT_EQUAL(0,str->length);
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
	TEST_ASSERT_EQUAL(3,string1->start);
	TEST_ASSERT_EQUAL(8,string1->length);
	printf("-                                               -\n");
	printf("-                                               -\n");
}

void test_stringTrimLeft_given_Saviour_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){
	printf("-----Test for stringTrimLeft Saviour to remove the space and tab -----\n");
	String *str = stringNew(t"	\tSaviour	");
	stringTrimLeft(str);
	stringDump(str);
	str->start ++;
	str->length--;
	TEST_ASSERT_EQUAL(3,str->start);
	TEST_ASSERT_EQUAL(9,str->length);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_stringTrimRight_given_Comet_postfixed_with_3_space_should_remove_the_spaces(){
	printf("-----Test for stringTrimRight Comet to remove the spaces -----\n");
	String *str = stringNew(t"  Comet \t   ");
	str->start ++;
	str->length--;
	stringTrimRight(str);
	stringDump(str);
	TEST_ASSERT_EQUAL(1,str->start);
	TEST_ASSERT_EQUAL(11,str->length);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_stringTrimRight_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){
	
	printf("-----Test for stringTrimRight Hello to remove the spaces and tab -----\n");
	String *str = stringNew(t"	hello\t	");
	str->start ++;
	str->length--;
	stringTrimRight(str);
	stringDump(str);
	TEST_ASSERT_EQUAL(1,str->start);
	TEST_ASSERT_EQUAL(7,str->length);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_stringTrim_given_hello_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){
	
	printf("-----Test for stringTrim both sides Hello to remove the spaces and tab -----\n");
	String *str = stringNew(t"\t \t \t hello \t \t ");
	stringTrim(str);
	stringDump(str);
	TEST_ASSERT_EQUAL(6,str->start);
	TEST_ASSERT_EQUAL(16,str->length);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_stringTrim_given_Kamaguchi_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){
	
	printf("-----Test for stringTrim both sides Hello to remove the spaces and tab -----\n");
	String *str = stringNew(t"\t \t Kamguchi \t \t\t");
	stringTrim(str);
	stringDump(str);
	TEST_ASSERT_EQUAL(4,str->start);
	TEST_ASSERT_EQUAL(17,str->length);
	printf("-                                               -\n");
	printf("-                                               -\n");

}

void test_stringTrim_given_Ferraro_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){
	
	printf("-----Test for stringTrim both sides Hello to remove the spaces and tab -----\n");
	String *str = stringNew(t"\t \t \t Ferrari \t \t\t");
	stringTrim(str);
	stringDump(str);
	TEST_ASSERT_EQUAL(6,str->start);
	TEST_ASSERT_EQUAL(18,str->length);
	printf("-                                               -\n");
	printf("-                                               -\n");

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



