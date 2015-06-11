#pragma once

#include <iostream>
#include <vector>

#include "Eval.h"
#include "Scanner.h"
#include "LET.h"

class Manager
{
public:
	Manager();
	~Manager();

	void init();

private:
	vector<LET> variables;
	void table(std::string keyword, std::string expression);
	void evalInput(string str);

};

