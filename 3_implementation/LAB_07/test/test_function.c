#include "filter.h"
#include "rect.h"
#include"oscillator.h"
#include "FlipFlop.h"
#include "LogicGates.h"
#include"Header.h"
#include "headers.h"
#include "digitalheader.h"
#include "header1.h"
#include "unity.h"


//-----FILTER CONSTANTS-------------
input_val right1={0.3,10,0,0};      // correct input
input_val wrong1={10,0.1,0,0};      //Av lower limit check
input_val wrong2={0.015,150,0,0};   //freq lower limit and Av upper limit check
input_val wrong3={0.02,100,0,0};    //freq lower limit check
input_val wrong4={300,50,0,0};      //freq upper limit check

input_val right2={0,20,10,50};      //correct input
input_val wrong5={0,20,0.01,100};   //freq lower limit check
input_val wrong6={0,20,10,300};     //freq upper limit check
input_val wrong7={0,1020,30,10};    //Av upper limit check

//------------OSCILLATOR CONSTANTS---------------
osc_input_val true_rc_phase_wein={50, 30, 0.0}; // Coorect RC Phase Shift and Wein Bridge Osc Input 
//C,C1,L,R,R1,R2,R3
// Expected Circuit Design Parameters
osc_output_val true_rc_phase_design_param={10.000000, 0.000000, 0.000000, 0.129897, 1.298972, 38.969154, 0.000000};
osc_output_val true_wein_bridge_design_param={10.000000, 10.000000, 0.000000, 290.000000, 10.000000, 0.010124, 10.000000};

osc_input_val true_colpitts={200, 10, 5}; // Correct Colpitts Osc Input
// Expected Circuit Design Parameters
osc_output_val true_colpitts_design_param={0.150000, 0.750000, 5.061984, 0.000000, 10.000000, 100.000000, 0.000000};

osc_input_val true_mvr={1.00, 0.00, 0.462}; // Correct Astable and Monostable MVR Input
// Expected Circuit Design Parameters
osc_output_val true_astable_mvr_design_param={10.000000, 0.000000, 0.000000, 50.014900, 10.000000, 8.587361, 0.000000};
osc_output_val true_monostable_mvr_design_param={10.000000, 0.000000, 0.000000, 161.317184, 10.000000, 8.587361, 0.000000};

osc_input_val false_rc_phase_wein1={40, 15, 0.0}; // Av Lower limit (RC Phase oscillator Only) 
osc_input_val false_rc_phase_wein2={45, 2.5, 0.0}; // Av Lower Limit (Wein Bridge oscilaltor Only)
osc_input_val false_rc_phase_wein3={5000, 35, 0.0}; // Frequency Upper Limit
osc_input_val false_rc_phase_wein4={0.07, 150, 0.0}; // Av Upper Limit and Frequency Lower Limit

osc_input_val false_colpitts1={2000, 40, 0.05}; // Frequency Upper Limit and beta Lower Limit
osc_input_val false_colpitts2={0.05, 10, 15}; // Frequency Lower Limit and beta Upper Limit
osc_input_val false_colpitts3={200, 2, 5}; // Av Lower Limit
osc_input_val false_colpitts4={200, 200, 5}; // Av Upper Limit

osc_input_val false_mvr1={0.01, 0.00, 0.6}; //Frequency Lower limit
osc_input_val false_mvr2={2000, 0.000, 0.01}; // Frequency Upper Limit and beta lower limit 
osc_input_val false_mvr3={100, 0.000, 20}; // beta Upper Limit

//----------LOGIC GATES CONSTANTS----------------
int andarr[2]={1,0};
int orarr[2]={1,1};
int nandarr[3]={1,1,1};
int norarr[3]={1,1,0};
int xorarr[3]={1,1,1};
int xnorarr[3]={1,1,1};

void setUp(){}
void tearDown(){}

//-------------------------FILTERS---------------------------------------------
void test_choose(void){
    TEST_ASSERT_EQUAL(Success,check_code('A'));
    TEST_ASSERT_EQUAL(code_error,check_code('a'));

}

void test_FLP(void){
    TEST_ASSERT_EQUAL(Success,FLP(&right1));
    TEST_ASSERT_EQUAL(Limit_error,FLP(&wrong1));
    TEST_ASSERT_EQUAL(Limit_error,FLP(&wrong2));
    TEST_ASSERT_EQUAL(Limit_error,FLP(&wrong3));
    TEST_ASSERT_EQUAL(Limit_error,FLP(&wrong4));
    TEST_ASSERT_EQUAL(Failure,NULL);
}

