#include"oscillator.h"
#include"unity.h"

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

void setUp(){}
void tearDown(){}

// Test the osc_check_code function
void test_osc_check_code(void)
{
    TEST_ASSERT_EQUAL(Success,osc_check_choice('A'));
    TEST_ASSERT_EQUAL(Choice_error,osc_check_choice('a'));
}

// Test the osc_rc_phase_shift function
void test_osc_rc_phase_shift(void)
{
    // Check for NULL values (Failure)
    TEST_ASSERT_EQUAL(Failure,osc_rc_phase_shift(NULL));
    // Check for right values
    TEST_ASSERT_EQUAL(Success,osc_rc_phase_shift(&true_rc_phase_wein));
    // Comparing individual design parameters of the RC Phase Shift Oscillator
    TEST_ASSERT_EQUAL_FLOAT(true_rc_phase_design_param.C,expected_design_values.C);
    TEST_ASSERT_EQUAL_FLOAT(true_rc_phase_design_param.R,expected_design_values.R);
    TEST_ASSERT_EQUAL_FLOAT(true_rc_phase_design_param.R1,expected_design_values.R1);
    TEST_ASSERT_EQUAL_FLOAT(true_rc_phase_design_param.R2,expected_design_values.R2);
    // Check for out of range values (Limit Error)
    TEST_ASSERT_EQUAL(Limit_error,osc_rc_phase_shift(&false_rc_phase_wein1));
    TEST_ASSERT_EQUAL(Limit_error,osc_rc_phase_shift(&false_rc_phase_wein3));
    TEST_ASSERT_EQUAL(Limit_error,osc_rc_phase_shift(&false_rc_phase_wein4));
}

// Test the osc_wein_bridge function
void test_osc_wein_bridge(void)
{
    // Check for NULL values (Failure)
    TEST_ASSERT_EQUAL(Failure,osc_wein_bridge(NULL));
    // Check for right values
    TEST_ASSERT_EQUAL(Success,osc_wein_bridge(&true_rc_phase_wein));
    // Comparing individual design parameters of the Wein Bridge Oscillator
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.C,expected_design_values.C);
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.C1,expected_design_values.C1);
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.R,expected_design_values.R);
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.R1,expected_design_values.R1);
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.R2,expected_design_values.R2);
    TEST_ASSERT_EQUAL_FLOAT(true_wein_bridge_design_param.R3,expected_design_values.R3);
    // Check for out of range values (Limit Error)
    TEST_ASSERT_EQUAL(Limit_error,osc_wein_bridge(&false_rc_phase_wein2));
    TEST_ASSERT_EQUAL(Limit_error,osc_wein_bridge(&false_rc_phase_wein3));
    TEST_ASSERT_EQUAL(Limit_error,osc_wein_bridge(&false_rc_phase_wein4));
}

// Test the osc_colpitts function
void test_osc_colpitts(void)
{
    // Check for NULL values (Failure)
    TEST_ASSERT_EQUAL(Failure,osc_colpitts(NULL));
    // Check for right values
    TEST_ASSERT_EQUAL(Success,osc_colpitts(&true_colpitts));
    // Comparing individual design parameters of the Colpitts Oscillator
    TEST_ASSERT_EQUAL_FLOAT(true_colpitts_design_param.C,expected_design_values.C);
    TEST_ASSERT_EQUAL_FLOAT(true_colpitts_design_param.C1,expected_design_values.C1);
    TEST_ASSERT_EQUAL_FLOAT(true_colpitts_design_param.L,expected_design_values.L);
    TEST_ASSERT_EQUAL_FLOAT(true_colpitts_design_param.R1,expected_design_values.R1);
    TEST_ASSERT_EQUAL_FLOAT(true_colpitts_design_param.R2,expected_design_values.R2);
    // Check for out of range values (Limit Error)
    TEST_ASSERT_EQUAL(Limit_error,osc_colpitts(&false_colpitts1));
    TEST_ASSERT_EQUAL(Limit_error,osc_colpitts(&false_colpitts2));
    TEST_ASSERT_EQUAL(Limit_error,osc_colpitts(&false_colpitts3));
    TEST_ASSERT_EQUAL(Limit_error,osc_colpitts(&false_colpitts4));
}

// Test the osc_astable_mvr function
void test_osc_astable_mvr(void)
{
    // Check for NULL values (Failure)
    TEST_ASSERT_EQUAL(Failure,osc_astable_mvr(NULL));
    // Check for right values
    TEST_ASSERT_EQUAL(Success,osc_astable_mvr(&true_mvr));
    // Comparing individual design parameters of the Astable Multivibrator
    TEST_ASSERT_EQUAL_FLOAT(true_astable_mvr_design_param.C,expected_design_values.C);
    TEST_ASSERT_EQUAL_FLOAT(true_astable_mvr_design_param.R,expected_design_values.R);
    TEST_ASSERT_EQUAL_FLOAT(true_astable_mvr_design_param.R1,expected_design_values.R1);
    TEST_ASSERT_EQUAL_FLOAT(true_astable_mvr_design_param.R2,expected_design_values.R2);
    // Check for out of range values (Limit Error)
    TEST_ASSERT_EQUAL(Limit_error,osc_astable_mvr(&false_mvr1));
    TEST_ASSERT_EQUAL(Limit_error,osc_astable_mvr(&false_mvr2));
    TEST_ASSERT_EQUAL(Limit_error,osc_astable_mvr(&false_mvr3));
}

// Test the osc_monostable_mvr function
void test_osc_monostable_mvr(void)
{
    // Check for NULL values (Failure)
    TEST_ASSERT_EQUAL(Failure,osc_monostable_mvr(NULL));
    // Check for right values
    TEST_ASSERT_EQUAL(Success,osc_monostable_mvr(&true_mvr));
    // Comparing individual design parameters of the Monostable Multivibrator
    TEST_ASSERT_EQUAL_FLOAT(true_monostable_mvr_design_param.C,expected_design_values.C);
    TEST_ASSERT_EQUAL_FLOAT(true_monostable_mvr_design_param.R,expected_design_values.R);
    TEST_ASSERT_EQUAL_FLOAT(true_monostable_mvr_design_param.R1,expected_design_values.R1);
    TEST_ASSERT_EQUAL_FLOAT(true_monostable_mvr_design_param.R2,expected_design_values.R2);
    // Check for out of range values (Limit Error)
    TEST_ASSERT_EQUAL(Limit_error,osc_monostable_mvr(&false_mvr1));
    TEST_ASSERT_EQUAL(Limit_error,osc_monostable_mvr(&false_mvr2));
    TEST_ASSERT_EQUAL(Limit_error,osc_monostable_mvr(&false_mvr3));
}

int main()
{
    UNITY_BEGIN();
    // Calling the test functions
    
    RUN_TEST(test_osc_check_code);
    RUN_TEST(test_osc_rc_phase_shift);
    RUN_TEST(test_osc_wein_bridge);
    RUN_TEST(test_osc_colpitts);
    RUN_TEST(test_osc_astable_mvr);
    RUN_TEST(test_osc_monostable_mvr);
    return UNITY_END();
}