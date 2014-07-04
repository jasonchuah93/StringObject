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
extern void test_getToken_should_get_number_token_from_string_and_left_empty_space(void);
extern void test_getToken_should_get_234_from_string_with_space_in_between_and_left_space567(void);
extern void test_getToken_should_get_234_from_string_contain_alphabets_with_space_in_between_and_left_spacejason(void);
extern void test_getToken_should_throw_error_when_characters_is_behind(void);
extern void test_getToken_should_throw_error_from_string_combine_with_alphabets_and_operators(void);
extern void test_getToken_should_throw_an_error_for_string_start_with_alphabet_first(void);
extern void test_getToken_should_get_operator_token_and_return_ADD_OP_and_left_empty_space(void);
extern void test_getToken_should_get_operator_token_with_space_at_front_and_return_ADD_OP_and_left_empty_space(void);
extern void test_getToken_should_get_operator_token_and_number_token(void);
extern void test_getToken_should_get_operator_token_number_token_and_identieifer_token(void);
extern void test_getToken_should_throw_error_for_string_operator_and_characters(void);
extern void test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space(void);
extern void test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space_and_characters_and_numbers(void);
extern void test_getToken_should_get_operators_token_with_space_at_front_and_return_LOGICAL_AND_OP_and_left_empty_space_and_characters_and_numbers(void);
extern void test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space(void);
extern void test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space_and_characters(void);
extern void test_getToken_should_get_two_different_operators_token_and_throw_an_error(void);
extern void test_getToken_should_get_two_different_operators_token_and_throw_an_error2(void);
extern void test_getToken_should_get_space_between_two_different_operators_token_and_throw_an_error(void);
extern void test_getToken_should_get_identifier_token_from_string(void);
extern void test_tokenDel_should_delete_Number_token_and_return_empty_string(void);
extern void test_tokenDel_should_delete_Identifier_token_and_return_empty_string(void);
extern void test_tokenDel_should_delete_Operator_token_and_return_empty_string(void);
extern void test_tokenDel_should_getToken_for_left_parenthesis(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_getToken.c";
  UnityBegin();
  RUN_TEST(test_getToken_should_get_number_token_from_string_and_left_empty_space, 13);
  RUN_TEST(test_getToken_should_get_234_from_string_with_space_in_between_and_left_space567, 35);
  RUN_TEST(test_getToken_should_get_234_from_string_contain_alphabets_with_space_in_between_and_left_spacejason, 50);
  RUN_TEST(test_getToken_should_throw_error_when_characters_is_behind, 61);
  RUN_TEST(test_getToken_should_throw_error_from_string_combine_with_alphabets_and_operators, 74);
  RUN_TEST(test_getToken_should_throw_an_error_for_string_start_with_alphabet_first, 85);
  RUN_TEST(test_getToken_should_get_operator_token_and_return_ADD_OP_and_left_empty_space, 98);
  RUN_TEST(test_getToken_should_get_operator_token_with_space_at_front_and_return_ADD_OP_and_left_empty_space, 111);
  RUN_TEST(test_getToken_should_get_operator_token_and_number_token, 124);
  RUN_TEST(test_getToken_should_get_operator_token_number_token_and_identieifer_token, 151);
  RUN_TEST(test_getToken_should_throw_error_for_string_operator_and_characters, 181);
  RUN_TEST(test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space, 194);
  RUN_TEST(test_getToken_should_get_operators_token_and_return_LOGICAL_AND_OP_and_left_empty_space_and_characters_and_numbers, 210);
  RUN_TEST(test_getToken_should_get_operators_token_with_space_at_front_and_return_LOGICAL_AND_OP_and_left_empty_space_and_characters_and_numbers, 226);
  RUN_TEST(test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space, 240);
  RUN_TEST(test_getToken_should_get_operators_token_and_return_LOGICAL_OR_OP_and_left_empty_space_and_characters, 256);
  RUN_TEST(test_getToken_should_get_two_different_operators_token_and_throw_an_error, 272);
  RUN_TEST(test_getToken_should_get_two_different_operators_token_and_throw_an_error2, 285);
  RUN_TEST(test_getToken_should_get_space_between_two_different_operators_token_and_throw_an_error, 298);
  RUN_TEST(test_getToken_should_get_identifier_token_from_string, 315);
  RUN_TEST(test_tokenDel_should_delete_Number_token_and_return_empty_string, 328);
  RUN_TEST(test_tokenDel_should_delete_Identifier_token_and_return_empty_string, 340);
  RUN_TEST(test_tokenDel_should_delete_Operator_token_and_return_empty_string, 352);
  RUN_TEST(test_tokenDel_should_getToken_for_left_parenthesis, 364);

  return (UnityEnd());
}
