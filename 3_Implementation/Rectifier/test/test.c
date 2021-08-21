/**
 * @file test.c
 * @author sakshinitnaware 
 * @brief 
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "rect.h"
#include "unity.h"

void setUp(){}
void tearDown(){}
/**
 * @brief  test_FWR() to test desired outputs of Full wave Rectifier
 * Vm as 60, Vac as 10, 1 to choose if want to calculate effeciency 
 * the second test returns -1 as Vm should be in the range of 0-100
 * the third test returns -2 as Vac should not be 0
 * the fourth test returns -3 as Vdc/Vac should not be greater than 1
 */
void test_FWR(void){
    TEST_ASSERT_EQUAL(-3,FWR(60,1,10));
    TEST_ASSERT_EQUAL(-1,FWR(0,1,10));
    TEST_ASSERT_EQUAL(-2,FWR(50,1,0));
    TEST_ASSERT_EQUAL(-3,FWR(90,1,0.5));
}

/**
 * @brief test_hWR() to test desired outputs of Half wave Rectifier
 * Vm as 60, Vac as 10, 1 to choose if want to calculate effeciency 
 * the second test returns -1 as Vm should be in the range of 0-100
 * the third test returns -2 as Vac should not be 0
 * the fourth test returns -3 as Vdc/Vac should not be greater than 1
 */
void test_HWR(void){
    TEST_ASSERT_EQUAL(-3,HWR(60,1,10));
    TEST_ASSERT_EQUAL(-1,HWR(0,1,10));
    TEST_ASSERT_EQUAL(-2,HWR(50,1,0));
    TEST_ASSERT_EQUAL(-3,HWR(90,1,0.5));
}

/**
 * @brief test_BR() to test desired outputs of Bridge Rectifier
 * Vm as 60, Vac as 10, 1 to choose if want to calculate effeciency 
 * the second test returns -1 as Vm should be in the range of 0-100
 * the third test returns -2 as Vac should not be 0
 * the fourth test returns -3 as Vdc/Vac should not be greater than 1
 */
void test_BR(void){
    TEST_ASSERT_EQUAL(-3,BR(60,1,10));
    TEST_ASSERT_EQUAL(-1,BR(0,1,10));
    TEST_ASSERT_EQUAL(-2,BR(50,1,0));
    TEST_ASSERT_EQUAL(-3,BR(90,1,0.5));
}
/**
 * @brief test_FR() to test desired outputs of Filter with Rectifier
 * Vm as 10, Vac as 10 to calculate to calculate ripple factor 
 * the second test returns -1 as Vm should be in the range of 0-100 
 */
void test_RF(void){
    TEST_ASSERT_EQUAL(1.73,RF(10,10));
    TEST_ASSERT_EQUAL(-1,RF(0,10));
}
 
 int main(){
    UNITY_BEGIN();
    RUN_TEST(test_FWR);
    RUN_TEST(test_FWR);
    RUN_TEST(test_FWR);
    RUN_TEST(test_FWR);
    RUN_TEST(test_HWR);
    RUN_TEST(test_HWR);
    RUN_TEST(test_HWR);
    RUN_TEST(test_HWR);
    RUN_TEST(test_BR);
    RUN_TEST(test_BR);
    RUN_TEST(test_BR);
    RUN_TEST(test_BR);
    RUN_TEST(test_RF);
    RUN_TEST(test_RF);
    
    return UNITY_END();
}