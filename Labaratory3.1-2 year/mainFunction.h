#ifndef H_MAINFUNCTION
#define H_MAINFUNCTION
#include "function.h"
char* MakeString(); 
BigInt StrToBigInt(char* String);
BigInt ScanBigIntF(char* FileName);
int MaxAbsBigInt(BigInt* a, BigInt* b);
int Parity(BigInt* a, BigInt* b);
void PrintBigInt(BigInt* a);
BigInt ZeroBigInt();
BigInt OneBigInt();
#endif