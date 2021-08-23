/**
 * @file oscillator.c
 * @author Tejas Holla (tejas.holla@ltts.com)
 * @brief Oscillator Circuit Dsign Functions and Interface Functions
 * @version 0.1
 * @date 2021-08-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include"oscillator.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.142857143
#define rt6 2.449489743
/**
 * @brief Oscillator Circuits Operations
 * 
 */
void osc_display()
{
    printf("******************************WELCOME******************************\n\n");
    printf("This is a project that will give you the parameters to design different oscillators.\n");
    printf("Refer the below chart to choose your oscillator\n");
    printf("A - RC Phase Shift Oscillator\nB - Wein Bridge Oscillator\nC - Colpitts Oscillator\nD - Astable Multivibrator\nE - Monostable Multivibrator\nF - Exit\n");
    printf("Note : The operating frequency range is from 0.1kHz to 250kHz");
    printf("\nEnter the code of the oscillator of your choice\n");
}

/**
 * @brief Check if the entered choice of operation is working properly or not
 * 
 * @param c 
 * @return condition 
 */
osc_condition osc_check_choice(char ch)
{
    if (ch=='A' || ch=='B' || ch=='C' || ch=='D' || ch=='E') 
        return osc_success;
    else 
        return osc_choice_error;
}

/**
 * @brief User selects the oscillator circuit of their choice
 * The input parameters are taken depending on which circuit is selected
 * @param c 
 * @return condition 
 */
osc_condition osc_select(char ch)
{
    osc_input_val params;
    int flag=1;

    // Oscillator Inputs are Frequency and Amplitude Gain 
    // For colpitt oscillator the feedback fraction is also taken
    if (ch=='A' || ch=='B')
    {
        printf("\nEnter the oscillating frequency in kHz: ");
        scanf("%f",&params.freq);
        printf("\nEnter the oscillator amplitude gain in dB: ");
        scanf("%f",&params.Av);
        flag=1;
    }
    else if(ch=='C')
    {
        printf("\nEnter the feedback fraction (Value range 0-10): ");
        scanf("%f",&params.beta);
        printf("\nEnter the oscillating frequency in kHz: ");
        scanf("%f",&params.freq);
        printf("\nEnter the oscillator amplitude gain in dB: ");
        scanf("%f",&params.Av);
        flag=1;            
    }
    else if (ch=='D' || ch=='E')
    {
        printf("\nEnter the oscillating frequency in kHz: ");
        scanf("%f",&params.freq);
        printf("\nEnter the feedback fraction (Value range 0-10): ");
        scanf("%f",&params.beta);
        flag=1;
    }

    else 
    {
        printf("\n!!! Enter the correct alphabet !!! \n");
        printf("\nRefer the below chart to choose your filter\n");
        printf("A - RC Phase Shift Oscillator\nB - Wein Bridge Oscillator\nC - Colpitts Oscillator\nD - Astable Multivibrator\nE - Monostable Multivibrator\nF - Exit\n");
        flag=-1;
    }

    switch(ch)
    {
        case 'A':osc_rc_phase_shift(&params);break;
        case 'B':osc_wein_bridge(&params);break;
        case 'C':osc_colpitts(&params);break;
        case 'D':osc_astable_mvr(&params);break;
        case 'E':osc_monostable_mvr(&params);break;
        case 'F': printf("Thank you for using the oscillator design section!");exit; break;
        default:flag=-1;break;
    };

    if (flag==1) 
        return osc_success;
    else if (flag==-1) 
        return osc_choice_error; 
    else 
        return osc_failure;
}
/**
 * @brief Defining the calculated circuit design parameters output structure
 * (Extern Variable Check oscillator.h)
 * 
 */
osc_output_val expected_design_values={0.0,0.0,0.0,0.0,0.0,0.0,0.0};

/**
 * @brief To design a RC Phase Shift Oscillator having the 3 RC Networks
 * Output the circuit parameters 
 * @param osc_params Input Parameters taken from the user (Oscillator Frequency and Oscilaltor Amplitude Gain)
 * @return osc_condition Failure--> Null Pointer Error Detected, Limits_error--> Out of Range Values are detected, Success--> Successful Operation
 */
