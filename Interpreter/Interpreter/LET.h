#pragma once

#include <string>
#include <vector>

class LET
{
public:
	LET(std::string expression);
	~LET();

	std::string getName();
	std::string getValue();
	std::string getDatatype();

private:
	std::string name;
	std::string valueToBeParsed;
	float parsedValue;
	int datatype; //float = 2. int = 1.

	void setName(std::string name);
	void setValue(float value);
	void setValueToBeParsed(std::string value);
	void setDataType(std::string type);

	void identifyPartsInExpression(std::string expression);
	int calculateExpression();

	char getOperator(char op);
	bool isOperator(char op);
	float generateRandomNumber();
	float doCalc(float value1, char op, float value2);
	std::string sortStringForward(std::string str);
	float isRandom(int posRandom);
	void subdivideValues(std::string expression);
};

