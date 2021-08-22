#include "header.h"
#include<stdio.h>

int Inv(double Rf,double Rin,double Vin)
{
    return (Rf/Rin)*Vin;
}

int Non_inv(double Rf,double Rin,double Vin)
{
    return (1+(Rf/Rin)*Vin);
}
int Diff(double Rf,double Rin,double Vin,double V1)
{
    return ((Rf/Rin)*(Vin-V1));
}
int summ(double Rf,double Rin,double Vin,double V1)
{ 
    return ((Rf/Rin)*(Vin+V1));
}
