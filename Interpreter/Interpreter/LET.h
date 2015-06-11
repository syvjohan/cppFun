#pragma once

#include <string>

using namespace std;

class LET
{
public:
	LET(std::string expression);
	~LET();

	string getName();
	string getValue();
	string getDatatype();

private:
	std::string name;
	std::string valueToBeParsed;
	int parsedValue;
	int datatype; //float = 2. int = 1.

	void setName(std::string name);
	void setValue(int value);
	void setValueToBeParsed(std::string value);
	void setDataType(std::string type);

	void parseExpression(std::string expression);
	int calculateExpression();

	char isOperator(char op);
	float generateRandomNumber();
	float doCalc(float value1, char op, float value2);

};

