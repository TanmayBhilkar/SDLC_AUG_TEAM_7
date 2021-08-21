#include "unity.h"
#include "fun.h"
int andarr[2]={1,0};
int orarr[2]={1,1};
int nandarr[3]={1,1,1};
int norarr[3]={1,1,0};
int xorarr[3]={1,1,1};
int xnorarr[3]={1,1,1};
/* Required by the unity test framework */
void setUp()
{
 
}
/* Required by the unity test framework */
void tearDown()
{

}

void test_inputs(void)
{
   TEST_ASSERT_EQUAL(0, inputs(andarr,2));
}


void test_ANDgate(void)
{
   TEST_ASSERT_EQUAL(0, ANDgate(andarr,2));
}

void test_ORgate(void)
{
  TEST_ASSERT_EQUAL(1, ORgate(orarr,2));
}

void test_NOTgate(void)
{
  TEST_ASSERT_EQUAL(1, NOTgate(0));
}
void test_NANDgate(void)
{    
  TEST_ASSERT_EQUAL(0, NANDgate(nandarr,3));
}
void test_NORgate(void)
{
     TEST_ASSERT_EQUAL(0, NORgate(norarr,3));
}
void test_XORgate(void)
{
    TEST_ASSERT_EQUAL(1, XORgate(xorarr,3));
}
void test_XNORgate(void)
{
    TEST_ASSERT_EQUAL(0, XNORgate(xnorarr,3));
}

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    
    RUN_TEST(test_ANDgate);
    RUN_TEST(test_ORgate);
    RUN_TEST(test_NOTgate);

    RUN_TEST(test_NANDgate);
    RUN_TEST(test_NORgate);
    RUN_TEST(test_XORgate);
    RUN_TEST(test_XNORgate);
    
    /* Close the Unity Test Framework */
    return UNITY_END();
}