osc_condition osc_rc_phase_shift(osc_input_val* osc_params)
{
    // Condition to check input parameters pointer is an NULL pointer
    if (osc_params==NULL)
    {
        return osc_failure;
    }

    // Condition to check whether the oscillating frequency range or the oscillator amplitude gain range is violated  
    // Minimum amplitude gain of RC Phase Shift Oscillator is 29
    if (osc_params->freq<0.1 || osc_params->freq>1000 || osc_params->Av<29 || osc_params->Av>100)
    {
            printf("\nOut of Range of SpecifiedLimits. Please Check Inputs");
            printf("\n !!! Note : The oscillating frequency range is from 0.1kHz to 1000kHz and amplitude gain range is from 29dB to 100dB\n");
            return osc_limit_error;
    }
    // Structure containing the RC Phase Shift Oscillator circuit design parameters  
    osc_output_val* rc_phase_shift_design_param=malloc(sizeof(osc_output_val));

    // Design Calculations
    // Assuming R1=10kOhms, C=10nF 
    rc_phase_shift_design_param->C=10;
    // CAlculating values of R and R1
    // f = 1 / (2 * pi * R * C * sqrt(6))
    rc_phase_shift_design_param->R=(1000)/(2 * pi * osc_params->freq * rc_phase_shift_design_param->C * rt6);
    //To prevent the loading of the amplifier because of RC networks, it is necessary that R1 >= 10 R. 
    rc_phase_shift_design_param->R1=10 * rc_phase_shift_design_param->R;  
    // Calcualting the value of R2 and C
    // (R2/R1) = Av
    rc_phase_shift_design_param->R2= rc_phase_shift_design_param->R1 *(osc_params->Av);

    //Display all the design parameters of the RC Phase Shift Oscillator Circuit
    printf("The RC Phase Shift Oscillator circuit design parameters are: \n");
    printf("R= %.3f kOhms\n",rc_phase_shift_design_param->R);
    printf("R1= %.3f kOhms\n",rc_phase_shift_design_param->R1);
    printf("R2= %.3f kOhms\n",rc_phase_shift_design_param->R2);

    printf("C= %.3f nF\n",rc_phase_shift_design_param->C);

    printf("\n\nRefer to the RC Phase Shift Oscillator circuit diagram\n");
    // Assigning the calculated value circuit design parameters in the output structure
    // For testing purpose
    expected_design_values = *rc_phase_shift_design_param;
    // Freeing up the output structure containing the RC Phase Oscillator circuit design parameters
    free(rc_phase_shift_design_param);
    
    // Returning the Success condition
    return osc_success;
}

/**
 * @brief To design a Wein Bridge Oscillator
 * Output the circuit parameters 
 * @param osc_params Input Parameters taken from the user (Oscillator Frequency and Oscilaltor Amplitude Gain)
 * @return osc_condition Failure--> Null Pointer Error Detected, Limits_error--> Out of Range Values are detected, Success--> Successful Operation
 */
osc_condition osc_wein_bridge(osc_input_val* osc_params)
{
    // Condition to check input parameters pointer is an NULL pointer
    if (osc_params==NULL)
    {
        return osc_failure;
    }

    // Condition to check whether the oscillating frequency range or the oscillator amplitude gain range is violated  
    // Minimum amplitude gain of Wein Bridge Oscillator is 3
    if (osc_params->freq<0.1 || osc_params->freq>1000 || osc_params->Av<3 || osc_params->Av>100)
    {
            printf("\nOut of Range of SpecifiedLimits. Please Check Inputs");
            printf("\n !!! Note : The oscillating frequency range is from 0.1kHz to 1000kHz and amplitude gain range is from 3 dB to 100 dB\n");
            return osc_limit_error;
    }
    
    // Structure containing the Wein Bridge Oscillator circuit design parameters  
    osc_output_val* wein_bridge_design_param=malloc(sizeof(osc_output_val));
    // Design Calculations
    // Here C is for storing C1 value, C1 is for storing C2 value and R is used for storing R4 value
    // Assuming R1=10kOhms, R3=10kOhms, C1=C=10nF 
    wein_bridge_design_param->C=10;
    wein_bridge_design_param->C1=10;
    wein_bridge_design_param->R1=10;
    wein_bridge_design_param->R3=10;    
    // Calcualting the value of R4 and R2
    // 1 + (R4/R3) = Av
    // f = 1 / (2 * pi * sqrt(R1 * R2 * C1 * C2))
    wein_bridge_design_param->R= wein_bridge_design_param->R3 *(osc_params->Av - 1);
    wein_bridge_design_param->R2=(1000000)/(4 * pi * pi * osc_params->freq * osc_params->freq * wein_bridge_design_param->R1 * wein_bridge_design_param->C * wein_bridge_design_param->C1);
    
    //Display all the design parameters of the Wein Bridge Oscillator Circuit
    printf("The Wein Bridge Oscillator circuit design parameters are: \n");
    printf("R1= %.3f kOhms\n",wein_bridge_design_param->R1);
    printf("R2= %.3f kOhms\n",wein_bridge_design_param->R2);
    printf("R3= %.3f kOhms\n",wein_bridge_design_param->R3);
    printf("R4= %.3f kOhms\n",wein_bridge_design_param->R);

    printf("C1= %.3f nF\n",wein_bridge_design_param->C);
    printf("C2= %.3f nF\n",wein_bridge_design_param->C1);

    printf("\n\nRefer to the Wein Bridge Oscillator circuit diagram\n");
    // Assigning the calculated value circuit design parameters in the output structure
    // For testing purpose
    expected_design_values = *wein_bridge_design_param;
    
    // Freeing up the output structure containing the Wein Bridge Oscillator circuit design parameters
    free(wein_bridge_design_param);
    
    // Returning the Success condition
    return osc_success;
}

