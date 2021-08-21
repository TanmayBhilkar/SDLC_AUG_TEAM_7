#include"fun.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    char option;
    int a;
    int number;
    
    printf("Enter:\n A for AND Gate \n B for OR Gate \n C for NOT Gate \n D for NAND Gate \n \
E for NOR Gate \n F for XOR Gate \n G for XNOR Gate \n");
    scanf("%c",&option);
    printf("\n Enter the number of inputs: 1 for NOT gate, and 2 or 3 other gates\n");
    scanf("%d",&number);
    
        if(number==1||number==2||number==3)
    {
       
    
    
    int arr[number];
    switch(option)
    {
    case 'a':
    case 'A':
    
    display(number);
    inputs(arr,number);
    ANDgate(arr,number);
    break;
        
    case 'b':
    case 'B':
    
    display(number);
    inputs(arr,number);
        ORgate(arr,number);
    break;
    
    case 'c':
    case 'C':
     
    display(number);
    scanf("%d",&a);
        NOTgate(a);
    break;
    
    case 'd':
    case 'D':
    
    display(number);
    inputs(arr,number);
    NANDgate(arr,number);
    break;
    
    case 'e':
    case 'E':
    
    display(number);
    inputs(arr,number);
    NORgate(arr,number);
    break;
    
    case 'f':
    case 'F':
    
    display(number);
    inputs(arr,number);
    XORgate(arr,number);
    break;
    
    case 'g':
    case 'G':
    display(number);
    inputs(arr,number);
    XNORgate(arr,number);
    break;
    
default:
printf("Please choose a valid option\n");

}
}
else printf("Please enter a valid option\n");
        return 0;
}