void test_FHP(void){
    TEST_ASSERT_EQUAL(Success,FHP(&right1));
    TEST_ASSERT_EQUAL(Limit_error,FHP(&wrong1));
    TEST_ASSERT_EQUAL(Limit_error,FHP(&wrong2));
    TEST_ASSERT_EQUAL(Limit_error,FHP(&wrong3));
    TEST_ASSERT_EQUAL(Limit_error,FHP(&wrong4));
    TEST_ASSERT_EQUAL(Failure,NULL);
}

void test_SLP(void){
    TEST_ASSERT_EQUAL(Success,SLP(&right1));
    TEST_ASSERT_EQUAL(Limit_error,SLP(&wrong1));
    TEST_ASSERT_EQUAL(Limit_error,SLP(&wrong2));
    TEST_ASSERT_EQUAL(Limit_error,SLP(&wrong3));
    TEST_ASSERT_EQUAL(Limit_error,SLP(&wrong4));
    TEST_ASSERT_EQUAL(Failure,NULL);
}

void test_SHP(void){
    TEST_ASSERT_EQUAL(Success,SHP(&right1));
    TEST_ASSERT_EQUAL(Limit_error,SHP(&wrong1));
    TEST_ASSERT_EQUAL(Limit_error,SHP(&wrong2));
    TEST_ASSERT_EQUAL(Limit_error,SHP(&wrong3));
    TEST_ASSERT_EQUAL(Limit_error,SHP(&wrong4));
    TEST_ASSERT_EQUAL(Failure,NULL);
}

void test_BPF(void){
    TEST_ASSERT_EQUAL(Success,BPF(&right2));
    TEST_ASSERT_EQUAL(Limit_error,BPF(&wrong5));
    TEST_ASSERT_EQUAL(Limit_error,BPF(&wrong6));
    TEST_ASSERT_EQUAL(Limit_error,BPF(&wrong7));
    TEST_ASSERT_EQUAL(Failure,NULL);
}

// ------------------------RECTIFIERS--------------------------------------------

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

//------------------------OSCILLATORS----------------------------------
// Test the osc_check_code function
void test_osc_check_code(void)
{
    TEST_ASSERT_EQUAL(osc_success,osc_check_choice('A'));
    TEST_ASSERT_EQUAL(osc_choice_error,osc_check_choice('a'));
}

// Test the osc_rc_phase_shift function
void test_osc_rc_phase_shift(void)
{
    // Check for NULL values (Failure)
    TEST_ASSERT_EQUAL(osc_failure,osc_rc_phase_shift(NULL));
    // Check for right values
    TEST_ASSERT_EQUAL(osc_success,osc_rc_phase_shift(&true_rc_phase_wein));
    // Comparing individual design parameters of the RC Phase Shift Oscillator
    TEST_ASSERT_EQUAL_FLOAT(true_rc_phase_design_param.C,expected_design_values.C);
    TEST_ASSERT_EQUAL_FLOAT(true_rc_phase_design_param.R,expected_design_values.R);
    TEST_ASSERT_EQUAL_FLOAT(true_rc_phase_design_param.R1,expected_design_values.R1);
    TEST_ASSERT_EQUAL_FLOAT(true_rc_phase_design_param.R2,expected_design_values.R2);
    // Check for out of range values (Limit Error)
    TEST_ASSERT_EQUAL(osc_limit_error,osc_rc_phase_shift(&false_rc_phase_wein1));
    TEST_ASSERT_EQUAL(osc_limit_error,osc_rc_phase_shift(&false_rc_phase_wein3));
    TEST_ASSERT_EQUAL(osc_limit_error,osc_rc_phase_shift(&false_rc_phase_wein4));
}

// Test the osc_wein_bridge function
void test_osc_wein_bridge(void)
{
    // Check for NULL values (Failure)
    TEST_ASSERT_EQUAL(osc_failure,osc_wein_bridge(NULL));
    // Check for right values
    TEST_ASSERT_EQUAL(osc_success,osc_wein_bridge(&true_rc_phase_wein));
    // Comparing individual design parameters of the Wein Bridge Oscillator
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.C,expected_design_values.C);
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.C1,expected_design_values.C1);
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.R,expected_design_values.R);
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.R1,expected_design_values.R1);
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.R2,expected_design_values.R2);
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.R3,expected_design_values.R3);
    // Check for out of range values (Limit Error)
    TEST_ASSERT_EQUAL(osc_limit_error,osc_wein_bridge(&false_rc_phase_wein2));
    TEST_ASSERT_EQUAL(osc_limit_error,osc_wein_bridge(&false_rc_phase_wein3));
    TEST_ASSERT_EQUAL(osc_limit_error,osc_wein_bridge(&false_rc_phase_wein4));
}

