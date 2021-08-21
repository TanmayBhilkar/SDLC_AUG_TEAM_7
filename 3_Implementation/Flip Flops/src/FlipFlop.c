#include <stdio.h>
#include <stdlib.h>
#include "flip_flop.h"


void display(void)
{
    printf("\nFrom the given choices choose the flip flop you'd like to check the output for: \n");
    printf("A: S R Flip Flop\n");
	printf("B: J K Flip Flop\n");
	printf("C: D Flip Flop\n");
    printf("D: T FLip Flop\n");
}

int option(char c)
{	char g='y';
	switch(c)
	{
		case 'A':
		case 'a':	
			srflipflop();			
			break;
		
		case 'B':
		case 'b':	
			jkflipflop();			
			break;
		
		case 'C':
		case 'c':
			dflipflop();		
			break;
		
		case 'D':
		case 'd':
			tflipflop();	
			break;
		
		default:
			printf("Please enter a valid option");
	}
	return 0;
}

int srflipflop()
{
	printf("Enter S, R, & Q values(enter binary values): ");
	int S,R,Q;
	scanf("%d%d%d",&S,&R,&Q);
	if((S!=0 && S!=1) || (R!=0 && R!=1) || (Q!=0 && Q!=1))
		printf("Please enter a binary value!\n");
	else
		printf("Q(next)=%d\n",S + (!R & ~(Q)));
		printf("Program ended!");
	return 0;
}

int jkflipflop()
{
	printf("Enter J, K, & Q values(enter binary values): ");
	int J,K,Q;
	scanf("%d%d%d",&J,&K,&Q);
	if((J!=0 && J!=1) || (K!=0 && K!=1) || (Q!=0 && Q!=1))
		printf("Please enter a binary value!\n");
	else
		printf("Q(next)=%d\n",J & ~(Q) | Q & ~(K));
		printf("Program ended!\n");
	return 0;
}

int dflipflop()
{
	int D;
	printf("Enter D value(enter binary value): ");
	scanf("%d",&D);
	if((D!=0 && D!=1))
		printf("Please enter a binary value!\n");
	else
		printf("Q(next)=%d\n",D);
		printf("Program ended!\n");
	return 0;
}

int tflipflop()
{
	printf("Enter T & Q values(enter binary values): ");
	int T,Q;
	scanf("%d%d",&T,&Q);
	if((T!=0 && T!=1) || (Q!=0 && Q!=1))
		printf("Please enter a binary value!\n");
	else
		printf("Q(next)=%d\n",T & ~(Q) | Q & ~(T));
		printf("Program ended!\n");
	return 0;
}

