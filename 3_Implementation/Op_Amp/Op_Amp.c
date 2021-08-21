#include <stdio.h>
void choose()
{
    // Components values for differnt Op-Amp on the Basis which Output Voltage is driven
    double Rf,Rin,Vin,V1;

 char chr;


 printf("****To calculate The output Volatge of various Op-Amp****\n");

// printf("Various Components have their Resistance, input voltage,Etc")


 printf("Enter the value of Rf Resistance: \n");
 scanf("%lf",&Rf);

 printf("Enter the value of Rin  Internal Resistance: \n");
 scanf("%lf",&Rin);

 printf("Enter the value of Vin  input Voltage: \n");
 scanf("%lf",&Vin);

 printf("Enter the value of V1 ref Voltage : \n");
 scanf("%lf",&V1);
 
 
 printf("a.Inverting amplifier \n");

 printf("b.Non inverting-Amplifier \n");

 printf("c.Differntiator \n");

 printf("d.Summing Amplifier\n");
 
 printf("e.Voltage Follower:\n ");



 scanf(" %c",&chr);
 
 switch(chr){
    case 'a':
        printf("Output Volatge of Inverting amplifier is %.1lf ", Rf, Rin,Vin, (Rf/Rin)*Vin);
        break;

    case 'b':
        printf("Output Volatge of Non-Inverting amplifier is  %.1lf", Rf, Rin,Vin, (1+(Rf/Rin)*Vin));
        break;

    case 'c':
        printf("Output Volatge of Differntiator amplifier is  %.1lf", Rf,Rin,Vin,V1, ((Rf/Rin)*(Vin-V1)));
        break;

    case 'd':
        printf("Output Volatge of Summing amplifier is  %.1lf", Rf,Rin,Vin,V1, ((Rf/Rin)*(Vin+V1)));
        break;

    case 'e':   
        printf("gain of a volatge follower is always 1");
        printf("Output Volatge of Voltage Follower is Equal to Vin %.1lf",V1, 1*V1);
        break;

   

    default:
        printf("Error! Wrong Amplifier.");
    }
}
    int main()
    {
        choose();

    
    
    return 0;
} 