// Test the osc_colpitts function
void test_osc_colpitts(void)
{
    // Check for NULL values (Failure)
    TEST_ASSERT_EQUAL(osc_failure,osc_colpitts(NULL));
    // Check for right values
    TEST_ASSERT_EQUAL(osc_success,osc_colpitts(&true_colpitts));
    // Comparing individual design parameters of the Colpitts Oscillator
    TEST_ASSERT_EQUAL_FLOAT(true_colpitts_design_param.C,expected_design_values.C);
    TEST_ASSERT_EQUAL_FLOAT(true_colpitts_design_param.C1,expected_design_values.C1);
    TEST_ASSERT_EQUAL_FLOAT(true_colpitts_design_param.L,expected_design_values.L);
    TEST_ASSERT_EQUAL_FLOAT(true_colpitts_design_param.R1,expected_design_values.R1);
    TEST_ASSERT_EQUAL_FLOAT(true_colpitts_design_param.R2,expected_design_values.R2);
    // Check for out of range values (Limit Error)
    TEST_ASSERT_EQUAL(osc_limit_error,osc_colpitts(&false_colpitts1));
    TEST_ASSERT_EQUAL(osc_limit_error,osc_colpitts(&false_colpitts2));
    TEST_ASSERT_EQUAL(osc_limit_error,osc_colpitts(&false_colpitts3));
    TEST_ASSERT_EQUAL(osc_limit_error,osc_colpitts(&false_colpitts4));
}

// Test the osc_astable_mvr function
void test_osc_astable_mvr(void)
{
    // Check for NULL values (Failure)
    TEST_ASSERT_EQUAL(osc_failure,osc_astable_mvr(NULL));
    // Check for right values
    TEST_ASSERT_EQUAL(osc_success,osc_astable_mvr(&true_mvr));
    // Comparing individual design parameters of the Astable Multivibrator
    TEST_ASSERT_EQUAL_FLOAT(true_astable_mvr_design_param.C,expected_design_values.C);
    TEST_ASSERT_EQUAL_FLOAT(true_astable_mvr_design_param.R,expected_design_values.R);
    TEST_ASSERT_EQUAL_FLOAT(true_astable_mvr_design_param.R1,expected_design_values.R1);
    TEST_ASSERT_EQUAL_FLOAT(true_astable_mvr_design_param.R2,expected_design_values.R2);
    // Check for out of range values (Limit Error)
    TEST_ASSERT_EQUAL(osc_limit_error,osc_astable_mvr(&false_mvr1));
    TEST_ASSERT_EQUAL(osc_limit_error,osc_astable_mvr(&false_mvr2));
    TEST_ASSERT_EQUAL(osc_limit_error,osc_astable_mvr(&false_mvr3));
}

// Test the osc_monostable_mvr function
void test_osc_monostable_mvr(void)
{
    // Check for NULL values (Failure)
    TEST_ASSERT_EQUAL(osc_failure,osc_monostable_mvr(NULL));
    // Check for right values
    TEST_ASSERT_EQUAL(osc_success,osc_monostable_mvr(&true_mvr));
    // Comparing individual design parameters of the Monostable Multivibrator
    TEST_ASSERT_EQUAL_FLOAT(true_monostable_mvr_design_param.C,expected_design_values.C);
    TEST_ASSERT_EQUAL_FLOAT(true_monostable_mvr_design_param.R,expected_design_values.R);
    TEST_ASSERT_EQUAL_FLOAT(true_monostable_mvr_design_param.R1,expected_design_values.R1);
    TEST_ASSERT_EQUAL_FLOAT(true_monostable_mvr_design_param.R2,expected_design_values.R2);
    // Check for out of range values (Limit Error)
    TEST_ASSERT_EQUAL(osc_limit_error,osc_monostable_mvr(&false_mvr1));
    TEST_ASSERT_EQUAL(osc_limit_error,osc_monostable_mvr(&false_mvr2));
    TEST_ASSERT_EQUAL(osc_limit_error,osc_monostable_mvr(&false_mvr3));
}

//-------------------FLIP FLOPS--------------------------------
void test_srflipflop(void)
{
	TEST_ASSERT_EQUAL(1,srflipflop(1,0,0));
	TEST_ASSERT_EQUAL(0,srflipflop(0,1,1));
	TEST_ASSERT_EQUAL(-1,srflipflop(1,2,1));
}

void test_jkflipflop(void)
{
	TEST_ASSERT_EQUAL(0,jkflipflop(0,0,0));
	TEST_ASSERT_EQUAL(1,jkflipflop(1,0,1));
	TEST_ASSERT_EQUAL(-1,jkflipflop(2,2,1));
}

