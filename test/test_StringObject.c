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
	
	//printf("-----Test for stringNew to create string from static text-----\n");
	
	Text *new=t"Exia";
	//textDump(new);
	String *string = stringNew(new);
	//stringDump(string);
	
	TEST_ASSERT_EQUAL(0X80000000,new->reference);
	TEST_ASSERT_EQUAL(0x01,string->reference);
	
	//printf("-                                               -\n");

}

void test_stringNew_should_create_string_with_dynamic_text(void){
	
	//printf("-----Test for stringNew to create string from dynamic text-----\n");
	
	Text *new=textNew("00Raiser");
	//textDump(new);
	String *string = stringNew(new);
	//stringDump(string);
	
	TEST_ASSERT_EQUAL(0X02,new->reference);
	TEST_ASSERT_EQUAL(0x01,string->reference);
	
	//printf("-                                               -\n");

}



void test_stringAssign_should_increase_reference(void){
	
	
	//printf("-----Test for stringAssign to increase reference-----\n");
	
	Text *name1 = textNew("Unicorn");
	//textDump(name1);
	String *string1 = stringNew(name1);
	String *string2 = stringAssign(string1);
	//stringDump(string2);
	String *string3 = stringAssign(string2);
	//stringDump(string3);
	String *string4 = stringAssign(string3);
	//stringDump(string4);
	String *string5 = stringAssign(string4);
	//stringDump(string5);
	
	TEST_ASSERT_EQUAL(0x05,string1->reference);
	TEST_ASSERT_EQUAL(0x05,string2->reference);
	TEST_ASSERT_EQUAL(0x05,string3->reference);
	TEST_ASSERT_EQUAL(0x05,string3->reference);
	TEST_ASSERT_EQUAL(0x05,string3->reference);
	
	//printf("-                                               -\n");

}

void test_stringAssign_should_not_increase_reference(void){
	
	//printf("-----Test for stringAssign to not to increase reference-----\n");
	
	Text *name1 = t"Banshee";
	//textDump(name1);
	String *string1 = stringNew(name1);
	//stringDump(string1);
	String *string2 = stringAssign(string1);
	String *string3 = stringDel(string2);
	//stringDump(string3);
	
	TEST_ASSERT_EQUAL(1,string1->reference);
	TEST_ASSERT_EQUAL(1,string2->reference);
	TEST_ASSERT_EQUAL(1,string3->reference);
	
	//printf("-                                               -\n");

}


void test_stringDelete_should_delete_reference(void)
{	
	//printf("-----Test for stringDelete should delete reference-----\n");
	Text * name1=textNew("Strike");
	//textDump(name1);
	
	String *string1=stringNew(name1);
	//stringDump(string1);
	
	String *string2= stringAssign(string1);
	//stringDump(string2);
	
	String *string3= stringAssign(string2);
	//stringDump(string3);
	
	String *string4= stringAssign(string3);
	//stringDump(string4);
	
	String *string5= stringAssign(string4);
	stringDump(string5);
	
	String *string6=stringDel(string1);
	//stringDump(string6);
	
	String *string7= stringDel(string1);
	//stringDump(string7);
	
	TEST_ASSERT_EQUAL(3,string1->reference);
	
	//printf("-                                               -\n");

}

void test_stringDelete_should_not_delete_reference_for_text(void)
{	
	printf("-----Test for stringDelete should not delete reference for text-----\n");
	Text * name1=t"QanTa";
	//textDump(name1);
	
	String *string1=stringNew(name1);
	//stringDump(string1);
	
	String *string2= stringAssign(string1);
	//stringDump(string2);
	
	String *string3= stringAssign(string2);
	//stringDump(string3);
	
	String *string4= stringAssign(string3);
	//stringDump(string4);
	
	String *string5= stringAssign(string4);
	//stringDump(string5);
	
	String *string6=stringDel(string1);
	//stringDump(string6);
	
	String *string7= stringDel(string1);
	//stringDump(string7);
	
	TEST_ASSERT_EQUAL(3,string1->reference);
	
	//printf("-                                               -\n");

}


void test_stringDelete_should_delete_all_reference_and_return_null(void)
{	
	//printf("-----Test for stringDelete should delete all reference-----\n");
	Text * name1=textNew("Infinite");
	textDump(name1);
	
	String *string1=stringNew(name1);
	//stringDump(string1);
	
	String *string2= stringAssign(string1);
	//stringDump(string2);
	
	String *string3= stringAssign(string2);
	//stringDump(string3);
	
	String *string4= stringAssign(string3);
	//stringDump(string4);
	
	String *string5= stringAssign(string4);
	//stringDump(string5);
	
	String *string6=stringDel(string1);
	//stringDump(string6);
	
	String *string7= stringDel(string1);
	//stringDump(string7);
	
	String *string8= stringDel(string1);
	//stringDump(string8);
	
	String *string9= stringDel(string1);
	//stringDump(string9);
	
	String *string10= stringDel(string1);
	//stringDump(string10);
	//printf("\n");
	TEST_ASSERT_EQUAL(NULL,string10);
	
	
	//printf("-                                               -\n");

}


