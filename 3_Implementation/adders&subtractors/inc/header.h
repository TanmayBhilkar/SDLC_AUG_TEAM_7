#ifndef __HEADER_H__
#define __HEADER_H__
//halfadder
typedef char bit;
// bit carry=0;
//halfsubtractor
typedef char bit;
  // bit borrow=0;

int Full_Adder_sum(int,int,int);
int Full_Adder_carry(int,int,int);
int Full_Subtractor_Dif(int,int,int);
int Full_Subtractor_bout(int,int,int);
 bit halfadd(bit,bit);
 bit halfadd_carry(bit,bit);

bit halfsub(bit,bit);
bit halfsub_b(bit,bit);


#endif
