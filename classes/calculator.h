#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
	int number1, number2, sum;
public:
	Calculator(int k, int x, int y) : number1(k), number2(x), sum(y) {}

	int Multiplication();
	int Division();

private:
};

#endif // !CALCULATOR_H 