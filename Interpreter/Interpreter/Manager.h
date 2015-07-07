#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>

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
	std::vector<LET> variablesNUMBER;

	int tableIndex;

	std::string exchangeVariableNameToValue(std::string expression);
	std::string getDatatype(LET var);
	void overwriteOldVariableValue(LET *newVar);
	size_t getCompareOperatorPos(std::string *expression);

	void table(std::string keyword, std::string expression);
	void evalPRINT(std::string &expression);
	void evalINPUT(std::string &expression);
	void evalLET(std::string &expression);
	void evalIF(std::string &expression);
	void evalGOTO(std::string &expression);
};

