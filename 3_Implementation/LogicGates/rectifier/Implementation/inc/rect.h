/**
 * @file rect.h
 * @author sakshinitnaware
 * @brief 
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __RECT_H__
#define __RECT_H__

void display(void);
int FWR(float Vm,int eff_choice,float Vac);
int HWR(float Vm, int eff_choice,float Vac);
int BR(float Vm, int eff_choice,float Vac);
int RF(float Vm, float Vrpp);

#endif /*__RECT_H__*/