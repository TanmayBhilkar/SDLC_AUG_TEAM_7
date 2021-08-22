int main()
{
 int i,j,result;
 printf("A   B  |  Diff  Borrow\n");
 for(i=0;i<2;i++)
 {
  for(j=0;j<2;j++)
  {
   result=halfsub(i,j);
   printf("%d   %d  |   ",i,j);
   printf("%d    %d\n",result,borrow);
   }
  }
 return 0;
}