void test_stringSkip_given_Hello_and_skip_2_should_become_llo(){
	//printf("-----Test for stringSkip on hello and become llo-----\n");
	String *str = stringNew(t"Hello");
	str->start ++;
	str->length--;
	stringSkip(str,2);
	//stringDump(str);
	TEST_ASSERT_EQUAL(2,str->start);
	TEST_ASSERT_EQUAL(4,str->length);
	//printf("-                                               -\n");
	//printf("-                                               -\n");

}

void test_stringSkip_given_gundam_and_skip_4_should_become_am(){
	//printf("-----Test for stringSkip on gundam and become am-----\n");
	String *str = stringNew(t"gundam");
	str->start ++;
	str->length--;
	stringSkip(str,4);
	//stringDump(str);
	TEST_ASSERT_EQUAL(4,str->start);
	TEST_ASSERT_EQUAL(5,str->length);
	//printf("-                                               -\n");
	//printf("-                                               -\n");

}

void test_stringSkip_given_gundam_and_skip_6_should_return_null(){
	//printf("-----Test for stringSkip on gundam and return null-----\n");
	String *str = stringNew(t"gundam");
	str->start ++;
	str->length--;
	stringSkip(str,6);
	//stringDump(str);
	TEST_ASSERT_EQUAL(6,str->start);
	TEST_ASSERT_EQUAL(0,str->length);
	//printf("-                                               -\n");
	//printf("-                                               -\n");

}

void test_stringSkip_given_beyond_ra_and_skip_2_should_make_start_equals_2_length_equals_0(){
	//printf("-----Test for stringSkip beyond ra for start = 2 and length = 0---\n");
	String *str = stringNew(t"ra");
	str->start +=3;
	str->length-=3;
	stringSkip(str,2);
	//stringDump(str);
	TEST_ASSERT_EQUAL(2,str->start);
	TEST_ASSERT_EQUAL(0,str->length);
	//printf("-                                               -\n");
	//printf("-                                               -\n");

}

void test_stringTrimLeft_given_Amazing_prefixed_with_2_space_should_remove_the_spaces(){
	//printf("-----Test for stringTrimLeft Amazing to remove the space -----\n");
	Text *new=textNew("  Amazing");
	String *string1 = stringNew(new);
	stringTrimLeft(string1);
	//stringDump(string1);
	string1->start ++;
	string1->length--;
	TEST_ASSERT_EQUAL(3,string1->start);
	TEST_ASSERT_EQUAL(8,string1->length);
	//printf("-                                               -\n");
	//printf("-                                               -\n");
}

void test_stringTrimLeft_given_Saviour_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){
	//printf("-----Test for stringTrimLeft Saviour to remove the space and tab -----\n");
	String *str = stringNew(t"	\tSaviour	");
	stringTrimLeft(str);
	//stringDump(str);
	str->start ++;
	str->length--;
	TEST_ASSERT_EQUAL(3,str->start);
	TEST_ASSERT_EQUAL(9,str->length);
	//printf("-                                               -\n");
	//printf("-                                               -\n");

}

void test_stringTrimRight_given_Comet_postfixed_with_3_space_should_remove_the_spaces(){
	//printf("-----Test for stringTrimRight Comet to remove the spaces -----\n");
	String *str = stringNew(t"  Comet \t   ");
	str->start ++;
	str->length--;
	stringTrimRight(str);
	//stringDump(str);
	TEST_ASSERT_EQUAL(1,str->start);
	TEST_ASSERT_EQUAL(11,str->length);
	//printf("-                                               -\n");
	//printf("-                                               -\n");

}

void test_stringTrimRight_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(){
	
	//printf("-----Test for stringTrimRight Hello to remove the spaces and tab -----\n");
	String *str = stringNew(t"	hello\t	");
	str->start ++;
	str->length--;
	stringTrimRight(str);
	//stringDump(str);
	TEST_ASSERT_EQUAL(1,str->start);
	TEST_ASSERT_EQUAL(7,str->length);
	//printf("-                                               -\n");
	//printf("-                                               -\n");

}

