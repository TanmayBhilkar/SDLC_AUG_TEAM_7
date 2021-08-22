#include"unity.h"
#include"header.h"
#include "unity.c"

void setUp()
{
    

 
}
/* Required by the unity test framework */
void tearDown()
{

}

void test_Full_Adder_sum(void)
{
       TEST_ASSERT_EQUAL(1, Full_Adder_sum(1,1,1));
       


}
void test_Full_Adder_carry(void)
{
       TEST_ASSERT_EQUAL(1, Full_Adder_carry(1,1,1));
       


}

void test_Full_Subtractor_Dif(void)
{
       TEST_ASSERT_EQUAL(1, Full_Subtractor_Dif(1,1,1));
    

}
void testFull_Subtractor_bout(void)
{
       TEST_ASSERT_EQUAL(1, Full_Subtractor_bout(1,1,1));
    

}
void test_halfadd(void)
{
       TEST_ASSERT_EQUAL(1, halfadd(1,0));
       


}
void test_halfadd_carry(void)
{
       TEST_ASSERT_EQUAL(0, halfadd_carry(1,0));
       
}

void test_halfsub(void)
{
       TEST_ASSERT_EQUAL(0, halfsub(1,1));
       
}
void test_halfsub_b(void)
{
       TEST_ASSERT_EQUAL(0, halfsub_b(1,1));
       
}