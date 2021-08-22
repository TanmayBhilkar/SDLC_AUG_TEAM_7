#include<stdio.h>
#include "Header.h"

/*int Inv(double Rf,double Rin,double Vin)
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
*/
int main() 
{
int ch;
double Rf, Rin, res;
double Vin,V1;
double res1,res2,res3;

    printf("\nWhich opamp Do You Want To Use\n\t 1. Inverting Amplifier \n\t  2. Non-Inverting Summing Amplifier\n\t 3. Differntiaterr\n\t 4. Summing\n\t");

    scanf("%d", &ch);
    switch (ch)
    {
    case 1:

        printf("\nEnter Rf and Rin and Vin \n");
        scanf("%lf%lf%lf",&Rf,&Rin,&Vin);
        res=Inv(Rf,Rin,Vin);
        printf("Vo=%.1lf",res);

        break;

   case 2:

        printf("\nEnter Rf and Rin and Vin  \n");
        scanf("%lf%lf%lf",&Rf,&Rin,&Vin);
        res1=Non_inv(Rf,Rin,Vin);
        printf("Vo=%.1lf",res1);

        break;

    case 3:

        printf("\nEnter Rf and Rin and Vin  and V1\n");
        scanf("%lf%lf%lf%lf",&Rf,&Rin,&Vin,&V1);
        res2=Diff(Rf,Rin,Vin,V1);
        printf("Vo=%.1lf",res2);

        break;

    case 4:

        printf("\nEnter Rf and Rin and Vin and V1 \n");
        scanf("%lf%lf%lf%lf",&Rf,&Rin,&Vin,&V1);
        res3=summ(Rf,Rin,Vin,V1);
        printf("Vo=%.1lf",res3);

        break;

    default:
        printf("Wrong Choice");
    }

    return 0;
}