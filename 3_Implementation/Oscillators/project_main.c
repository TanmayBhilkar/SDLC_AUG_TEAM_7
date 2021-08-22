/**
 * @file project_main.c
 * @author Tejas Holla (tejas.holla@ltts.com)
 * @brief Main Program 
 * @version 0.1
 * @date 2021-08-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include "oscillator.h"

int main()
{
    // Call the oscillator circuits menu
    osc_display();
    char osc_choice;
    // User selects the oscillator circuit
    scanf("%c",&osc_choice);
    // Oscillator Circuits Driver Program
    osc_select(osc_choice);

    return 0;
}