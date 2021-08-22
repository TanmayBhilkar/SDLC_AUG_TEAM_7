#include"unity.h"
#include"Header.h"
#include "unity.c"
/*#include"opm.c"
#include"op.c"*/



void setUp()
{
    

 
}
/* Required by the unity test framework */
void tearDown()
{

}

void test_Inv(void)
{
       TEST_ASSERT_EQUAL(1, Inv(1,2,3));
       TEST_ASSERT_EQUAL(2, Inv(2,3,4));
       TEST_ASSERT_EQUAL(4, Inv(4,5,6));




}
void test_Non_inv(void)
{
       TEST_ASSERT_EQUAL(2, Non_inv(1,2,3));
       TEST_ASSERT_EQUAL(3, Non_inv(2,3,4));
       TEST_ASSERT_EQUAL(5, Non_inv(4,5,6));




}
void test_Diff(void)
{
       TEST_ASSERT_EQUAL(1, Diff(2,4,6,8));
       TEST_ASSERT_EQUAL(1, Diff(4,6,8,10));
       




}
void test_summ(void)
{
       TEST_ASSERT_EQUAL(8, summ(8,6,4,2));
       TEST_ASSERT_EQUAL(56, summ(23,32,34,35));
       
}



int main(void)
{
  
    UNITY_BEGIN();
    RUN_TEST(test_Inv);
    RUN_TEST(test_Inv);
    RUN_TEST(test_Inv);
    RUN_TEST(test_Non_inv);
    RUN_TEST(test_Non_inv);
    RUN_TEST(test_Non_inv);
    RUN_TEST(test_Diff);
    RUN_TEST(test_Diff);
    RUN_TEST(test_summ);
    RUN_TEST(test_summ);
    
    
   
    
     
    return UNITY_END();
}