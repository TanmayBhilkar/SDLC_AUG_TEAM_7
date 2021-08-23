#include <stdio.h>
#include "capacitor.h"
int output1();
int output2();
int main()
{
    int select;
    printf("\nChoose the combination of capacitors\n\t 1. Series combination\n\t 2. Parallel Combination\n\n");
    scanf("%d", &select);
    choose(select);

    return 0;
}