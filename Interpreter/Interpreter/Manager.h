#pragma once

#include <iostream>
#include <vector>

#include "Scanner.h"
#include "LETNumber.h"
#include "LETINPUT.h"

class Manager
{
public:
	Manager();
	~Manager();

	void init();

private:
	Scanner scanner;
	std::vector<LETNumber> variablesNUMBER;
	std::vector<LETINPUT> variablesINPUT;
	void table(std::string keyword, std::string expression);
	void evalPRINT(std::string str);
	void evalINPUT(std::string &str);
	void evalIF(std::string &str);
};