/**
 * @brief To design a Colpitts Oscillator
 * Output the circuit parameters 
 * @param osc_params Input Parameters taken from the user (Oscillator Frequency and Oscilaltor Amplitude Gain and Feedback Fraction)
 * @return osc_condition osc_condition Failure--> Null Pointer Error Detected, Limits_error--> Out of Range Values are detected, Success--> Successful Operation 
 */
osc_condition osc_colpitts(osc_input_val* osc_params)
{
    // Condition to check input parameters pointer is an NULL pointer
    if (osc_params==NULL)
    {
        return osc_failure;
    }

    // Condition to check whether the oscillating frequency range or the oscillator amplitude gain range is violated  
    // Minimum amplitude gain of Colpitts Oscillator is 2.9    
    if (osc_params->freq<0.1 || osc_params->freq>1000 || osc_params->Av<2.9 || osc_params->Av>100 || osc_params->beta<0.1 || osc_params->beta>10)
    {
            printf("\nOut of Range of SpecifiedLimits. Please Check Inputs");
            printf("\n !!! Note : The oscillating frequency range is from 0.1kHz to 1000kHz, amplitude gain range is from 2.9 dB to 100 dB and feedback fraction is from 0.1 to 10\n");
            return osc_limit_error;
    }

    // Structure containing the Colpitts Oscillator circuit design parameters  
    osc_output_val* colpitts_design_param=malloc(sizeof(osc_output_val));
    // Design Calculations
    // Here C is for storing C1 value, C1 is for storing C2 value
    // Assuming C=10nF, R1=10kOhms 
    colpitts_design_param->C=0.15;
    colpitts_design_param->R1=10;
   
    // Calcualting the value of C2, R2 and L
    // C2/C1 = beta
    // |R2/R1| = Av
    // f = 1/(a=2* pi* sqrt(L * Ceq))
    // Ceq = (C1 * C2)/(C1 + C2)
    colpitts_design_param->R2= colpitts_design_param->R1 * osc_params->Av;
    colpitts_design_param->C1= colpitts_design_param->C * osc_params->beta;
    float Ceq=(colpitts_design_param->C * colpitts_design_param->C1)/(colpitts_design_param->C + colpitts_design_param->C1);
    colpitts_design_param->L=(1000000)/(4 * pi * pi * osc_params->freq * osc_params->freq * Ceq);
    
    //Display all the design parameters of the Copitts Oscillator Circuit
    printf("The Colpitts Oscillator circuit design parameters are: \n");
    printf("R1= %.3f kOhms\n",colpitts_design_param->R1);
    printf("R2= %.3f kOhms\n",colpitts_design_param->R2);

    printf("C1= %.3f nF\n",colpitts_design_param->C);
    printf("C2= %.3f nF\n",colpitts_design_param->C1);

    printf("L= %.3f mH\n",colpitts_design_param->L);

    printf("\n\nRefer to the Colpitts Oscillator circuit diagram\n");
    // Assigning the calculated value circuit design parameters in the output structure
    // For testing purpose
    expected_design_values = *colpitts_design_param;

    // Freeing up the output structure containing the Colpitts Oscillator circuit design parameters
    free(colpitts_design_param);
    
    // Returning the Success condition
    return osc_success;
}

/**
 * @brief To design a Astable Multivibrator
 * Output the circuit parameters 
 * @param osc_params Input Parameters taken from the user (Oscillator Frequency and Oscilaltor Feedback Fraction)
 * @return osc_condition osc_condition Failure--> Null Pointer Error Detected, Limits_error--> Out of Range Values are detected, Success--> Successful Operation
 */