void test_stringTrim_given_hello_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){
	
	//printf("-----Test for stringTrim both sides Hello to remove the spaces and tab -----\n");
	String *str = stringNew(t"\t \t \t hello \t \t ");
	stringTrim(str);
	//stringDump(str);
	TEST_ASSERT_EQUAL(6,str->start);
	TEST_ASSERT_EQUAL(16,str->length);
	//printf("-                                               -\n");
	//printf("-                                               -\n");

}

void test_stringTrim_given_Kamaguchi_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){
	
	//printf("-----Test for stringTrim both sides Hello to remove the spaces and tab -----\n");
	String *str = stringNew(t"\t \t Kamguchi \t \t\t");
	stringTrim(str);
	//stringDump(str);
	TEST_ASSERT_EQUAL(4,str->start);
	TEST_ASSERT_EQUAL(17,str->length);
	//printf("-                                               -\n");
	//printf("-                                               -\n");

}

void test_stringTrim_given_Ferraro_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(){
	
	//printf("-----Test for stringTrim both sides Hello to remove the spaces and tab -----\n");
	String *str = stringNew(t"\t \t \t Ferrari \t \t\t");
	stringTrim(str);
	//stringDump(str);
	TEST_ASSERT_EQUAL(6,str->start);
	TEST_ASSERT_EQUAL(18,str->length);
	//printf("-                                               -\n");
	//printf("-                                               -\n");

}



void test_stringRemove_should_remove_first_char_within_a_string(void){
	//printf("-----Test for stringRemove should remove k in knight and return k-----\n");
	Text * name1=textNew("knight");
	//textDump(name1);
	
	String *string1=stringNew(name1);
	//stringDump(string1);
	
	stringRemoveChar(string1);
	//stringDump(string1);
	
	TEST_ASSERT_EQUAL('k',string1->text->string[0]);
	//printf("-                                               -\n");
	//printf("-                                               -\n");
}

void test_stringRemove_should_remove_three_char_within_a_string(void){
	//printf("-----Test for stringRemove should remove kni in knight and return kni-----\n");
	Text * name1=textNew("knight");
	//textDump(name1);
	
	String *string1=stringNew(name1);
	//stringDump(string1);
	
	stringRemoveChar(string1);
	
	stringRemoveChar(string1);
	
	stringRemoveChar(string1);
	//stringDump(string1);
	
	TEST_ASSERT_EQUAL('k',string1->text->string[0]);
	TEST_ASSERT_EQUAL('n',string1->text->string[1]);
	TEST_ASSERT_EQUAL('i',string1->text->string[2]);
	//printf("-                                               -\n");
	//printf("-                                               -\n");
}

void test_stringRemove_should_remove_five_char_within_a_string(void){
	//printf("-----Test for stringRemove should remove 5 character in knight and return knigh-----\n");
	Text * name1=textNew("knight");
	//textDump(name1);
	
	String *string1=stringNew(name1);
	//stringDump(string1);
	
	stringRemoveChar(string1);
	
	stringRemoveChar(string1);
	
	stringRemoveChar(string1);
	
	stringRemoveChar(string1);
	
	stringRemoveChar(string1);
	//stringDump(string1);
	
	TEST_ASSERT_EQUAL('k',string1->text->string[0]);
	TEST_ASSERT_EQUAL('n',string1->text->string[1]);
	TEST_ASSERT_EQUAL('i',string1->text->string[2]);
	TEST_ASSERT_EQUAL('g',string1->text->string[3]);
	TEST_ASSERT_EQUAL('h',string1->text->string[4]);
	
	//printf("-                                               -\n");
	//printf("-                                               -\n");
}

void test_stringRemove_should_remove_all_char_within_a_string(void){
	//printf("-----Test for stringRemove should remove all character in knight and return -1 -----\n");
	
	char a;
	Text * name1=textNew("knight");
	//textDump(name1);
	
	String *string1=stringNew(name1);
	//stringDump(string1);
	
	stringRemoveChar(string1);
	
	stringRemoveChar(string1);
	
	stringRemoveChar(string1);
	
	stringRemoveChar(string1);
	
	stringRemoveChar(string1);
	
	stringRemoveChar(string1);
	
	a=stringRemoveChar(string1);
	//stringDump(string1);
	
	TEST_ASSERT_EQUAL('k',string1->text->string[0]);
	TEST_ASSERT_EQUAL('n',string1->text->string[1]);
	TEST_ASSERT_EQUAL('i',string1->text->string[2]);
	TEST_ASSERT_EQUAL('g',string1->text->string[3]);
	TEST_ASSERT_EQUAL('h',string1->text->string[4]);
	TEST_ASSERT_EQUAL('t',string1->text->string[5]);
	TEST_ASSERT_EQUAL(-1,a);
	//printf("-                                               -\n");
	//printf("-                                               -\n");
}

