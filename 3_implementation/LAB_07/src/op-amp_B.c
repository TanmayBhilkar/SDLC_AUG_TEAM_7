#include "headers.h"
#include<stdio.h>

//Function definition for Voltage Follower Amplifier
int vtg_follower(int Av,int Vin)
{
    return Av*Vin;
}

// Function definition for Inverting Summing Amplifier
float inv_sum(float V1,float Av1,float V2, float Av2)
{
    return (V1*Av1)+(V2*Av2);
}

// Function definition for Non-Inverting Summing Amplifier
float non_inv_sum(float r,float vtg_sum)
{
    return (1+(r))*(vtg_sum/3);
}

// Function definition for Converter current voltage Amplifier
float con_cur_vtg(float Vin,float Vi,float I)
{
    return (Vin+Vi-I);
}
// Function definition To Choose op-amp
void choice(int ch)
    {
        int Av, Vin, res;
        float V1, Av1, V2,res1;
        
        float Av2;
        float  Vn, r, vtg_sum = 0;int n;
        float Vi, I,vin;
        
        switch (ch)
        {
        case 1:                               //Voltage follower
            printf("\nEnter Av and Vin\n");
            scanf("%d%d", &Av, &Vin);
            res = vtg_follower(Av, Vin);
            printf("Vo=%d V", res);
            break;

        case 2:                              //Inverting Summing Amplifier
            printf("\nEnter V1,Av1,V2,Av2\n");
            scanf("%f%f%f%f", &V1, &Av1, &V2, &Av2);
            res1 = inv_sum(V1, Av1, V2, Av2);
            printf("Vo=%0.2f V", res1);
            break;

        case 3:                             //Non-Inverting Summing Amplifier
            printf("\nEnter no. of input voltages :  ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter V%d=", i + 1);
                scanf("%f", &Vn);
                vtg_sum += Vn;
            }
            printf("Enter the value of (Rf/Ri) ohm:\n");
            scanf("%f", &r);
            res1 = non_inv_sum(r, vtg_sum);
            printf("Vo=%0.2f V", res1);
            break;
        case 4:                                 //converter current voltage Amplifier
            printf("\nEnter the value of:\nVin\nVi\nI\n");
            scanf("%f\n%f\n%f", &vin, &Vi, &I);
            res1 = con_cur_vtg(vin, Vi, I);
            printf("Vo=%0.2f V", res1);
            break;

        default:
            printf("Wrong Choice");
        }
    }