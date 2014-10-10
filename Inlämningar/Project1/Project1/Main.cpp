#include "RationalNumber.h"
#include <iostream>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//RationalNumber<int> rat;
	int a = 2;
	int b = 6;
	int c = 4;
	int d = 9;

	RationalNumber<int> rat(a, b, c, d);
	//printf("%i", rat.Calculate(a, b, c, d));
	



	system("pause");
	return 0;
}