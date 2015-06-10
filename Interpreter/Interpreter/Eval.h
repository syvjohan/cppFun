#pragma once
#include "Parser.h"

#include <string>
#include <iostream>
#include <algorithm>

class Eval {
public:
	Eval();
	~Eval();

	int evaluateExpression(std::string line);

private:
	std::string expression;

	void loopExpression();
	std::string calculateExpression();
};

