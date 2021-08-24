/**
 * @file rect.c
 * @author sakshinitnaware 
 * @brief  
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "rect.h"
#define pi 3.142857143
#define rt2 1.414213562
#define rt3 1.732050807
#define ZeroDivisionError -2
    /**
     * @brief display() to display different rectifiers available
     *  input is charater type
     */
void display_2(void){
    printf("******************************WELCOME******************************\n\n");
    printf("This is a project that will give you the parameters to design different Rectifier.\n");
    printf("Refer the below chart to choose your Rectifier\n");
    printf("A - Full wave rectifier \nB - Half wave rectifier\nC - Bridge Rectifier\n");
    printf("D - Rectifier with filter \n");
    printf("E - Exit \n");
}
/**
 * @brief FWR() is full wave rectifier 
 *          calculates ripple factor and effeciency, input is float type
 * @param Vm 
 * @param eff_choice 
 * @param Vac 
 * @return int 
 */
int FWR( float Vm,int eff_choice,float Vac){     
    float  R, Vrms, Vdc, eff;
    if (Vm>0 && Vm <100){
        printf("Full wave rectifier\n");
        Vrms = Vm/rt2;
        Vdc= 2*Vm/pi;
        R = sqrt((Vrms/Vdc)*(Vrms/Vdc) - 1);
        printf("Vrms is %0.2fV\n",Vrms);
        printf("Vdc is %0.2fV\n",Vdc);
        printf("R is %0.02fV\n",R);
        if (eff_choice==1){
            if (Vac==0){
                printf("Vac cant be 0");
                return ZeroDivisionError;
            }
            else if(Vdc/Vac>1){
                printf("Vac Limits Voilated");
                return -3;
            }
            else{
        
                eff= (Vdc*Vdc)/(Vac*Vac);
                printf("Effenciency is %f",eff);
            }
        }
        return R;
    }
    else {
    printf("Vm Limits voilated");
    return -1;
    }
}

/**
 * @brief HWR() is half wave rectifier
 *          calculates ripple factor and effeciency, input is float type
 * @param Vm 
 * @param eff_choice 
 * @param Vac 
 * @return int 
 */
int HWR(float Vm, int eff_choice,float Vac){
    float  R, Vrms, Vdc, eff;
    if (Vm>0 && Vm<100){
        printf("Half wave rectifier\n");
        Vrms = Vm/2;
        Vdc= Vm/pi;
        R = sqrt((Vrms/Vdc)*(Vrms/Vdc) - 1);
        printf("Vrms is %0.2fV\n",Vrms);
        printf("Vdc is %0.2fV\n",Vdc);
        printf("R is %0.2fV\n",R);
        if (eff_choice==1){
            if (Vac==0){
                printf("Vac cant be 0");
                return ZeroDivisionError;
            }
            else if(Vdc/Vac>1){
            printf("Vac Limits Voilated");
            return -3;
            }
            else{
            eff= (Vdc*Vdc)/(Vac*Vac);
            printf("Effenciency is %f",eff);

            }
        }   
        return R;
    }
    else {
        printf("Vm Limits voilated");
        return -1;
    }
}
/**
 * @brief BR() is Bridge Rectifier
 *        calculates ripple factor and effeciency, input is float type
 * @param Vm 
 * @param eff_choice 
 * @param Vac 
 * @return int 
 */
int BR(float Vm, int eff_choice,float Vac){
    float  R, Vrms, Vdc, eff;
    if (Vm>0 && Vm <100){
        printf("Bridge rectifier\n");
        Vrms = Vm/rt2;
        Vdc= 2*Vm/pi;
        R = sqrt((Vrms/Vdc)*(Vrms/Vdc) - 1);
        printf("Vrms is %0.2fV\n",Vrms);
        printf("Vdc is %0.2fV\n",Vdc);
        printf("R is %0.2fV\n",R);
        if (eff_choice==1){
            if (Vac==0){
                printf("Vac cant be 0");
                return ZeroDivisionError;
            }
            else if(Vdc/Vac>1){
                printf("Vac Limits Voilated");
                return -3;
            }
            else{
        
                eff= (Vdc*Vdc)/(Vac*Vac);
                printf("Effenciency is %f",eff);
            }
        }
        return R;
    }
    else {
    printf("Vm Limits voilated");
    return -1;
    }
}
/**
 * @brief FR() is Filter with Rectifier 
 *          calculates ripple factor, input is float type
 * @param Vm 
 * @param Vrpp 
 * @return int 
 */
int RF(float Vm,float Vrpp){
    float  R, Vrms, Vdc;
        printf("Rectifier with filter\n");
        printf("The Resistance is 0.1k and Capacitance is 100uF for Rectifier with filter\n");
        if (Vm>0 && Vm<100){
            Vrms = Vrpp/2*rt3;
            Vdc= Vm-(Vrpp/2);
            R = Vrms/Vdc;
            printf("Vrms is %0.2fV\n",Vrms);
            printf("Vdc is %0.2fV\n",Vdc);
            printf("R is %0.2fV\n",R);

                return R;
       }
       else {
           printf("Vm Limits Voilated");
           return -1;
       }
}

