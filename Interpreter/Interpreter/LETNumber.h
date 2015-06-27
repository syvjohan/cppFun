#pragma once

#include <string>
#include "Map.h"

class LETNumber
{
public:
	LETNumber(std::string expression);
	~LETNumber();

	std::string getName();
	std::string getValue();
	std::string getDatatype();

private:

	std::string name;
	std::string parsedValue;
	int datatype; //float = 2. int = 1.

	void setName(std::string name);
	void setValue(std::string value);
	void setDataType(std::string type);

	void identifyPartsInExpression(std::string expression);

	char validateOperator(char op);
	bool isOperator(char op);
	float generateRandomNumber();
	float doCalc(float value1, char op, float value2);
	std::string sortStringForward(std::string str);

	std::string& subdivideValue(std::string &expression);

	int validateOperatorType(char op);
	bool isParanthesis(char op);
	bool isNumber(const std::string str);
	std::string transformKeywordsToValues(std::string str);
};

