#include <iostream>

using namespace std;

class Calculator {
	int number1, number2, sum;
public:
	Calculator(int k, int x, int y) : number1(k), number2(x), sum(y) {}

	int Multiplication() {
		sum = number1 * number2;
		return sum;
	}

	int Division(int number1, int number2, int sum) {
		sum = number1 / number2;
		return sum;
	}
};

int main() {
	int number1 = 10;
	int number2 = 20;
	int sum = 0;

	Calculator obj (number1, number2, sum); 	
	Calculator * multi, * divi;
	multi = &obj;
	divi = &obj;

	cout<< multi->Multiplication() <<endl;
}
