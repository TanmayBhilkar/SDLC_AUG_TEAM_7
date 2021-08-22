#include <stdio.h>
#include <math.h>
#include "digitalheader.h"

int main ()
{
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
        return 0;
    }

    else if (choice == 2)
    {
        int g;
        printf("Enter the gray code: ");
        scanf("%d", &g);
        graytobin(g);

    }
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

    }
}
 
