#include<stdio.h>
#include "capacitor.h"
/*int output1();
int output2();*/
int choose(int sel)
{

    switch (sel)
    {
    case 1:
        output1();
        break;

    case 2:
        output2();
        break;

    default:
        printf("Wrong Choice");
    }
}
int output1()
{
    float c[10], num, Cs = 0,Cp = 0;
   int i;
 
   printf("Enter the number of Capacitors : ");
   scanf("%f", &num);
 
   printf("\nEnter Value of Each Capacitor : n");
   for (i = 0; i < num; i++) {
      printf("\nC%d : ", i + 1);
      scanf("%f", &c[i]);
   }
 
   for (i = 0; i < num; i++) {
      Cs = Cs + (1.0 / c[i]);
   }
   Cs = 1.0 / Cs;
 
   printf("\nEquivalent Series Capacitance : %f mFarad", Cs);
    }
int output2()
{
   float c[10], num, Cp = 0;
   int i;
 
   printf("Enter the number of Capacitors : ");
   scanf("%f", &num);
 
   printf("\nEnter Value of Each Capacitor : n");
   for (i = 0; i < num; i++) {
      printf("\nC%d : ", i + 1);
      scanf("%f", &c[i]);
   }
 
   for (i = 0; i < num; i++) {
      Cp = Cp + c[i];
   }
 
   printf("\nEquivalent Parallel Capacitance : %f mFarad", Cp);
   }