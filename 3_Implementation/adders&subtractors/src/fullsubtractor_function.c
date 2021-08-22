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