void test_stringLength_should_get_the_correct_length(void){
	//printf("-----Test for stringLength should get the correct length-----\n");
	
	int input ;
	Text * name1=textNew("pikachu");
	
	String *string1=stringNew(name1);
	
	input = stringLength(string1);
	//stringDump(string1);
	
	TEST_ASSERT_EQUAL(7,input);
	//printf("-                                               -\n");
	//printf("-                                               -\n");
}

void test_stringLength_should_get_the_correct_length2(void){
	//printf("-----Test for stringLength should get the correct length with space -----\n");
	
	int input ;
	Text * name1=textNew("     pikachu");
	
	String *string1=stringNew(name1);
	
	input = stringLength(string1);
	//stringDump(string1);
	
	TEST_ASSERT_EQUAL(12,input);
	//printf("-                                               -\n");
	//printf("-                                               -\n");
}

void test_stringLength_should_get_the_correct_length3(void){
	//printf("-----Test for stringLength should get the correct length with space and tab-----\n");
	
	int input ;
	Text * name1=textNew("     \t \t \t \t \t \t \t pikachu");
	
	String *string1=stringNew(name1);
	
	input = stringLength(string1);
	//stringDump(string1);
	
	TEST_ASSERT_EQUAL(26,input);
	//printf("-                                               -\n");
	//printf("-                                               -\n");
}

void test_stringRemoveWordNotContaining_should_test_input_and_start_with_alphabet(void){
	printf("-----Test for stringRemoveWordNotContaining -----\n");
	Text * name1=t"Bulldog";
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
	TEST_ASSERT_EQUAL('a',string2->text->string[string2->start]);
	TEST_ASSERT_EQUAL(0,string2->start);
	TEST_ASSERT_EQUAL(3,string2->length);
	
	TEST_ASSERT_EQUAL(3,string1->start);
	TEST_ASSERT_EQUAL(2,string1->length);
	printf("-                                               -\n");
}

void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet2(void){
	
	Text *name1=textNew("1234ABCD56");
	String *string1=stringNew(name1);
	
	String *string2 = stringRemoveWordContaining(string1,"1234");
	stringDump(string2);
	stringDump(string1);
	
	TEST_ASSERT_EQUAL(0,string2->start);
	TEST_ASSERT_EQUAL(4,string2->length);
	
	TEST_ASSERT_EQUAL(4,string1->start);
	TEST_ASSERT_EQUAL(6,string1->length);
	printf("-                                               -\n");
}

void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet3(void){
	
	Text *name1=textNew("1234ABCD56");
	String *string1=stringNew(name1);
	
	String *string2 = stringRemoveWordContaining(string1,"2134");
	stringDump(string2);
	stringDump(string1);
	
	TEST_ASSERT_EQUAL(0,string2->start);
	TEST_ASSERT_EQUAL(4,string2->length);
	
	TEST_ASSERT_EQUAL(4,string1->start);
	TEST_ASSERT_EQUAL(6,string1->length);
	printf("-                                               -\n");
}

void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet4(void){
	
	Text *name1=textNew("1234ABCD56");
	String *string1=stringNew(name1);
	
	String *string2 = stringRemoveWordContaining(string1,"3214");
	stringDump(string2);
	stringDump(string1);
	
	TEST_ASSERT_EQUAL(0,string2->start);
	TEST_ASSERT_EQUAL(4,string2->length);
	
	TEST_ASSERT_EQUAL(4,string1->start);
	TEST_ASSERT_EQUAL(6,string1->length);
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
	
	TEST_ASSERT_EQUAL(1,input);
	TEST_ASSERT_EQUAL(5,string1->length);
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
	
	TEST_ASSERT_EQUAL(0,input);
	TEST_ASSERT_EQUAL(5,string1->length);
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
	
	TEST_ASSERT_EQUAL(0,input);
	TEST_ASSERT_EQUAL(6,string1->length);
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
	TEST_ASSERT_EQUAL(1,input);
	
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
	TEST_ASSERT_EQUAL(1,input);
	
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
	TEST_ASSERT_EQUAL(1,input);
	
	printf("-                                               -\n");
}

void test_stringCharAt_should_return_negative_one_if_startIndex_is_more_than_lenght(void)
{
	Text *name1=textNew("Hello");
	String *string1=stringNew(name1);
	string1->start=5;
	
	TEST_ASSERT_EQUAL(-1,stringCharAt(string1,0));
}

