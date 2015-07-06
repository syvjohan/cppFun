#pragma once

#include <iostream>
#include <vector>
#include <string>

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

	int tableIndex;

	std::string exchangeVariableNameToValue(std::string expression);
	std::string getDatatype(LETNumber var);

	void table(std::string keyword, std::string expression);
	void evalPRINT(std::string &expression);
	void evalINPUT(std::string &expression);
	void evalIF(std::string &expression);
	void evalGOTO(std::string &expression);
};

