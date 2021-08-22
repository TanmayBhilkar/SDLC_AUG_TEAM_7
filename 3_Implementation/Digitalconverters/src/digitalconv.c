#include<stdio.h>
#include<math.h>
#include"digitalheader.h"

int bintogray(int bin)
{
    if (!bin)
      return 0;
   int a = bin % 10;
   int b = (bin / 10) % 10;
   if ((a && !b) || (!a && b))
      return (1 + 10 * bintogray(bin / 10));
   return (10 * bintogray(bin / 10));
}

int graytobin(int n)
{
    int a[10],i=0,c=0;
    while(n!=0)
    {
        a[i]=n%10;
        n/=10;
        i++;
        c++;
    }
    for(i=c-1;i>=0;i--)
    {
    if(a[i]==1)
    {
    if(a[i-1]==1)
    a[i-1]=0;
    else
    a[i-1]=1;
    }
    }
    printf("\n the binary code is ");
    for(i=c-1;i>=0;i--)
    printf("%d",a[i]);
}

int bcdtox3(int num)
{
    int rem,decimal_num=0,base=1,i,s=0;
    int xt[10];
    while ( num > 0)  
    {  
        rem = num % 10;  
        decimal_num = decimal_num + rem * base;  
        num = num / 10; 
        base = base * 2;  
    }  

    decimal_num+=3;

    for(i=0;decimal_num>0;i++)    
    {    
        xt[i]=decimal_num%2;    
        decimal_num=decimal_num/2;    
    }   
   
         
   while(i)
     {
         
         s+=xt[i-1] *pow(10,i-1);
        --i;
     }
    return s;
}

int x3tobcd(int num)
{
    int rem,decimal_num=0,base=1,i,s=0,bc[10];
   
    while ( num > 0)  
    {  
        rem = num % 10;  
        decimal_num = decimal_num + rem * base;  
        num = num / 10;  
        base = base * 2;  
    }  

    decimal_num-=3;

    for(i=0;decimal_num>0;i++)    
    {    
        bc[i]=decimal_num%2;    
        decimal_num=decimal_num/2;    
    }    
       while(i)
     {
         
         s+=bc[i-1] *pow(10,i-1);
        --i;
     }
    return s;
     
}
