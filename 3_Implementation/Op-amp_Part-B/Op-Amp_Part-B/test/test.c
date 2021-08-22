#include "header.h"
#include "unity.h"

/* Prototypes for all the test functions */
int vtg_follower(int Av,int Vin);
float inv_sum(float V1,float Av1,float V2, float Av2);
float non_inv_sum(float r,float vtg_sum);
float con_cur_vtg(float Vin,float Vi,float I);


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Write all the test functions */

void test_vtg_follower()
{
    TEST_ASSERT_EQUAL(8, vtg_follower(2,4));
   
}
void test_inv_sum()
{
    TEST_ASSERT_EQUAL(16.00, inv_sum(2,5,3,2));
    
}
void test_non_inv_sum()
{
    TEST_ASSERT_EQUAL(10.00, non_inv_sum(4,6));

}    
void test_con_cur_vtg()
{
    TEST_ASSERT_EQUAL(10.00, con_cur_vtg(10,4,4));
    
}


/* Start of the application test */
int test_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_vtg_follower);
 // RUN_TEST(test_score_neg);


  /* Close the Unity Test Framework */
  return UNITY_END();
}
