#include "Rational.h"
#include <iostream>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	Rational<int> rat(1,1);
	
	const int a = 2;
	const int b = 6;
	const int c = 4;
	const int d = 9;
	
	//printf("%i",rat + Rational<int>(4, 3));

	system("pause");
	return 0;
}

