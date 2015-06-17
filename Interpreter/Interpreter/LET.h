#pragma once

#include <string>

class LET
{
public:
	LET(std::string expression);
	~LET();

	std::string getName();
	std::string getValue();
	std::string getDatatype();

private:

	struct Parantheses { int open, close; }parantheses;

	std::string name;
	std::string valueToBeParsed;
	float parsedValue;
	int datatype; //float = 2. int = 1.

	int insertPos;
	std::string restLeft;
	std::string restRight;
	bool findNewParanthesSet;

	void setName(std::string name);
	void setValue(float value);
	void setValueToBeParsed(std::string value);
	void setDataType(std::string type);

	void identifyPartsInExpression(std::string expression);
	int calculateExpression();

	char validateOperator(char op);
	bool isOperator(char op);
	float generateRandomNumber();
	float doCalc(float value1, char op, float value2);
	std::string sortStringForward(std::string str);
	float isRandom(int posRandom);

	std::string subdivideValue(std::string expression, int index);
	std::string ManageValueClassification(std::string expression, std::string str, int opHierarchy);

	int validateOperatorType(char op);
	bool isParanthesis(char op);
	void setParanthesisPos(std::string str);
	bool isDigits(const std::string str);
};

