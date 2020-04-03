#include"function.h"
#include"mainFunction.h"
#include<stdio.h>
int main(int argc, char* argv[]) {
	printf("Choose Print. Print Number. Number '1' - files 'input.txt', 'input1.txt'. Number '2' - for keyboard. Number '3' - for main\n");
	int exc;
	scanf_s("%d", &exc);
	BigInt c;
	BigInt c1;
	if (exc == 1) {
		c = ScanBigIntF("input.txt");
		c1 = ScanBigIntF("input1.txt");
		PrintBigInt(&c);
		PrintBigInt(&c1);
		printf("\n");
	}
	if (exc == 2) {
		char* str1 = MakeString();
		char* str2 = MakeString();
		c = StrToBigInt(str1);
		c1 = StrToBigInt(str2);
	}
	if (exc == 3) {
		if (argc < 4) {
			return 0;
		}
		c = StrToBigInt(argv[1]);
		c1 = StrToBigInt(argv[2]);
	}
	
	BigInt d = SumBigInt(&c, &c1);PrintBigInt(&d);
	BigInt d1 = DifBigInt(&c, &c1); PrintBigInt(&d1);
	BigInt d2 = PrBigInt(&c, &c1);
	PrintBigInt(&d2);
	BigInt d3 = DivBigInt(&c, &c1);
	PrintBigInt(&d3);
	system("pause");
	return 0;
}