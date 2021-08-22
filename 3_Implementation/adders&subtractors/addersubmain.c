#include<stdio.h>
#include "header.h"

int main()
{
    int choice;
    printf("Adders and Subtractors:\nEnter your choice:\n1. Half Adder \n2. Full Adder\n 3. Half Subtractor\n 4. Full subtractor\n");
    scanf("%d",&choice);

    if(choice ==1)
    {
        int i,j,result,carry;
        printf("Input A and b");
        scanf("%d%d",&i,&j);
        
        result=halfadd(i,j);
        carry = halfadd_carry(i,j);
        
        printf("result = %d carry= %d\n",result,carry);
            

    }
    else if (choice==2)
    {
       int i,j,k,sum,cout;
       printf("Input A, b and Cin");
       scanf("%d%d%d",&i,&j,&k);
       sum= Full_Adder_sum(i, j, k);
        cout=Full_Adder_carry(i,j,k);
        printf("Sum = %d, Cout = %d",sum,cout);
    }
    else if(choice ==3)
    {
         int i,j,result,borrow;
        printf("Input A and b");
        scanf("%d%d",&i,&j);
        result=halfsub(i,j);
        borrow = halfsub_b(i,j);
        printf("result = %d borrow = %d\n",result,borrow);

    }
    else if(choice == 4)
    {
        int i,j,k,dif,bout;
        printf("Input A, b and Cin");
        scanf("%d%d%d",&i,&j,&k);
        dif =Full_Subtractor_Dif(i, j, k);
        bout = Full_Subtractor_bout(i,j,k);
        printf("Difference = %d B_Out = %d",dif,bout);

    }
}

 

