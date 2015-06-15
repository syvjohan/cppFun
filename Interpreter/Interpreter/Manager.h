#pragma once

#include <iostream>
#include <vector>

#include "Scanner.h"
#include "LET.h"

class Manager
{
public:
	Manager();
	~Manager();

	void init();

private:
	Scanner scanner;
	std::vector<LET> variables;
	void table(std::string keyword, std::string expression);
	void evalInput(std::string str);

};

