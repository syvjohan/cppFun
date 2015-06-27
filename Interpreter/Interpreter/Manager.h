#pragma once

#include <iostream>
#include <vector>

#include "Scanner.h"
#include "LETNumber.h"
#include "LETString.h"

class Manager
{
public:
	Manager();
	~Manager();

	void init();

private:
	Scanner scanner;
	std::vector<LETNumber> variables;
	void table(std::string keyword, std::string expression);
	void evalInput(std::string str);

};

