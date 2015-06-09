#pragma once
#include "Parser.h"

#include <string>
#include <iostream>
#include <algorithm>

class Eval {
public:
	Eval(const std::string &expression);
	~Eval();

private:
	void evaluateExpression();
	std::string expression;
	void loopExpression();
};

