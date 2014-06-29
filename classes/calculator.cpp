#include "calculator.h"

Calculator::Calculator() {}

Calculator::~Calculator() {}

int Calculator::Multiplication(int a, int b) {
	return a * b;
}

int Calculator::Division(int a, int b) {
	
	return a / b;
}

int Calculator::Addition(int a, int b) {
	return a + b;
}

int Calculator::Substraction(int a, int b) {
	return Addition(a, -b);

}