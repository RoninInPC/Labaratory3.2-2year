#ifndef H_FUNCTION
#define H_FUNCTION
struct bigint {
	int Sign;
	int Size;
	int* Arr;
};
typedef struct bigint BigInt;
BigInt SumBigInt(BigInt* a, BigInt* b);
BigInt DifBigInt(BigInt* a, BigInt* b);
BigInt PrBigInt(BigInt* a, BigInt* b);
BigInt DivBigInt(BigInt* a, BigInt* b);
#endif