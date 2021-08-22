#include <stdio.h>
#include "header.h"

int main()
{
    int ch;
    printf("\nWhich opamp Do You Want To Use\n\t 1. Voltage Follower\n\t 2. Inverting Summing Amplifier\n\t 3. Non-Inverting Summing Amplifier\n\t 4. Converter current voltage Amplifier\n\n");
    scanf("%d", &ch);
    choice(ch);
    return 0;
}