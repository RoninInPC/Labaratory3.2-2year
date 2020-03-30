#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include"function.h"
#include"mainFunction.h"
BigInt SumBigInt(BigInt* a, BigInt* b) {
	BigInt Ans;
	Ans.Sign = 0;
	if (MaxAbsBigInt(a, b) == 2) {
		return SumBigInt(b, a);
	}
	if (a->Sign == 1 && b->Sign == 1) {
		Ans.Sign = 1;
	}
	if (a->Sign == 1 && b->Sign == 0 || a->Sign == 0 && b->Sign == 1) {
			Ans.Sign = a->Sign;
			for (int i = 0; i < b->Size; i++) {
				b->Arr[i] *= (-1);
			}
	}
	Ans.Size = a->Size + 1;
	int* Arr = (int*)malloc(Ans.Size * sizeof(int));
	for (int i = 0; i < Ans.Size; i++) {
		Arr[i] = 0;
	}
	for (int i = 0; i < a->Size; i++) {
		if (i < b->Size) {
			Arr[i] =Arr[i]+ a->Arr[i] + b->Arr[i];
		}
		else
			Arr[i] += a->Arr[i];
		if (Arr[i] < 0) {
			Arr[i] += 10;
			Arr[i + 1] -= 1;
		}
		if (Arr[i] >= 10) {
			Arr[i] -= 10;
			Arr[i + 1] += 1;
		}
	}
	int t = 0;
	for (int i = Ans.Size - 1; i > 0; i--) {
		if (Arr[i] == 0) {
			t++;
		}
		else break;
	}
	if (a->Sign == 1 && b->Sign == 0 || a->Sign == 0 && b->Sign == 1) {
		for (int i = 0; i < b->Size; i++) {
			b->Arr[i] *= (-1);
		}
	}
	Ans.Size -= t;
	Arr = (int*)realloc(Arr, Ans.Size * sizeof(int));
	Ans.Arr = Arr;
	return Ans;
}
BigInt DifBigInt(BigInt* a, BigInt* b) {
	BigInt Copy = *b;
	if (Copy.Sign == 0) {
		Copy.Sign = 1;
	}
	else
		Copy.Sign = 0;
	return SumBigInt(a, &Copy);
}
BigInt PrBigInt(BigInt* a, BigInt* b) {
	BigInt Ans = *a;
	BigInt Copy = *b;
	int* Arr=(int*)malloc(1*sizeof(int));
	Arr[0] = 1;
	BigInt E;
	E.Arr = Arr;
	E.Sign = 0;
	E.Size = 1;
	Copy = DifBigInt(&Copy, &E);
	while (1) {
		if (Copy.Arr[0] == 0 && Copy.Size == 1) break;
		Ans = SumBigInt(&Ans, a);
		Copy = DifBigInt(&Copy, &E);
		
	}
	if (a->Sign == 0 && b->Sign == 1 || a->Sign == 1 && b->Sign == 0) {
		Ans.Sign = 1;
	}
	else
		Ans.Sign = 0;
	return Ans;
}
BigInt DivBigInt(BigInt* a, BigInt* b) {
	int* Arr = (int*)malloc(1 * sizeof(int));
	Arr[0] = 1;
	BigInt E;
	E.Arr = Arr;
	E.Sign = 0;
	E.Size = 1;
	Arr[0] = 0;
	BigInt O;
	O.Arr = Arr;
	O.Sign = 0;
	O.Size = 1;
	BigInt Ans = O;
	BigInt Copy = *a;
	while (MaxAbsBigInt(&Copy, b) == 1) {
		Copy = DifBigInt(&Copy, b);
		Ans = SumBigInt(&Ans, &E);
	}
	if (a->Sign == 0 && b->Sign == 1 || a->Sign == 1 && b->Sign == 0) {
		Ans.Sign = 1;
	}
	else
		Ans.Sign = 0;
	return Ans;
}