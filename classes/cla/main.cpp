#include <iostream>
#include <cstdio>

using namespace std;

class Calculator {

public:
int Multiplication(int a, int b) {
	return a * b;
}

int Division(int a, int b) {
	return a / b;
}

int Addition(int a, int b) {
	return a + b;
}
int Substraction(int a, int b) {
	return Addition(a, -b);
}

private:
};

int main() {

	Calculator calcObj;
	Calculator *pCalc;
	pCalc = &calcObj;

	printf("Result-Mul : %i\n", pCalc->Multiplication(4,3));
	printf("Result-Div : %i\n", pCalc->Division(12,4));
	printf("Result-Add : %i\n", pCalc->Addition(12,4));
	printf("Result-Div : %i\n", pCalc->Substraction(12,40));

	return 0;
}