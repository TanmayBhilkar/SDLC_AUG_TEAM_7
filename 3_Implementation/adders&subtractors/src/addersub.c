#include<stdio.h>
#include"header.h"


void Full_Adder(int A,int B,int C_In){
    int Sum , C_Out;
    // Calculating value of sum
    Sum = C_In ^ (A ^ B);
    
    //Calculating value of C-Out
    C_Out = (A & B) || (B & C_In) || (A & C_In);
   
   // printing the values
    printf("%d = ",Sum);
    printf("%d = ",C_Out);
  }

  void Full_Subtractor(int A,int B,int Bin){
   
   // Calculating value of Difference
    int Difference = (A ^ B) ^ Bin;
       
    //calculating NOT  value of a
    int A1 = not(A);
       
    //Calculating value of B-Out
    int B_Out = A1 & Bin | A1 & B | B & Bin;
   
    //printing the values
    printf("Difference = %d",Difference);
    printf("B-Out = %d",B_Out);
   
  }

  bit halfadd(bit A,bit B){
 carry=A&B;
   return A^B;
 }
bit halfsub(bit A,bit B){
 borrow=!A&B;
 return A^B;
      }

