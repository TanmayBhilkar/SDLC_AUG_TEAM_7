#include <stdio.h>
#include <stdlib.h>
#include "FlipFlop.h"


void display_1(void)
{
    printf("\nFrom the given choices choose the flip flop you'd like to check the output for: \n");
    printf("A: S R Flip Flop\n");
    printf("B: J K Flip Flop\n");
    printf("C: T Flip Flop\n");
    printf("D: D FLip Flop\n");
}

int input_1(int *a,int *b,int *c)
{
	scanf(" %d%d%d",a,b,c);
	return 0;
}

int input_2(int *a, int *b)
{
	scanf(" %d%d",a,b);
	return 0;
}

int input_3(int *a)
{
	scanf(" %d",a);
	return 0;
}

int output(int p)
{
	printf("Q(next)=%d\n",p);
	printf("Program ended!\n");
	return 0;
}

int srflipflop(int x,int y,int z)
{
	if((x!=0 && x!=1) || (y!=0 && y!=1) || (z!=0 && z!=1))
		return -1;
	else
		return (x + (~(y) & z));
}

int jkflipflop(int x,int y,int z)
{	
	if((x!=0 && x!=1) || (y!=0 && y!=1) || (z!=0 && z!=1))
		return -1;
	return (x & ~(z) | z & ~(y));
}

int dflipflop(int x)
{
	if((x!=0 && x!=1))
		return -1;
	return x;
}

int tflipflop(int x,int z)
{
	if((x!=0 && x!=1) || (z!=0 && z!=1))
		return -1;
	return x & ~(z) | z & ~(x);
}

int option(char c)
{	int g;
	char v='y';
	int M,N,Q;
	switch(c)
	{
		case 'A':
		case 'a':
			while(v=='y' || v=='Y')
			{
				printf("Enter S, R, & Q values(enter binary values): ");
				input_1(&M,&N,&Q);
				if((M!=0 && M!=1) || (N!=0 && N!=1) || (Q!=0 && Q!=1))
				{
					printf("Please enter a binary value!\n");
					printf("Do you want to re-enter values?");
					scanf(" %c",&v);
					if(v=='n')
						return 0;
				}
				else
					v='n';
			}
			g=srflipflop(M,N,Q);		
			output(g);	
			break;
		
		case 'B':
		case 'b':	
			while(v=='y' || v=='Y')
			{
				printf("Enter J, K, & Q values(enter binary values): ");
				input_1(&M,&N,&Q);
				if((M!=0 && M!=1) || (N!=0 && N!=1) || (Q!=0 && Q!=1))
				{
					printf("Please enter a binary value!\n");
					printf("Do you want to re-enter values?");
					scanf(" %c",&v);
					if(v=='n')
						return 0;
				}
				else
					v='n';
			}
			g=jkflipflop(M,N,Q);		
			output(g);	
			break;
			
		case 'C':
		case 'c':
			while(v=='y' || v=='Y')
			{
				printf("Enter T & Q values(enter binary values): ");
				input_2(&M,&Q);
				if((M!=0 && M!=1) || (Q!=0 && Q!=1))
				{
					printf("Please enter a binary value!\n");
					printf("Do you want to re-enter values?");
					scanf(" %c",&v);
					if(v=='n')
						return 0;
				}
				else
					v='n';
			}
			g=tflipflop(M,Q);		
			output(g);	
			break;
	
		case 'D':
		case 'd':
			while(v=='y' || v=='Y')
			{
				printf("Enter D value (enter binary value): ");
				input_3(&M);
				if((M!=0 && M!=1))
				{
					printf("Please enter a binary value!\n");
					printf("Do you want to re-enter values?");
					scanf(" %c",&v);
					if(v=='n')
						return 0;
				}
				else
					v='n';
			}
			g=dflipflop(M);		
			output(g);	
			break;
			
		default:
			printf("Please enter a valid option");
	}
	return 0;
}
