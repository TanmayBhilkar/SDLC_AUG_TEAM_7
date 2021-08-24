#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED

#define MAX 1000
#define ARRAY_SIZE  20

long double Cal_pow(int x, int y);
int DEC_BIN(int d);
int DEC_OCTAL(long o);
int DEC_HEXA(long h);
int BIN_DEC(int b);
int BIN_OCTAL(long bo);
int BIN_HEXA(long bh);
int OCTAL_BIN(char *ob);
int OCTAL_DEC(long octal);
int OCTAL_HEXA(int octnum);
int HEXA_BIN(char *hb);
int HEXA_DEC(char *hd);
int HEXA_OCTAL(char *ho);

#endif

