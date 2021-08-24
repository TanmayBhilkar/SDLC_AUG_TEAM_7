#include <stdio.h>
#include <stdlib.h>
#include "filter.h"
#include "FlipFlop.h"
#include "Header.h"
#include "LogicGates.h"
#include "rect.h"
#include "oscillator.h"
#include "headers.h"
#include "digitalheader.h"
#include "header1.h"
#include "capacitor.h"

int OpAmpB_main()
{   char a='y';
	while(a=='y' || a=='Y'){
    int ch;
    printf("\nWhich opamp Do You Want To Use\n\t 1. Voltage Follower\n\t 2. Inverting Summing Amplifier\n\t 3. Non-Inverting Summing Amplifier\n\t 4. Converter current voltage Amplifier\n\n");
    scanf("%d", &ch);
    choice(ch);
    printf("\nDo you wish to continue with Op-Amps Part B?(y/n):");
    scanf(" %c",&a);}
    return 0;
}

int filter_main()
{
    char a='y';
	while(a=='y' || a=='Y')
    {
        display();
        char k;
        scanf(" %c",&k);
        choose_filter(k);
        printf("\nDo you wish to continue with design of filters?(y/n):");
        scanf(" %c",&a);
    }
    return 0;
}

int FlipFlop_main()
{
    	char a='y';
	while(a=='y' || a=='Y')
	{
		display_1();
   		char choice;
		scanf(" %c",&choice);
   		option(choice);
   		printf("\nDo you wish to continue with flip flop menu?(y/n):");
   		scanf(" %c",&a);
	}
	return 0;
}

int LogicGates_main()
{
    char j='y';
    while(j=='y'|| j=='Y'){
    char option;
    int a;
    int number;
    
    printf("Enter:\n A for AND Gate \n B for OR Gate \n C for NOT Gate \n D for NAND Gate \n \
E for NOR Gate \n F for XOR Gate \n G for XNOR Gate \n J to EXIT\n");
    scanf(" %c",&option);
    if (option=='A' || option=='a' || option=='B' || option=='b' || option=='C' || option=='c'|| option=='D' || option=='d' || option=='E' || option=='e' || option=='F' || option=='f'|| option=='G'||option=='g')
    {
    printf("\n Enter the number of inputs: 1 for NOT gate, and 2 or 3 other gates\n");
    scanf("%d",&number);
    
    if(number==1||number==2||number==3)
    {
       
    
    
    int arr[number],bincheck=-1;
    switch(option)
    {
    case 'a':
    case 'A':
    
    display_3(number);
    bincheck=inputs(arr,number);
    if(bincheck==0)
    {
    ANDgate(arr,number);
    }
    else 
    printf("\nPlease enter a valid input (Binary: 0 or 1) \n");
    break;
        
    case 'b':
    case 'B':
    
    display_3(number);
    bincheck=inputs(arr,number);
    if(bincheck==0)
    {
    ORgate(arr,number);
    }
    else printf("\nPlease enter a valid input (Binary: 0 or 1) \n");
    break;
    
    case 'c':
    case 'C':
     if(number==1)
    {
        printf("Enter a Binary value\n");
    scanf("%d",&a);
    if(a==1||a==0)
        NOTgate(a);
        }
        else printf("\nPlease enter a valid input!!\n");
    break;
    
    case 'd':
    case 'D':
    
    display_3(number);
    bincheck=inputs(arr,number);
    if(bincheck==0)
    {
    NANDgate(arr,number);
    }
    else printf("\nPlease enter a valid input (Binary: 0 or 1) \n");
    break;
    
    case 'e':
    case 'E':
    
    display_3(number);
    bincheck=inputs(arr,number);
    if(bincheck==0)
    {
    NORgate(arr,number);
    }
    else printf("\nPlease enter a valid input (Binary: 0 or 1) \n");
    break;
    
    case 'f':
    case 'F':
    
    display_3(number);
    bincheck=inputs(arr,number);
    if(bincheck==0)
    {
    XORgate(arr,number);
    }
    else printf("\nPlease enter a valid input (Binary: 0 or 1) \n");
    break;
    
    case 'g':
    case 'G':
    display_3(number);
    bincheck=inputs(arr,number);
    if(bincheck==0)
    {
    XNORgate(arr,number);
    }
    else printf("\nPlease enter a valid input (Binary: 0 or 1) \n");
    break;
    
    default:
    printf("\nPlease choose a valid option\n");
    break;

    }
    }
    else {
        printf("\nPlease enter a valid number as shown\n");
    }
    }
    else if(option=='j'||option=='J')
    return 0;
    else {
        printf("\nPlease enter a valid input!!\n");
    }
    printf("\nDo you wish to continue with logic gates menu?(y/n)\n");
    scanf(" %c",&j);
    }
    return 0;
}
int OpAmps_main() 
{
    char a='y';
	while(a=='y' || a=='Y'){
    int ch;
    double Rf, Rin, res;
    double Vin,V1;
    double res1,res2,res3;

    printf("\nWhich opamp Do You Want To Use\n\t 1. Inverting Amplifier \n\t 2. Non-Inverting Summing Amplifier\n\t 3. Differntiaterr\n\t 4. Summing\n\t");

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
    printf("\nDo you wish to continue with op-amps menu?(y/n):");
   	scanf(" %c",&a);}

    return 0;
}


int Rectifier_main(){
    char a='y';
	while(a=='y' || a=='Y'){
    char option;
    float Vm, Vrpp, Vac;  /* defining variables */
    int eff_choice;
    display_2();
    printf("\nEnter the code of the Rectifier of your choice: ");
    scanf(" %c",&option);                                               // taking input from user to opt for rectifier 
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
    if (option=='E'){
        exit;
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
		    
        case 'E':
        break;
		    
        default: 
        return 0;
    }
    printf("\nDo you wish to continue with Rectifiers menu?(y/n):");
   	scanf(" %c",&a);}
  
    return 0;

}