void test_stringCharAt_should_return_relative_character(void)
{
	int input;
	Text *name1=textNew("Hello");
	String *string1=stringNew(name1);
	string1->start=0;
	
	input = stringCharAt(string1,2);
	
	TEST_ASSERT_EQUAL('l',input);
}

void test_stringCharAt_should_return_relative_character2(void)
{
	int input;
	Text *name1=textNew("Hello");
	String *string1=stringNew(name1);
	string1->start=1;
	
	input = stringCharAt(string1,3);
	
	TEST_ASSERT_EQUAL('o',input);
}

void test_stringCharAtInSet_should_return_negative_one(void){
	int input;
	Text *name1=textNew("Hello");
	String *string1=stringNew(name1);
	string1->start=0;
	
	input = stringCharAtInSet(string1,1,"abcd");
	
	TEST_ASSERT_EQUAL(0,input);
}

void test_stringCharAtInSet_should_return_relative_character2(void){
	int input;
	Text *name1=textNew("Hello");
	String *string1=stringNew(name1);
	string1->start=0;
	
	input = stringCharAtInSet(string1,2,"abeld");
	
	TEST_ASSERT_EQUAL(1,input);
}

void test_stringCharAtInSet_should_return_relative_character3(void){
	int input;
	Text *name1=textNew("Hello");
	String *string1=stringNew(name1);
	string1->start=1;
	
	input = stringCharAtInSet(string1,3,"abo");
	
	TEST_ASSERT_EQUAL(1,input);
}

void test_stringSubstringInChar_Phone016_should_return_016(void){
	
	char *input;
	Text *name1=textNew("Phone016");
	String *string1=stringNew(name1);
	
	input = stringSubstringInChar(string1,5,3);
	printf("%s\n",input);
	
	TEST_ASSERT_EQUAL_STRING("016",input);
}

void test_stringSubstringInChar2_HandPhone016123_should_return_016(void){
	
	char *input;
	Text *name1=textNew("HandPhone016123");
	String *string1=stringNew(name1);
	
	input = stringSubstringInChar(string1,4,13);
	printf("%s\n",input);
	
	TEST_ASSERT_EQUAL_STRING("Phone016123",input);
}

void test_stringSubstringInChar_Phone016_should_return_NULL_if_length_of_string_exceeded(void){
	
	char *input;
	Text *name1=textNew("Phone016");
	String *string1=stringNew(name1);
	
	input = stringSubstringInChar(string1,1,10);
	printf("%s\n",input);
	
	TEST_ASSERT_EQUAL_STRING(" ",input);
}

void test_stringSubstringInText_Phone016_should_return_016(void){
	
	Text *name1=textNew("Phone016");
	String *string1=stringNew(name1);
	
	Text *stringText = stringSubstringInText(string1,5,3);
	
	
	TEST_ASSERT_EQUAL(1,stringText->reference);
	TEST_ASSERT_EQUAL_STRING("016",stringText->string);

}

void test_stringSubstringInText_should_get_substring(void){
	
	Text *name1=textNew("HandPhone016123");
	String *string1=stringNew(name1);
	
	Text *stringText = stringSubstringInText(string1,6,6);
	
	
	TEST_ASSERT_EQUAL(1,stringText->reference);
	TEST_ASSERT_EQUAL_STRING("one016",stringText->string);

}

void test_stringSubstringInText_should_return_empty_string(void){
	
	Text *name1=textNew("HandPhone016123");
	String *string1=stringNew(name1);
	
	Text *stringText = stringSubstringInText(string1,6,20);
	
	
	TEST_ASSERT_EQUAL(1,stringText->reference);
	TEST_ASSERT_EQUAL_STRING(" ",stringText->string);

}

void test_stringToInteger_should_return_integer_type(void){
	int input;
	Text *name1=textNew("HandPhone016123");
	String *string1=stringNew(name1);
	string1->start=10;
	string1->length=5;
	
	input=stringToInteger(string1);
	
	TEST_ASSERT_EQUAL(16123,input);
}

void test_stringToInteger_should_return_integer_type2(void){
	int input;
	Text *name1=textNew("Hand016123Phone");
	String *string1=stringNew(name1);
	string1->start=5;
	string1->length=4;
	
	input=stringToInteger(string1);
	
	TEST_ASSERT_EQUAL(1612,input);
}

void test_stringToInteger_should_return_integer_type3(void){
	int input;
	Text *name1=textNew("Hand016123Phone");
	String *string1=stringNew(name1);
	string1->start=5;
	string1->length=4;
	
	input=stringToInteger(string1);
	
	TEST_ASSERT_EQUAL(1612,input);
}

