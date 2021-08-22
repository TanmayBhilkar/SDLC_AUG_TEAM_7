#include<stdio.h>
#include"header.h"


int Full_Adder_sum(int A,int B,int C_In){
    int Sum ;
    // Calculating value of sum
   return  Sum = C_In ^ (A ^ B);
} 
int Full_Adder_carry(int A,int B,int C_In){
    //Calculating value of C-Out
    int C_Out;
   return C_Out = (A & B) || (B & C_In) || (A & C_In);
   
  }

  int Full_Subtractor_Dif(int A,int B,int Bin){
   
   // Calculating value of Difference
    int Difference = (A ^ B) ^ Bin;
    return Difference;
  }
  int Full_Subtractor_bout(int A,int B,int Bin){
       
    //calculating NOT  value of a
    int A1 = !A;
       
    //Calculating value of B-Out
    int B_Out = A1 & Bin | A1 & B | B & Bin;
   return B_Out;
   
  }

  bit halfadd(bit A,bit B){
   
    return A^B;
 }

 bit halfadd_carry(bit A,bit B){
   return A&B;
    
 }
bit halfsub(bit A,bit B){
    
    return A^B;
}
bit halfsub_b(bit A,bit B){
    return !A&B;
   
}

