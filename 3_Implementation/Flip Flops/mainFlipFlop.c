#include <stdio.h>
#include <stdlib.h>
#include "flip_flop.h"
#include "FlipFlop.c"

int main()
{	char a='y';
	while(a=='y' || a=='Y')
	{
		display();
   		char choice;
		scanf(" %c",&choice);
   		option(choice);
   		printf("\nDo you wish to continue with flip flop menu?(y/n):");
   		scanf(" %c",&a);
	};
	return 0;
}