int Oscillator_main()
{   char a='y';
	while(a=='y' || a=='Y'){
    // Call the oscillator circuits menu
    osc_display();
    char osc_choice;
    // User selects the oscillator circuit
    scanf(" %c",&osc_choice);
    // Oscillator Circuits Driver Program
    osc_select(osc_choice);
    printf("\nDo you wish to continue with Oscillators menu?(y/n):");
   	scanf(" %c",&a);}

    return 0;
}

int DigitalConv_main ()
{   char a='y';
	while(a=='y' || a=='Y'){
    int choice;
    printf("Digital Conversions: \n Select your choice:");
    printf("\n1. Binary to gray \n2. Gray to binary \n3. BCD to excess 3 \n4. Excess 3 to BCD");
    printf("\nChoice:");
    scanf("%d",&choice);
    if(choice == 1)
    {
        int bin, gray;
    
        printf("Enter Binary:");
        scanf("%d",&bin);
        gray = bintogray(bin);
        printf("The gray code of %d is %d\n", bin, gray);
    }

    else if (choice == 2)
    {
        int g;
        printf("Enter the gray code: ");
        scanf("%d", &g);
        graytobin(g);

    }/*
    else if(choice == 3)
    {
        long bcd;
        int *x3,i,xt[10];;
        printf("Enter valid 4bit BCD:");
        scanf("%d",&bcd);
        x3=bcdtox3(bcd,xt);
        printf("\nExcess3 of Given Number is=");    
        for(i=i-1;i>=0;i--)    
        
             printf("%d",x3[i]);

    }
    else if(choice == 4)
    {
        int x,*bcd,i,bc[10];
        printf("Enter valid 4 bit Excess 3 code:");
        scanf("%d",&x);
        bcd =x3tobcd(x,bc);
        printf("\nBCD of Given Number is=");    
        for(i=i-1;i>=0;i--)    
        
             printf("%d",bcd[i]);

    }*/
    printf("\nDo you wish to continue with Digital Conversions menu?(y/n):");
   	scanf(" %c",&a);}
    return 0;
}

int AddersAndSub_main()
{   char a='y';
	while(a=='y' || a=='Y'){
    int choice;
    printf("Adders and Subtractors:\nEnter your choice:\n 1. Half Adder \n 2. Full Adder\n 3. Half Subtractor\n 4. Full subtractor\n");
    scanf("%d",&choice);

    if(choice ==1)
    {
        int i,j,result,carry;
        printf("Input A and B\n");
        scanf("%d%d",&i,&j);
        
        result=halfadd(i,j);
        carry = halfadd_carry(i,j);
        
        printf("result = %d carry= %d\n",result,carry);
            

    }
    else if (choice==2)
    {
       int i,j,k,sum,cout;
       printf("Input A, B and Cin\n");
       scanf("%d%d%d",&i,&j,&k);
       sum= Full_Adder_sum(i, j, k);
        cout=Full_Adder_carry(i,j,k);
        printf("Sum = %d, Cout = %d",sum,cout);
    }
    else if(choice ==3)
    {
         int i,j,result,borrow;
        printf("Input A and B\n");
        scanf("%d%d",&i,&j);
        result=halfsub(i,j);
        borrow = halfsub_b(i,j);
        printf("result = %d borrow = %d\n",result,borrow);

    }
    else if(choice == 4)
    {
        int i,j,k,dif,bout;
        printf("Input A, B and Bin\n");
        scanf("%d%d%d",&i,&j,&k);
        dif =Full_Subtractor_Dif(i, j, k);
        bout = Full_Subtractor_bout(i,j,k);
        printf("Difference = %d B_Out = %d\n",dif,bout);

    }
    printf("\nDo you wish to continue with Adders and Subtractors menu?(y/n):");
   	scanf(" %c",&a);}
    return 0;
}

int cap_main()
{   char a='y';
	while(a=='y' || a=='Y'){
    int select;
    printf("\nChoose the combination of capacitors\n\t 1. Series combination\n\t 2. Parallel Combination\n\n");
    scanf("%d", &select);
    choose(select);
    printf("\nDo you wish to continue with Capacitors menu?(y/n):");
   	scanf(" %c",&a);}

    return 0;
}

int main(){
    char z='y';
	while(z=='y' || z=='Y'){
    printf("**************************  WELCOME  **************************\n");
    printf("This is a project which will help you design and implement various electronics circuits and logics!\n");
    printf("Refer the below chart to use the features with their respective codes:\n");
    printf("A: Design of Filters\nB: Rectifiers\nC: Logic Gates\nD: Oscillators\nE: Op-Amps\n" );
    printf("F: Flip Flops\nG: Op-amps Part B\nH: Digital Converters\nI: Adders and Subtractors\n");
    printf("J: Capacitors\n ");
    printf("Enter a feature you want to use : ");
    char key;
    scanf(" %c",&key);
    switch (key)
    {
        case 'A':
        filter_main();
        break;

        case 'B':
        Rectifier_main();
        break;

        case 'C':
        LogicGates_main();
        break;
        
        case 'D':
        Oscillator_main();
        break;

        case 'E':
        OpAmps_main();
        break;

        case 'F':
        FlipFlop_main();
        break;

        case 'G':
        OpAmpB_main();
        break;

        case 'H':
        DigitalConv_main();
        break;

        case 'I':
        AddersAndSub_main();
        break;

        case 'J':
        cap_main();
        break;

        default:
        printf("\nPlease enter correct code!!\n");
    }
    printf("\nDo you wish to go to the main menu?(y/n):");
   	scanf(" %c",&z);}
}