void test_dflipflop(void)
{
	TEST_ASSERT_EQUAL(1,dflipflop(1));
	TEST_ASSERT_EQUAL(0,dflipflop(0));
	TEST_ASSERT_EQUAL(-1,dflipflop(5));
}

void test_tflipflop(void)
{
	TEST_ASSERT_EQUAL(1,tflipflop(1,0));
	TEST_ASSERT_EQUAL(1,tflipflop(0,1));
	TEST_ASSERT_EQUAL(-1,tflipflop(6,7));
}

//----------------LOGIC GATES----------------------------------------
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

//---------------------OP AMP PART A -------------------------------
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
       TEST_ASSERT_EQUAL(-1, Diff(2,4,6,8));
       TEST_ASSERT_EQUAL(-1, Diff(4,6,8,10));
       




}
void test_summ(void)
{
       TEST_ASSERT_EQUAL(8, summ(8,6,4,2));
       TEST_ASSERT_EQUAL(49, summ(23,32,34,35));
       
}

//--------------OP AMP PART B----------------------------------
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

//---------------------Digital Converters -------------------------------
/*void test_bintogray(void)
{
       TEST_ASSERT_EQUAL(1, bintogray(010));
       TEST_ASSERT_EQUAL(1, bintogray(011));
       TEST_ASSERT_EQUAL(110, bintogray(100));


}

void test_graytobin(void)
{
       TEST_ASSERT_EQUAL(1, graytobin(011));
       TEST_ASSERT_EQUAL(10, graytobin(010));
       TEST_ASSERT_EQUAL(1, graytobin(110));


}
void test_bcdtox3(void)
{
       TEST_ASSERT_EQUAL(0110, bcdtox3(1001));
       


}
void test_x3tobcd(void)
{
       TEST_ASSERT_EQUAL(1001, x3tobcd(0110));
       


}

*/

//------------------------ADDERS AND SUBTRACTORS----------------------
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
void test_Full_Subtractor_bout(void)
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

int main(){
    UNITY_BEGIN();
    //------Filters------
    RUN_TEST(test_choose);
    RUN_TEST(test_FLP);
    RUN_TEST(test_FHP);
    RUN_TEST(test_SLP);
    RUN_TEST(test_SHP);
    RUN_TEST(test_BPF);

    //-----Rectifiers-----
    RUN_TEST(test_FWR);
    RUN_TEST(test_HWR);
    RUN_TEST(test_BR);
    RUN_TEST(test_RF);

    //------Oscillators-----
    RUN_TEST(test_osc_check_code);
    RUN_TEST(test_osc_rc_phase_shift);
    RUN_TEST(test_osc_wein_bridge);
    RUN_TEST(test_osc_colpitts);
    RUN_TEST(test_osc_astable_mvr);
    RUN_TEST(test_osc_monostable_mvr);

    //------FlipFlops--------
    RUN_TEST(test_srflipflop);
    RUN_TEST(test_jkflipflop);
    RUN_TEST(test_dflipflop);
    RUN_TEST(test_tflipflop);

    //------LogicGates---------
    RUN_TEST(test_ANDgate);
    RUN_TEST(test_ORgate);
    RUN_TEST(test_NOTgate);
    RUN_TEST(test_NANDgate);
    RUN_TEST(test_NORgate);
    RUN_TEST(test_XORgate);
    RUN_TEST(test_XNORgate);

    //-------OPAMP PartA---------
    RUN_TEST(test_Inv);
    RUN_TEST(test_Non_inv);
    RUN_TEST(test_Diff);
    RUN_TEST(test_summ);

    //------OPAMP PartB----------
    RUN_TEST(test_vtg_follower);
    RUN_TEST(test_inv_sum);
    RUN_TEST(test_non_inv_sum);
    RUN_TEST(test_con_cur_vtg);
	
    //------Digital Converters----------
    //RUN_TEST(test_bintogray);
    //RUN_TEST(test_graytobin);
    //RUN_TEST(test_bcdtox3);
    //RUN_TESTtest_x3tobcd);

    //------AddersAbdSub----------------
    RUN_TEST(test_Full_Adder_sum);
    RUN_TEST(test_Full_Adder_carry);
    RUN_TEST(test_Full_Subtractor_Dif);
    RUN_TEST(test_Full_Subtractor_bout);
    RUN_TEST(test_halfadd);
    RUN_TEST(test_halfadd_carry);
    RUN_TEST(test_halfsub);
    RUN_TEST(test_halfsub_b);

    return UNITY_END();
}
