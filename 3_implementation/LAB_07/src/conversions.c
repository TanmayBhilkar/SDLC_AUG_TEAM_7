#include <stdio.h>
#include <stdlib.h>
//#include <link.h>
#include <math.h>
#include <string.h>
#include "conversions.h"
#define MAX 1000
#define ARRAY_SIZE  20


int DEC_BIN(int d)
{
 int a[10],n,i,dtbret;

for(i=0;d>0;i++)
{
a[i]=d%2;
d=d/2;
}
//printf("\nBinary to dec will be =");
for(i=i-1;i>=0;i--)
{
printf("%d",a[i]);
dtbret =a[i];
}
printf("\n");
return dtbret;

}




int DEC_OCTAL(long o)
{
    long decimalnum, remainder, quotient;
    int octalNumber[100], i = 1, j;


    quotient = o;
    while (quotient != 0)
    {
        octalNumber[i++] = quotient % 8;
        quotient = quotient / 8;
    }
    printf("Equivalent octal value of decimal no %ld = ", o);
    for (j = i - 1; j > 0; j--)
        printf("%d", octalNumber[j]);
    return 0;
}

int DEC_HEXA(long h)
{
long decimalnum, quotient, remainder;
    int i, j = 0;
    char hexadecimalnum[100];
    quotient = h;

    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        quotient = quotient / 16;
    }

    // display integer into character
    for (i = j; i >= 0; i--)
            printf("%c", hexadecimalnum[i]);
    return 0;
}

int BIN_DEC(int b)
{
    int binary_num, decimal_num = 0, base = 1, rem;
    binary_num = b; // assign the binary number to the binary_num variable


    while (b > 0)
    {
        rem = b % 10; /* divide the binary number by 10 and store the remainder in rem variable. */
        decimal_num = decimal_num + rem * base;
        b = b / 10; // divide the number with quotient
        base = base * 2;
    }

    printf ( " The binary number is %d \t", binary_num); // print the binary number
    printf (" \n The decimal number is %d \t", decimal_num); // print the decimal
    return 0;
}

int BIN_OCTAL(long bo)
{
    {
    long int octalnum = 0, j = 1, remainder;
    while (bo != 0)
    {
        remainder = bo % 10;
        octalnum = octalnum + remainder * j;
        j = j * 2;
        bo = bo / 10;
    }
    printf("Equivalent octal value: %lo", octalnum);
    return 0;
}
}

int BIN_HEXA(long bh)
{
    long int hexadecimalval = 0, i = 1, remainder;
    while (bh != 0)
    {
        remainder = bh % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        bh = bh / 10;
    }
    printf("Equivalent hexadecimal value: %lX \n", hexadecimalval);
    return 0;
}

int OCTAL_BIN(char *ob)
{
    long i = 0;
    printf("Equivalent binary value: ");
    while (ob[i])
    {
        switch (ob[i])
        {
        case '0':
            printf("000"); break;
        case '1':
            printf("001"); break;
        case '2':
            printf("010"); break;
        case '3':
            printf("011"); break;
        case '4':
            printf("100"); break;
        case '5':
            printf("101"); break;
        case '6':
            printf("110"); break;
        case '7':
            printf("111"); break;
        default:
            printf("\n Invalid octal digit %c ", ob[i]);
            return 0;
        }
        i++;
    }
    return 0;


}


int OCTAL_DEC(long octal)
 
{
 long int decimal = 0;
    int i = 0;
    while (octal != 0)
    {
       decimal =  decimal +(octal % 10)* (long)Cal_pow(8,i);
       i++;
       octal = octal / 10;
    }
   printf("Equivalent decimal value: %ld \n",decimal);
    return 0;

}

int OCTAL_HEXA(int octnum)
{
 int rev=0, rem, count=0, hex=0, mul=1, i=0, k=0;
    char binnum[40] = "", hexnum[40];

    while(octnum!=0)
    {
        rem = octnum%10;
        if(rem>7)
        {
            count++;
            break;
        }
        rev = (rev*10) + rem;
        octnum = octnum/10;
    }
    if(count==0)
    {
        octnum = rev;
        while(octnum!=0)
        {
            rem = octnum%10;
            switch(rem)
            {
                case 0: strcat(binnum, "000");
                    break;
                case 1: strcat(binnum, "001");
                    break;
                case 2: strcat(binnum, "010");
                    break;
                case 3: strcat(binnum, "011");
                    break;
                case 4: strcat(binnum, "100");
                    break;
                case 5: strcat(binnum, "101");
                    break;
                case 6: strcat(binnum, "110");
                    break;
                case 7: strcat(binnum, "111");
                    break;
            }
            octnum = octnum/10;
        }
        while(binnum[k]!='\0')
            k++;
        count=1;
        k--;
        while(k>=0)
        {
            if(binnum[k]=='0')
                rem = 0;
            else
                rem = 1;
            hex = hex + (rem*mul);
            if(count%4==0)
            {
                if(hex<10)
                    hexnum[i] = hex+48;
                else
                    hexnum[i] = hex+55;
                mul = 1;
                hex = 0;
                count = 1;
                i++;
            }
            else
            {
                mul = mul*2;
                count++;
            }
            k--;
        }
        if(count!=1)
            hexnum[i] = hex+48;
        if(count==1)
            i--;
        printf("Equivalent Hexadecimal Value = ");
        count = 0;
        for(i=i; i>=0; i--)
        {
            if(hexnum[i]=='0' && count==0)
            {
                count++;
                continue;
            }
            else
                printf("%c", hexnum[i]);
        }
    }
    else
        printf("\n Invalid Octal Digit %d", rem);
    return 0;

}

