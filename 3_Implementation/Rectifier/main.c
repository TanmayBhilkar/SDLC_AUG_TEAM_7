/**
 * @file main.c
 * @author sakshinitnaware
 * @brief 
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include "inc/rect.h"

int main(){
    char option;
    float Vm, Vrpp, Vac;  /* defining variables */
    int eff_choice;
    display();
    printf("\nEnter the code of the Rectifier of your choice: ");
    scanf("%c",&option);                                               // taking input from user to opt for rectifier 
     if (option=='A' || option=='B' || option=='C'){
        printf("\nEnter the values of Vm in volts: ");
        scanf("%f",&Vm);                                                // taking input from user for Vm 
        printf("\nto calculate effeciency \nyes=1/no=0: ");
        scanf("%d",&eff_choice);                                         // taking input from user to opt for calculating efficiency 
        if(eff_choice==1){
            printf("\nEnter the value of Vac: ");
            scanf("%f",&Vac);
        }
    }
    else if (option=='D'){                                              // if user opt for option D rectifier with filter
        printf("\nEnter the values of Vm in volts: ");
        scanf("%f",&Vm);                                                    // scanning valve for Vm
        printf("\nEnter the values of Vrpp in volts: ");
        scanf("%f",&Vrpp);                                              // scanning valve for Vrpp
    }
    else{
        printf("\nenter the correct option from the given table");         // print if the user enters any other option rather than  displayed on the screen
    }
     
    switch (option)                                            // switch case to call function which the user has opt for
    {
        case 'A':
        FWR(Vm,eff_choice,Vac);
        break;

        case 'B':
        HWR(Vm,eff_choice,Vac);
        break;

        case 'C':
        BR(Vm,eff_choice,Vac);
        break;

        case 'D':
        RF(Vm,Vrpp);
        break;

        default: 
          return 0;
    }  
    return 0;

}
