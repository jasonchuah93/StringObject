/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      setUp(); \
      TestFunc(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_StringDump_explore(void);
extern void test_textDump_explore(void);
extern void test_textNew_should_create_a_static_text(void);
extern void test_textNew_should_create_a_dynamic_text(void);
extern void test_stringNew_should_create_string_with_static_text(void);
extern void test_stringNew_should_create_string_with_dynamic_text(void);
extern void test_textAssign_should_increase_text_reference(void);
extern void test_textAssign_should__not_increase_text_reference(void);
extern void test_stringAssign_should_increase_reference(void);
extern void test_stringAssign_should_not_increase_reference(void);
extern void test_textDelete_should_delete_reference_for_dynamic_text(void);
extern void test_textDelete_should_not_delete_reference_for_static_text(void);
extern void test_stringDelete_should_delete_reference(void);
extern void test_stringDelete_should_not_delete_reference_for_text(void);
extern void test_textDelete_should_delete_all_reference_and_return_null(void);
extern void test_stringDelete_should_delete_all_reference_and_return_null(void);
extern void test_text_explore(void);
extern void test_stringSkip_given_Hello_and_skip_2_should_become_llo(void);
extern void test_stringSkip_given_gundam_and_skip_4_should_become_am(void);
extern void test_stringSkip_given_gundam_and_skip_6_should_return_null(void);
extern void test_stringSkip_given_beyond_ra_and_skip_2_should_make_start_equals_2_length_equals_0(void);
extern void test_stringTrimLeft_given_Amazing_prefixed_with_2_space_should_remove_the_spaces(void);
extern void test_stringTrimLeft_given_Saviour_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(void);
extern void test_stringTrimRight_given_Comet_postfixed_with_3_space_should_remove_the_spaces(void);
extern void test_stringTrimRight_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab(void);
extern void test_stringTrim_given_hello_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(void);
extern void test_stringTrim_given_Kamaguchi_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(void);
extern void test_stringTrim_given_Ferraro_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab(void);
extern void test_textNew_should_create_a_text_with_reference_of_1(void);
extern void test_textAssign_dynamic_text_should_increase_reference_to_2(void);
extern void test_stringRemove_should_remove_first_char_within_a_string(void);
extern void test_stringRemove_should_remove_three_char_within_a_string(void);
extern void test_stringRemove_should_remove_five_char_within_a_string(void);
extern void test_stringRemove_should_remove_all_char_within_a_string(void);
extern void test_stringLength_should_get_the_correct_length(void);
extern void test_stringLength_should_get_the_correct_length2(void);
extern void test_stringLength_should_get_the_correct_length3(void);
extern void test_stringRemoveWordNotContaining_should_test_input__and_start_with_alphabet(void);
extern void test_stringRemoveWordNotContaining_should_test_input_and_start_with_alphabet2(void);
extern void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet1(void);
extern void test_stringIsEqual_should_result_both_string_is_same(void);
extern void test_stringIsEqual_should_result_both_string_the_start_is_different_but_length_is_same(void);
extern void test_stringIsEqualCaseSensitive_should_set_all_alphabet_to_lower_case(void);
extern void test_stringIsEqualCaseSensitive_should_set_all_alphabet_to_lower_case2(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_StringObject.c";
  UnityBegin();
  RUN_TEST(test_StringDump_explore, 14);
  RUN_TEST(test_textDump_explore, 35);
  RUN_TEST(test_textNew_should_create_a_static_text, 46);
  RUN_TEST(test_textNew_should_create_a_dynamic_text, 61);
  RUN_TEST(test_stringNew_should_create_string_with_static_text, 76);
  RUN_TEST(test_stringNew_should_create_string_with_dynamic_text, 92);
  RUN_TEST(test_textAssign_should_increase_text_reference, 108);
  RUN_TEST(test_textAssign_should__not_increase_text_reference, 140);
  RUN_TEST(test_stringAssign_should_increase_reference, 163);
  RUN_TEST(test_stringAssign_should_not_increase_reference, 190);
  RUN_TEST(test_textDelete_should_delete_reference_for_dynamic_text, 210);
  RUN_TEST(test_textDelete_should_not_delete_reference_for_static_text, 249);
  RUN_TEST(test_stringDelete_should_delete_reference, 267);
  RUN_TEST(test_stringDelete_should_not_delete_reference_for_text, 300);
  RUN_TEST(test_textDelete_should_delete_all_reference_and_return_null, 333);
  RUN_TEST(test_stringDelete_should_delete_all_reference_and_return_null, 375);
  RUN_TEST(test_text_explore, 418);
  RUN_TEST(test_stringSkip_given_Hello_and_skip_2_should_become_llo, 467);
  RUN_TEST(test_stringSkip_given_gundam_and_skip_4_should_become_am, 481);
  RUN_TEST(test_stringSkip_given_gundam_and_skip_6_should_return_null, 495);
  RUN_TEST(test_stringSkip_given_beyond_ra_and_skip_2_should_make_start_equals_2_length_equals_0, 509);
  RUN_TEST(test_stringTrimLeft_given_Amazing_prefixed_with_2_space_should_remove_the_spaces, 523);
  RUN_TEST(test_stringTrimLeft_given_Saviour_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab, 537);
  RUN_TEST(test_stringTrimRight_given_Comet_postfixed_with_3_space_should_remove_the_spaces, 551);
  RUN_TEST(test_stringTrimRight_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab, 565);
  RUN_TEST(test_stringTrim_given_hello_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab, 580);
  RUN_TEST(test_stringTrim_given_Kamaguchi_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab, 593);
  RUN_TEST(test_stringTrim_given_Ferraro_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab, 606);
  RUN_TEST(test_textNew_should_create_a_text_with_reference_of_1, 619);
  RUN_TEST(test_textAssign_dynamic_text_should_increase_reference_to_2, 626);
  RUN_TEST(test_stringRemove_should_remove_first_char_within_a_string, 635);
  RUN_TEST(test_stringRemove_should_remove_three_char_within_a_string, 651);
  RUN_TEST(test_stringRemove_should_remove_five_char_within_a_string, 673);
  RUN_TEST(test_stringRemove_should_remove_all_char_within_a_string, 702);
  RUN_TEST(test_stringLength_should_get_the_correct_length, 738);
  RUN_TEST(test_stringLength_should_get_the_correct_length2, 754);
  RUN_TEST(test_stringLength_should_get_the_correct_length3, 770);
  RUN_TEST(test_stringRemoveWordNotContaining_should_test_input__and_start_with_alphabet, 786);
  RUN_TEST(test_stringRemoveWordNotContaining_should_test_input_and_start_with_alphabet2, 802);
  RUN_TEST(test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet1, 818);
  RUN_TEST(test_stringIsEqual_should_result_both_string_is_same, 837);
  RUN_TEST(test_stringIsEqual_should_result_both_string_the_start_is_different_but_length_is_same, 851);
  RUN_TEST(test_stringIsEqualCaseSensitive_should_set_all_alphabet_to_lower_case, 873);
  RUN_TEST(test_stringIsEqualCaseSensitive_should_set_all_alphabet_to_lower_case2, 894);

  return (UnityEnd());
}