int HEXA_BIN(char *hb)
{
 char binarynum[MAX];
    long int i = 0;

    printf("\n Equivalent binary value: ");
    while (hb[i])
    {
        switch (hb[i])
        {
        case '0':
            printf("0000"); break;
        case '1':
            printf("0001"); break;
        case '2':
            printf("0010"); break;
        case '3':
            printf("0011"); break;
        case '4':
            printf("0100"); break;
        case '5':
            printf("0101"); break;
        case '6':
            printf("0110"); break;
        case '7':
            printf("0111"); break;
        case '8':
            printf("1000"); break;
        case '9':
            printf("1001"); break;
        case 'A':
            printf("1010"); break;
        case 'B':
            printf("1011"); break;
        case 'C':
            printf("1100"); break;
        case 'D':
            printf("1101"); break;
        case 'E':
            printf("1110"); break;
        case 'F':
            printf("1111"); break;
        case 'a':
            printf("1010"); break;
        case 'b':
            printf("1011"); break;
        case 'c':
            printf("1100"); break;
        case 'd':
            printf("1101"); break;
        case 'e':
            printf("1110"); break;
        case 'f':
            printf("1111"); break;
        default:
            printf("\n Invalid hexa digit %c ", hb[i]);
            return 0;
        }
        i++;
    }
    return 0;

}



int HEXA_DEC(char *hd)
{
    long long decimal, place;
    int i = 0, val, len;

    decimal = 0;
    place = 1;

    /* Find the length of total number of hex digit */
    len = strlen(hd);
    len--;

    for(i=0; hd[i]!='\0'; i++)
    {

        /* Find the decimal representation of hex[i] */
        if(hd[i]>='0' && hd[i]<='9')
        {
            val = hd[i] - 48;
        }
        else if(hd[i]>='a' && hd[i]<='f')
        {
            val = hd[i] - 97 + 10;
        }
        else if(hd[i]>='A' && hd[i]<='F')
        {
            val = hd[i] - 65 + 10;
        }

        decimal += val * (long)Cal_pow(16, len);
        len--;
    }

    printf("Hexadecimal number = %s\n", hd);
    printf("Decimal number = %lld", decimal);

    return 0;




}

int HEXA_OCTAL(char *ho)
{
    long long octal, bin, place;
    int i = 0, rem, val;

    octal = 0ll;
    bin = 0ll;
    place = 0ll;

    /* Hexadecimal to binary conversion */
    for(i=0; ho[i]!='\0'; i++)
    {
        bin = bin * place;

        switch(ho[i])
        {
            case '0':
                bin += 0;
                break;
            case '1':
                bin += 1;
                break;
            case '2':
                bin += 10;
                break;
            case '3':
                bin += 11;
                break;
            case '4':
                bin += 100;
                break;
            case '5':
                bin += 101;
                break;
            case '6':
                bin += 110;
                break;
            case '7':
                bin += 111;
                break;
            case '8':
                bin += 1000;
                break;
            case '9':
                bin += 1001;
                break;
            case 'a':
            case 'A':
                bin += 1010;
                break;
            case 'b':
            case 'B':
                bin += 1011;
                break;
            case 'c':
            case 'C':
                bin += 1100;
                break;
            case 'd':
            case 'D':
                bin += 1101;
                break;
            case 'e':
            case 'E':
                bin += 1110;
                break;
            case 'f':
            case 'F':
                bin += 1111;
                break;
            default:
                printf("Invalid hexadecimal input.");
        }

        place = 10000;
    }

    place = 1;

    /* Binary to octal conversion */
    while(bin > 0)
    {
        rem = bin % 1000;

        switch(rem)
        {
            case 0:
                val = 0;
                break;
            case 1:
                val = 1;
                break;
            case 10:
                val = 2;
                break;
            case 11:
                val = 3;
                break;
            case 100:
                val = 4;
                break;
            case 101:
                val = 5;
                break;
            case 110:
                val = 6;
                break;
            case 111:
                val = 7;
                break;
        }

        octal = (val * place) + octal;
        bin /= 1000;

        place *= 10;
    }

    printf("Hexadecimal number = %s\n", ho);
    printf("\n Octal number = %lld", octal);

    return 0;
}

long double Cal_pow(int x, int y)
{
    int base, exp;
    long double result = 1.0;
    base=x;
    exp=y;

    while (exp != 0) {
        result *= base;
        --exp;
    }

    return result;
}
