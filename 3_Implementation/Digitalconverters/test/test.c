#include"unity.h"
#include"digitalheader.h"
#include "unity.c"

void setUp()
{
    

 
}
/* Required by the unity test framework */
void tearDown()
{

}

void test_bintogray(void)
{
       TEST_ASSERT_EQUAL(011, bintogray(010));
       TEST_ASSERT_EQUAL(010, bintogray(011));
       TEST_ASSERT_EQUAL(110, bintogray(100));


}

void test_graytobin(void)
{
       TEST_ASSERT_EQUAL(010, graytobin(011));
       TEST_ASSERT_EQUAL(011, graytobin(010));
       TEST_ASSERT_EQUAL(100, graytobin(110));


}
/*
void test_bcdtox3(void)
{
       TEST_ASSERT_EQUAL(0110, bcdtox3(1001));
       


}
void test_x3tobcd(void)
{
       TEST_ASSERT_EQUAL(1001, x3tobcd(0110));
       


}
*/

int main(void)
{
  
    UNITY_BEGIN();
    RUN_TEST(test_bintogray);
    RUN_TEST(test_graytobin);
   // RUN_TEST(test_bcdtox3);
   // RUN_TEST(test_x3tobcd);
 
    return UNITY_END();
}
