int main()
{
 int i,j,result;
 printf("A   B  |  Sum  Carry\n");
 for(i=0;i<2;i++)
 {
  for(j=0;j<2;j++)
  {
   result=halfadd(i,j);
   printf("%d   %d  |  ",i,j);
   printf("%d   %d\n",result,carry);
  }
 }
 return 0;
}
