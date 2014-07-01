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
extern void test_stringNew_should_create_string_with_static_text(void);
extern void test_stringNew_should_create_string_with_dynamic_text(void);
extern void test_stringAssign_should_increase_reference(void);
extern void test_stringAssign_should_not_increase_reference(void);
extern void test_stringDelete_should_delete_reference(void);
extern void test_stringDelete_should_not_delete_reference_for_text(void);
extern void test_stringDelete_should_delete_all_reference_and_return_null(void);
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
extern void test_stringRemove_should_remove_first_char_within_a_string(void);
extern void test_stringRemove_should_remove_three_char_within_a_string(void);
extern void test_stringRemove_should_remove_five_char_within_a_string(void);
extern void test_stringRemove_should_remove_all_char_within_a_string(void);
extern void test_stringLength_should_get_the_correct_length(void);
extern void test_stringLength_should_get_the_correct_length2(void);
extern void test_stringLength_should_get_the_correct_length3(void);
extern void test_stringRemoveWordNotContaining_should_test_input_and_start_with_alphabet(void);
extern void test_stringRemoveWordNotContaining_should_test_input_and_start_with_alphabet2(void);
extern void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet1(void);
extern void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet2(void);
extern void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet3(void);
extern void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet4(void);
extern void test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet5(void);
extern void test_stringIsEqual_should_return_one_if_both_string_is_same(void);
extern void test_stringIsEqual_should_return_one_if_both_string_is_same01(void);
extern void test_stringIsEqual_should_return_zero_if_both_string_is_same02(void);
extern void test_stringIsEqualCaseInsensitive_should_set_all_alphabet_to_lower_case(void);
extern void test_stringIsEqualCaseInsensitive_should_set_all_alphabet_to_lower_case2(void);
extern void test_stringIsEqualCaseInsensitive_should_set_all_alphabet_to_lower_case01(void);
extern void test_stringCharAt_should_return_negative_one_if_startIndex_is_more_than_lenght(void);
extern void test_stringCharAt_should_return_relative_character(void);
extern void test_stringCharAt_should_return_relative_character2(void);
extern void test_stringCharAtInSet_should_return_negative_one(void);
extern void test_stringCharAtInSet_should_return_relative_character2(void);
extern void test_stringCharAtInSet_should_return_relative_character3(void);
extern void test_stringSubstringInChar_Phone016_should_return_016(void);
extern void test_stringSubstringInChar2_HandPhone016123_should_return_Phone016123(void);
extern void test_stringSubstringInChar_Phone016_should_return_NULL_if_length_of_string_exceeded(void);
extern void test_stringSubstringInText_Phone016_should_return_016(void);
extern void test_stringSubstringInText_should_get_substring(void);
extern void test_stringSubstringInText_should_return_empty_string(void);
extern void test_stringToInteger_should_return_integer_type(void);
extern void test_stringToInteger_should_return_integer_type2(void);
extern void test_stringToInteger_should_return_integer_type3(void);


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
  RUN_TEST(test_StringDump_explore, 15);
  RUN_TEST(test_stringNew_should_create_string_with_static_text, 37);
  RUN_TEST(test_stringNew_should_create_string_with_dynamic_text, 53);
  RUN_TEST(test_stringAssign_should_increase_reference, 71);
  RUN_TEST(test_stringAssign_should_not_increase_reference, 98);
  RUN_TEST(test_stringDelete_should_delete_reference, 119);
  RUN_TEST(test_stringDelete_should_not_delete_reference_for_text, 152);
  RUN_TEST(test_stringDelete_should_delete_all_reference_and_return_null, 186);
  RUN_TEST(test_stringSkip_given_Hello_and_skip_2_should_become_llo, 230);
  RUN_TEST(test_stringSkip_given_gundam_and_skip_4_should_become_am, 244);
  RUN_TEST(test_stringSkip_given_gundam_and_skip_6_should_return_null, 258);
  RUN_TEST(test_stringSkip_given_beyond_ra_and_skip_2_should_make_start_equals_2_length_equals_0, 272);
  RUN_TEST(test_stringTrimLeft_given_Amazing_prefixed_with_2_space_should_remove_the_spaces, 286);
  RUN_TEST(test_stringTrimLeft_given_Saviour_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab, 300);
  RUN_TEST(test_stringTrimRight_given_Comet_postfixed_with_3_space_should_remove_the_spaces, 314);
  RUN_TEST(test_stringTrimRight_given_hello_prefixed_with_space_and_tab_should_remove_the_spaces_and_tab, 328);
  RUN_TEST(test_stringTrim_given_hello_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab, 343);
  RUN_TEST(test_stringTrim_given_Kamaguchi_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab, 356);
  RUN_TEST(test_stringTrim_given_Ferraro_suffixed_with_space_and_tab_should_remove_all_spaces_and_tab, 369);
  RUN_TEST(test_stringRemove_should_remove_first_char_within_a_string, 384);
  RUN_TEST(test_stringRemove_should_remove_three_char_within_a_string, 400);
  RUN_TEST(test_stringRemove_should_remove_five_char_within_a_string, 422);
  RUN_TEST(test_stringRemove_should_remove_all_char_within_a_string, 451);
  RUN_TEST(test_stringLength_should_get_the_correct_length, 487);
  RUN_TEST(test_stringLength_should_get_the_correct_length2, 503);
  RUN_TEST(test_stringLength_should_get_the_correct_length3, 519);
  RUN_TEST(test_stringRemoveWordNotContaining_should_test_input_and_start_with_alphabet, 535);
  RUN_TEST(test_stringRemoveWordNotContaining_should_test_input_and_start_with_alphabet2, 550);
  RUN_TEST(test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet1, 566);
  RUN_TEST(test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet2, 583);
  RUN_TEST(test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet3, 600);
  RUN_TEST(test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet4, 617);
  RUN_TEST(test_stringRemoveWordContaining_should_test_input_and_start_with_alphabet5, 634);
  RUN_TEST(test_stringIsEqual_should_return_one_if_both_string_is_same, 652);
  RUN_TEST(test_stringIsEqual_should_return_one_if_both_string_is_same01, 673);
  RUN_TEST(test_stringIsEqual_should_return_zero_if_both_string_is_same02, 694);
  RUN_TEST(test_stringIsEqualCaseInsensitive_should_set_all_alphabet_to_lower_case, 715);
  RUN_TEST(test_stringIsEqualCaseInsensitive_should_set_all_alphabet_to_lower_case2, 736);
  RUN_TEST(test_stringIsEqualCaseInsensitive_should_set_all_alphabet_to_lower_case01, 757);
  RUN_TEST(test_stringCharAt_should_return_negative_one_if_startIndex_is_more_than_lenght, 778);
  RUN_TEST(test_stringCharAt_should_return_relative_character, 787);
  RUN_TEST(test_stringCharAt_should_return_relative_character2, 799);
  RUN_TEST(test_stringCharAtInSet_should_return_negative_one, 811);
  RUN_TEST(test_stringCharAtInSet_should_return_relative_character2, 822);
  RUN_TEST(test_stringCharAtInSet_should_return_relative_character3, 833);
  RUN_TEST(test_stringSubstringInChar_Phone016_should_return_016, 844);
  RUN_TEST(test_stringSubstringInChar2_HandPhone016123_should_return_Phone016123, 856);
  RUN_TEST(test_stringSubstringInChar_Phone016_should_return_NULL_if_length_of_string_exceeded, 868);
  RUN_TEST(test_stringSubstringInText_Phone016_should_return_016, 880);
  RUN_TEST(test_stringSubstringInText_should_get_substring, 893);
  RUN_TEST(test_stringSubstringInText_should_return_empty_string, 906);
  RUN_TEST(test_stringToInteger_should_return_integer_type, 919);
  RUN_TEST(test_stringToInteger_should_return_integer_type2, 931);
  RUN_TEST(test_stringToInteger_should_return_integer_type3, 943);

  return (UnityEnd());
}
