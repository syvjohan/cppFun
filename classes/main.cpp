#include <iostream>
#include <cstdio>
#include "calculator.h"

using namespace std;

int main() {

	Calculator pCalc;

	printf("Result-Mul : %i\n", pCalc.Multiplication(4,3));
	printf("Result-Div : %i\n", pCalc.Division(12,4));
	printf("Result-Add : %i\n", pCalc.Addition(12,4));
	printf("Result-Div : %i\n", pCalc.Substraction(12,4));

	return 0;
}
