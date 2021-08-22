#include<stdio.h>

int main()
{
    int c;
    printf("Adders and Subtractors:\nEnter your choice:\n1. Half Adder \n2. Full Adder\n 3. Half Subtractor\n 4. Full subtractor\n")
    scanf("%d.&c");

    if(choice ==1)
    {
        int i,j,result;
        printf("Input A and b");
        scanf("%d%d",&i,&j);
        
        result=halfadd(i,j);
        printf("%d   %d  |  ",i,j);
        printf("%d   %d\n",result,carry);
            

    }
    else if (choice==2)
    {
       int i,j,k;
       printf("Input A, b and Cin");
       scanf("%d%d%d",&i,&j,&k);
        Full_Adder(i, j, k);

    }
    else if(choice ==3)
    {
         int i,j,result;
        printf("Input A and b");
        scanf("%d%d",&i,&j);
        result=halfsub(i,j);
        printf("%d   %d  |   ",i,j);
        printf("%d    %d\n",result,borrow);

    }
    else if(choice == 4)
    {
        int i,j,k;
        printf("Input A, b and Cin");
        scanf("%d%d%d",&i,&j,&k);
        Full_Subtractor(i, j, k);
}
    }
}

 