osc_condition osc_astable_mvr(osc_input_val* osc_params)\
{
    // Condition to check input parameters pointer is an NULL pointer
    if (osc_params==NULL)
    {
        return osc_failure;
    }

    // Condition to check whether the oscillating frequency range or the feedback fraction range is violated  
    if (osc_params->freq<0.1 || osc_params->freq>1000 || osc_params->beta<0.1 || osc_params->beta>10)
    {
            printf("\nOut of Range of SpecifiedLimits. Please Check Inputs");
            printf("\n !!! Note : The oscillating frequency range is from 0.1kHz to 1000kHz and feedback fraction range is from 0.1 to 10\n");
            return osc_limit_error;
    }

    // Structure containing the Astable Multivibrator circuit design parameters  
    osc_output_val* astable_mvr_design_param=malloc(sizeof(osc_output_val));
    // Design Calculations
    // Assuming R1=10kohms and C=10nF
    astable_mvr_design_param->R1=10;
    astable_mvr_design_param->C=10;
    // Calcualting the value of R2
    // beta = R2/(R1 + R2)
    astable_mvr_design_param->R2=(osc_params->beta * astable_mvr_design_param->R1)/(1 - osc_params->beta);
    astable_mvr_design_param->R=(1000)/(2 * osc_params->freq * astable_mvr_design_param->C * log((1 + osc_params->beta)/(1 - osc_params->beta)));

    //Display all the design parameters of the Astable Multivibrator Circuit
    printf("The Astable Multivibrator circuit design parameters are: \n");
    printf("R= %.3f kOhms\n",astable_mvr_design_param->R);
    printf("C= %.3f nF\n",astable_mvr_design_param->C);
    printf("R1= %.3f kOhms\n",astable_mvr_design_param->R1);
    printf("R2= %.3f kOhms\n",astable_mvr_design_param->R2);

    printf("\n\nRefer to the Astable Multivibrator Oscillator circuit diagram\n");
    // Assigning the calculated value circuit design parameters in the output structure
    // For testing purpose
    expected_design_values = *astable_mvr_design_param;

    // Freeing up the output structure containing the Astable Multivibrator circuit design parameters
    free(astable_mvr_design_param);
    
    // Returning the Success condition
    return osc_success;
}

/**
 * @brief To design a Monostable Multivibrator
 * Output the circuit parameters 
 * @param osc_params Input Parameters taken from the user (Oscillator Frequency and Oscilaltor Feedback Fraction)
 * @return osc_condition osc_condition Failure--> Null Pointer Error Detected, Limits_error--> Out of Range Values are detected, Success--> Successful Operation
 */
osc_condition osc_monostable_mvr(osc_input_val* osc_params)
{
    // Condition to check input parameters pointer is an NULL pointer
    if (osc_params==NULL)
    {
        return osc_failure;
    }

    // Condition to check whether the oscillating frequency range or the feedback fraction range is violated  
    if (osc_params->freq<0.1 || osc_params->freq>1000 || osc_params->beta<0.1 || osc_params->beta>10)
    {
            printf("\nOut of Range of SpecifiedLimits. Please Check Inputs");
            printf("\n !!! Note : The oscillating frequency range is from 0.1kHz to 1000kHz and feedback fraction range is from 0 to 10\n");
            return osc_limit_error;
    }
    // Structure containing the Monostable Multivibrator circuit design parameters  
    osc_output_val* monostable_mvr_design_param=malloc(sizeof(osc_output_val));

    // Design Calculations
    // Assuming R1=10kohms and C=10nF
    monostable_mvr_design_param->R1=10;
    monostable_mvr_design_param->C=10;
    // Calcualting the value of R2
    // beta = R2/(R1 + R2)
    monostable_mvr_design_param->R2=(osc_params->beta * monostable_mvr_design_param->R1)/(1 - osc_params->beta);
    monostable_mvr_design_param->R=(1000)/(osc_params->freq * monostable_mvr_design_param->C * log(1 + (monostable_mvr_design_param->R2/monostable_mvr_design_param->R1)));

    //Display all the design parameters of the Monostable Multivibrator Circuit
    printf("The Monostable Multivibrator circuit design parameters are: \n");
    printf("R= %.3f kOhms\n",monostable_mvr_design_param->R);
    printf("C= %.3f nF\n",monostable_mvr_design_param->C);
    printf("R1= %.3f kOhms\n",monostable_mvr_design_param->R1);
    printf("R2= %.3f kOhms\n",monostable_mvr_design_param->R2);

    printf("\n\nRefer to the Monostable Multivibrator circuit diagram\n");
    // Assigning the calculated value circuit design parameters in the output structure
    // For testing purpose
    expected_design_values = *monostable_mvr_design_param;

    // Freeing up the output structure containing the Monostable Multivibrator circuit design parameters
    free(monostable_mvr_design_param);
    
    // Returning the Success condition
    return osc_success;
}
