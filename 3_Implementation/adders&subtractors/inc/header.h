#ifndef __HEADER_H__
#define __HEADER_H__
//halfadder
typedef char bit;
 bit carry=0;
//halfsubtractor
typedef char bit;
   bit borrow=0;

void Full_Adder(int,int,int);
void Full_Subtractor(int,int,int);
 bit halfadd(bit,bit);

bit halfsub(bit,bit);


#endif