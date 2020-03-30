#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"
void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
char* MakeString() {
	int size = 0;
	char* Str = (char*)malloc(size * sizeof(char));
	int i = 0;
	while (10) {
		i = getch();
		if (i == 13) {
			break;
		}
		size++;
		Str = (char*)realloc(Str, size * sizeof(char));
		Str[size] = i;
	}
	return Str;
}
BigInt StrToBigInt(char* String) {
	BigInt Ans;
	Ans.Sign = 0;
	Ans.Size = strlen(String);
	int* Arr = (int*)malloc(Ans.Size * sizeof(int));
	for (int i = 0; i < Ans.Size; i++) {
		if (String[Ans.Size - i - 1] < 48 && String[Ans.Size - i - 1]>57) {
			if (String[Ans.Size - i - 1] == '-') {
				Ans.Size -= 1;
				Ans.Sign == 1;
				Arr = (int*)realloc(Arr, Ans.Sign * sizeof(int));
			}
			else
			{
				printf("ERROR!String have not numbers symbol");
				break;
			}
		}
		Arr[i] = (int)String[Ans.Size - 1 - i] - 48;
	}
	Ans.Arr = Arr;
	return Ans;
}
BigInt ScanBigIntF(char* FileName) {
	BigInt BigI;
	BigI.Sign = 0;
	FILE* f;
	char c = '-';
	fopen_s(&f, FileName, "r");
	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	int* Arr = (int*)malloc(size * sizeof(int));
	fseek(f, 0, SEEK_SET);
	for (int i = 0; i < size; i++) {
		fscanf_s(f, "%c", &c, 1);
		if (c == '-') {
			BigI.Sign = 1;
			size--;
			Arr = (int*)realloc(Arr, size * sizeof(int));
			break;
		}
		Arr[i] = c - 48;
	}
	fclose(f);
	for (int i = 0; i < size / 2; i++) {
		Swap(&Arr[i], &Arr[size - 1 - i]);
	}
	BigI.Size = size;
	BigI.Arr = Arr;
	return BigI;
}
void PrintBigInt(BigInt* a) {
	if (a->Size == 1 && a->Arr[0] == 0) {
		printf("0\n");
		return 0;
	}
	if (a->Sign == 1) {
		printf("-");
	}
	for (int i = a->Size - 1; i >= 0; i--) {
		printf("%d", a->Arr[i]);
	}
	printf("\n");
}
int MaxAbsBigInt(BigInt* a, BigInt* b) {
	if (a->Size > b->Size) {
		return 1;
	}
	else
		if (a->Size < b->Size) {
			return 2;
		}
		else
			if (a->Size == b->Size) {
				for (int i = a->Size - 1; i >= 0; i--) {
					if (a->Arr[i] > b->Arr[i]) {
						return 1;
					}
					else
						if (a->Arr[i] < b->Arr[i]) {
							return 2;
						}
				}
			}
	return 1;
}
int Parity(BigInt* a, BigInt* b) {
	if (a->Size != a->Size) {
		return 0;
	}
	for (int i = 0; i < a->Size; i++) {
		if (a->Arr[i] != b->Arr[i])
			return 0;
	}
	return 1;
}