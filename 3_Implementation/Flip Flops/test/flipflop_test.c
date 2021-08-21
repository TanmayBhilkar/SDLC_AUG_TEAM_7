#include "Flip_Flop.h"
#include "FlipFlop.c"
#include "unity.h"
#include "unity.c"
#define PROJECT_NAME    "Flip Flops"

void setUp(){}
void tearDown(){}


void test_srflipflop(void)
{
	TEST_ASSERT_EQUAL(1,srflipflop(1,0,0));
	TEST_ASSERT_EQUAL(0,srflipflop(0,1,1));
}

void test_jkflipflop(void)
{
	TEST_ASSERT_EQUAL(0,jkflipflop(0,0,0));
	TEST_ASSERT_EQUAL(1,jkflipflop(1,0,1));
}

void test_dflipflop(void)
{
	TEST_ASSERT_EQUAL(1,dflipflop(1));
	TEST_ASSERT_EQUAL(0,dflipflop(0));
}

void test_tflipflop(void)
{
	TEST_ASSERT_EQUAL(1,tflipflop(1,0));
	TEST_ASSERT_EQUAL(1,tflipflop(0,1));
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_srflipflop);
    RUN_TEST(test_jkflipflop);
    RUN_TEST(test_dflipflop);
    RUN_TEST(test_tflipflop);
    return UNITY_END();
}
