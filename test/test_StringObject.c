#include "unity.h"
#include "StringObject.h"


typedef struct FakeText{
	uint32 reference;
	char string[80];
}FakeText;

void setUp(void){}

void tearDown(void){}

#define t (Text *)"\x00\x00\x00\x80"



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
	
	TEST_ASSERT_EQUAL(0x01,name->reference);
	
}

void test_stringNew_should_return_string(void){
	
	printf("-----------------------------\n");
	printf("-----Test for stringNew-----\n");
	
	Text *new=textNew("Jason");
	textDump(new);
	String *string = stringNew(new);
	stringDump(string);
	
	TEST_ASSERT_EQUAL(0x01,string->reference);
	TEST_ASSERT_EQUAL(0x02,new->reference);
}

void test_textAssign(void){
	
	printf("-----------------------------\n");
	printf("-----Test for textAssign-----\n");
	
	Text *name1 = t"jason";
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
	
	TEST_ASSERT_EQUAL(0X80000000,name1->reference);
	TEST_ASSERT_EQUAL(0x02,name2->reference);
	TEST_ASSERT_EQUAL(0x02,name3->reference);
	TEST_ASSERT_EQUAL(name2->reference,name3->reference);
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
	
	TEST_ASSERT_EQUAL(0x02,string2->reference);
	TEST_ASSERT_EQUAL(0x02,string1->reference);
	TEST_ASSERT_EQUAL(0x02,name1->reference);
	
}

void test_textDelete_should_delete_and_left_only_1(void){
	
	printf("-----------------------------\n");
	printf("-----Test for textDelete-----\n");
	Text *name1;
	Text *name2;
	Text *name3;
	name1=t"Jason";
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
	
	TEST_ASSERT_EQUAL(0x01,name3->reference);
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
	TEST_ASSERT_EQUAL(0x01,string1->reference);
}

void test_textDelete_should_delete_all_text_reference_and_return_null(void){

	printf("---------------------------------------------------------\n");
	printf("-----Test for textDelete and return NULL at the end -----\n");
	Text *name1;
	Text *name2;
	Text *name3;
	name1=t"Jason";
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
	
	TEST_ASSERT_EQUAL(NULL,name2);
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
	
	TEST_ASSERT_EQUAL(NULL,string2);
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


void test_stringSkip_given_Hello_and_skip_2_should_become_lo(){
	String *str = stringNew(t"Hello");
	str->start ++;
	str->length--;
	stringSkip(str,2);
	TEST_ASSERT_EQUAL(2,str->start);
	TEST_ASSERT_EQUAL(4,str->length);
}

void test_stringSkip_given_beyond_ra_and_skip_2_should_make_start_equals_2_length_equals_0(){
	String *str = stringNew(t"ra");
	str->start +=3;
	str->length-=3;
	stringSkip(str,2);
	TEST_ASSERT_EQUAL(2,str->start);
	TEST_ASSERT_EQUAL(0,str->length);
}

void test_stringTrimLeft_given_hello_prefixed_with_2_space_should_remove_the_spaces(){
	String *str = stringNew(t"	hello	");
	stringTrimLeft(str);
	str->start ++;
	str->length--;
	TEST_ASSERT_EQUAL(2,str->start);
	TEST_ASSERT_EQUAL(6,str->length);
}

void test_stringTrimLeft_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){
	String *str = stringNew(t"	\thello	");
	stringTrimLeft(str);
	str->start ++;
	str->length--;
	TEST_ASSERT_EQUAL(3,str->start);
	TEST_ASSERT_EQUAL(7,str->length);
}

void test_stringTrimRight_given_hello_prefixed_with_2_space_should_remove_the_spaces(){
	String *str = stringNew(t"	hello	");
	str->start ++;
	str->length--;
	stringTrimRight(str);
	TEST_ASSERT_EQUAL(1,str->start);
	TEST_ASSERT_EQUAL(6,str->length);
}

void test_stringTrimRight_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){
	String *str = stringNew(t"	hello\t	");
	str->start ++;
	str->length--;
	stringTrimRight(str);
	TEST_ASSERT_EQUAL(1,str->start);
	TEST_ASSERT_EQUAL(7,str->length);
}

void test_stringTrim_given_hello_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){
	String *str = stringNew(t"\t \t hello \t \t\t");
	stringTrim(str);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(14,str->length);
}

void test_textNew_should_create_a_text_with_reference_of_1(void){
	Text *name = textNew("Jackson");
	TEST_ASSERT_EQUAL(1,name->reference);
	TEST_ASSERT_EQUAL_STRING("Jackson",name->string);
}

void test_textNew_should_create_a_text_with_reference_of(void){
	Text *name = t"Michael";
	TEST_ASSERT_EQUAL(0x80000000,name->reference);
}

void test_textAssign_dynamic_text_should_increase_reference_to_2(void){

	Text *name1 = textNew("Jackson");
	Text *name2 = textAssign(name1);
	TEST_ASSERT_EQUAL_PTR(name1,name2);
	TEST_ASSERT_EQUAL(2,name1->reference);
	
}



