#include <iostream>
#include "calculator.h"

using namespace std;

int main() {
	int number1 = 10;
	int number2 = 20;
	int sum = 0;

	Calculator calc (number1, number2, sum); 	
	Calculator * multi, * divi;
	multi = &calc;
	divi = &calc;

	cout<< multi->Multiplication() <<endl;
	cout<< divi->Division() <<endl;
}
