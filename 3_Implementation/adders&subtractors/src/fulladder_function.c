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
