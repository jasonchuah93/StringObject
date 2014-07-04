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
extern void test_numberNew_should_get_single_digit_value_and_type(void);
extern void test_numberNew_should_get_more_than_single_digit_value_and_type(void);
extern void test_numberNew_should_get_negative_value_and_type(void);
extern void test_identifierNew_should_identifier_the_content(void);
extern void test_identifierNew_should_identifier_the_content2(void);
extern void test_identifierNew_should_identifier_the_content_three(void);
extern void test_operatorNewBySymbol_should_identify_the_symbol(void);
extern void test_operatorNewBySymbol_should_identify_the_different_symbol(void);
extern void test_operatorNewBySymbol_should_identify_the_different_symbol2(void);
extern void test_operatorNewBySymbol_should_identify_the_different_symbol3(void);
extern void test_operatorNewBySymbol_should__retur_NULL_if_input_invalid_symbol(void);
extern void test_operatorNewBySymbol_should_identify_the_different_symbol4(void);
extern void test_operatorNewByID_should_identify_the_different_symbol(void);
extern void test_operatorNewByID_should_identify_the_different_symbol2(void);
extern void test_operatorNewByID_should_identify_the_different_symbol3(void);
extern void test_operatorNewByID_should_return_NULL_if_input_the_incorrect_symbol(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_Token.c";
  UnityBegin();
  RUN_TEST(test_numberNew_should_get_single_digit_value_and_type, 14);
  RUN_TEST(test_numberNew_should_get_more_than_single_digit_value_and_type, 24);
  RUN_TEST(test_numberNew_should_get_negative_value_and_type, 34);
  RUN_TEST(test_identifierNew_should_identifier_the_content, 44);
  RUN_TEST(test_identifierNew_should_identifier_the_content2, 55);
  RUN_TEST(test_identifierNew_should_identifier_the_content_three, 66);
  RUN_TEST(test_operatorNewBySymbol_should_identify_the_symbol, 78);
  RUN_TEST(test_operatorNewBySymbol_should_identify_the_different_symbol, 90);
  RUN_TEST(test_operatorNewBySymbol_should_identify_the_different_symbol2, 102);
  RUN_TEST(test_operatorNewBySymbol_should_identify_the_different_symbol3, 114);
  RUN_TEST(test_operatorNewBySymbol_should__retur_NULL_if_input_invalid_symbol, 126);
  RUN_TEST(test_operatorNewBySymbol_should_identify_the_different_symbol4, 134);
  RUN_TEST(test_operatorNewByID_should_identify_the_different_symbol, 147);
  RUN_TEST(test_operatorNewByID_should_identify_the_different_symbol2, 157);
  RUN_TEST(test_operatorNewByID_should_identify_the_different_symbol3, 167);
  RUN_TEST(test_operatorNewByID_should_return_NULL_if_input_the_incorrect_symbol, 176);

  return (UnityEnd());
}
