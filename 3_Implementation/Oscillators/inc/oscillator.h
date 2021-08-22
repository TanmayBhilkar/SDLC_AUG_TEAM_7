/**
 * @file oscillator.h
 * @author Tejas Holla (tejas.holla@ltts.com)
 * @brief OScillator Circuits Header File
 * @version 0.1
 * @date 2021-08-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __OSCILLATOR_H__
#define __OSCILLATOR_H__

/**
 * @brief Strucure to take input values
 * For oscillators
 * (For only Colpitts Oscillator) Feedback Fraction = beta 
 * Oscillator Amplitude Gain = Av
 * Oscillator Frequency = Freq
 * For multivibrators
 * Multivibrator feedback fraction = beta
 * Multivibrator Frequency = Freq
 */
typedef struct osc_input_val
{
    float freq;
    float Av;
    float beta;
}osc_input_val;

/**
 * @brief Structure containing the necessary design values according to the requirement
 * 
 */
typedef struct osc_output_val
{
    float C;
    float C1;
    float L;
    float R;
    float R1;
    float R2;
    float R3;
}osc_output_val;

// Expected Circuit Design Values
// Only for the testing purpose to check the design parameters 
extern osc_output_val expected_design_values;

/**
 * @brief enum to denote different return conditions
 * Failure is used to test null pointer error
 * code_error is used to test the character entered by user
 * Limit_error is used to test the input values stay within operating range
 */
typedef enum osc_condition
{
    Limit_error=-2,
    Choice_error=-1,
    Failure = 0,
    Success = 1
}osc_condition;

/**
 * @brief Oscillator Circuits Menu with all the options to select that oscillator scircuit
 * 
 */
void osc_display(void);
/**
 * @brief Oscillator Circuit Choice Selected is checked 
 * 
 * @param ch character choice that is selected from the user
 * @return osc_condition Success-->VALID CHOICE, code_error--> INVALID CHOICE
 */
osc_condition osc_check_choice(char ch);
/**
 * @brief Depending on the oscillator circuit selected the inputs are taken from the user and passed to the respective functions
 * 
 * @param ch character choice that is selected from the user
 * @return condition Success-->VALID CHOICE, code_error--> INVALID CHOICE   
 */
osc_condition osc_select(char ch);
/**
 * @brief To design a RC Phase Shift Oscillator having the 3 RC Networks
 * Output the circuit parameters 
 * @param osc_params Input Parameters taken from the user (Oscillator Frequency and Oscilaltor Amplitude Gain)
 * @return osc_condition Failure--> Null Pointer Error Detected, Limits_error--> Out of Range Values are detected, Success--> Successful Operation
 */
osc_condition osc_rc_phase_shift(osc_input_val* osc_params);
/**
 * @brief To design a Wein Bridge Oscillator
 * Output the circuit parameters 
 * @param osc_params Input Parameters taken from the user (Oscillator Frequency and Oscilaltor Amplitude Gain)
 * @return osc_condition Failure--> Null Pointer Error Detected, Limits_error--> Out of Range Values are detected, Success--> Successful Operation
 */
osc_condition osc_wein_bridge(osc_input_val* osc_params);
/**
 * @brief To design a Colpitts Oscillator
 * Output the circuit parameters 
 * @param osc_params Input Parameters taken from the user (Oscillator Frequency and Oscilaltor Amplitude Gain and Feedback Fraction)
 * @return osc_condition osc_condition Failure--> Null Pointer Error Detected, Limits_error--> Out of Range Values are detected, Success--> Successful Operation 
 */
osc_condition osc_colpitts(osc_input_val* osc_params);
/**
 * @brief To design a Astable Multivibrator
 * Output the circuit parameters 
 * @param osc_params Input Parameters taken from the user (Oscillator Frequency and Oscilaltor Feedback Fraction)
 * @return osc_condition osc_condition Failure--> Null Pointer Error Detected, Limits_error--> Out of Range Values are detected, Success--> Successful Operation
 */
osc_condition osc_astable_mvr(osc_input_val* osc_params);
/**
 * @brief To design a Monostable Multivibrator
 * Output the circuit parameters 
 * @param osc_params Input Parameters taken from the user (Oscillator Frequency and Oscilaltor Feedback Fraction)
 * @return osc_condition osc_condition Failure--> Null Pointer Error Detected, Limits_error--> Out of Range Values are detected, Success--> Successful Operation
 */
osc_condition osc_monostable_mvr(osc_input_val* osc_params);
#endif