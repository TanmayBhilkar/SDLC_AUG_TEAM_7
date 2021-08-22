#include "LogicGates.h"
#include <stdio.h>
#include <stdlib.h>
  int display_3(int number)
{
    printf("enter %d space seperated binary values\n", number);
    return 0;
}

  int inputs(int *arr,int number)
{   
        for(int i=0;i<number;i++)
        scanf("%d",&arr[i]);
            return 0;
}
int ANDgate(int *arr,int number)
{
     int value=1;
  // AND 
  for(int i=0;i<number;i++)
        value &= arr[i];
        printf("\n Result = %d ", value);
        return value;
}

int ORgate(int *arr,int number)
{
     int value=0;
       
    // OR 
   for(int i=0;i<number;i++)
        value |= arr[i];
        printf("\n Result = %d ", value);
    return value;
        
}

int NOTgate(int a)
{
   
    //   OR
            printf("\n NOT %d = %d", a,!a);
            return !a;

}

int NANDgate(int *arr,int number)
{
    int value=1;
      
    // NAND 
    for(int i=0;i<number;i++)
        value &= arr[i];
        printf("\n Result = %d ", !value);
    return !value;
}

int NORgate(int *arr,int number)
{
    int value=0;
      
    // NOR 
    for(int i=0;i<number;i++)
        value |= arr[i];
        printf("\n Result = %d ", !value);
    return !value;
}

int XORgate(int *arr,int number)
{
    int value=0;
       
    // XOR 
    for(int i=0;i<number;i++)
        value ^= arr[i];
        printf("\n Result = %d ", value);
    return value;
        
}

int XNORgate(int *arr, int number)
{
    int value=0;
       
    // XNOR 
    for(int i=0;i<number;i++)
        value ^= arr[i];
        printf("\n Result = %d ", !value);
    return !value;
        
}
