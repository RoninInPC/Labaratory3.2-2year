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
		Arr[i] += a->Arr[i];
	}
	for (int i = 0; i < b->Size; i++) {
		Arr[i] += b->Arr[i];
	}
	for (int i = 0; i < Ans.Size; i++) {
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
	BigInt Ans;
	if (b->Size == 1 && b->Arr[0] == 0) {
		return *b;
	}
	if (a->Size == 1 && a->Arr[0] == 0) {
		return *a;
	}
	if (MaxAbsBigInt(a, b) == 2) {
		return PrBigInt(b, a);
	}
	Ans.Size = a->Size + b->Size;
	int* Arr = (int*)malloc(Ans.Size * sizeof(int));
	for (int i = 0; i < Ans.Size; i++) Arr[i] = 0;
	for (int i = 0; i < b->Size; i++) {
		for (int j = 0; j < a->Size; j++) {
			Arr[i + j] += a->Arr[j] * b->Arr[i];
		}
	}
	for (int i = 0; i < Ans.Size - 1; i++) {
		Arr[i + 1] += Arr[i] / 10;
		Arr[i] %= 10;
	}
	int t = 0;
	for (int i = Ans.Size - 1; i > 0; i--) {
		if (Arr[i] == 0) {
			t++;
		}
		else break;
	}
	Ans.Size -= t;
	Arr = realloc(Arr, Ans.Size * sizeof(int));
	Ans.Arr = Arr;
	Ans.Sign = (a->Sign + b->Sign) % 2;	
	return Ans;
}
BigInt DivBigInt(BigInt* a, BigInt* b) {
	BigInt Ans;
	BigInt E;
	E.Size = 1;
	int* Arr = (int*)malloc(E.Size*sizeof(int));
	Arr[0] = 1;
	Arr = (int*)realloc(Arr, sizeof(int));
	E.Sign = 0;
	E.Arr = Arr;
	int* Arr1 = (int*)malloc(E.Size * sizeof(int));
	Arr1 = (int*)realloc(Arr1, sizeof(int));
	Arr1[0] = 0;
	Ans.Sign = 0;
	Ans.Size = 1;
	Ans.Arr = Arr1;
	int i = 0;
	BigInt E1 = E;
	while (1) {
		BigInt IF = PrBigInt(&Ans, b);
		Ans = SumBigInt(&Ans, &E);
		if (i == 10) {
			E = SumBigInt(&E, &E);
			i = 0;
		}
		if (MaxAbsBigInt(a, &IF) == 2) {
			break;
		}
		i++;
	}
	while (1) {
		BigInt IF = PrBigInt(&Ans, b);
		if (MaxAbsBigInt(a, &IF) == 1) {
			break;
		}
		Ans = DifBigInt(&Ans, &E1);
	}
	int t = 0;
	for (int i = Ans.Size - 1; i > 0; i--) {
		if (Arr[i] == 0) {
			t++;
		}
		else break;
	}
	Ans.Size -= t;
	Arr = realloc(Arr, Ans.Size * sizeof(int));
	Ans.Sign = (a->Sign + b->Sign) % 2;
	return Ans;
}