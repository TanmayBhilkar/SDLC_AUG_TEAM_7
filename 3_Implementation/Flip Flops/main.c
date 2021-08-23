#include <stdio.h>
#include <stdlib.h>
#include "FlipFlop.h"
#include "FlipFlop.c"

int main()
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
