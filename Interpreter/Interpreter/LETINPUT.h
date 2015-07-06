#pragma once

#include <string>
#include <regex>

class LETINPUT {
public:
	LETINPUT();
	LETINPUT(std::string &expression);
	~LETINPUT();

	std::string getName();
	std::string getValue();
	int getDatatype();

private:
	std::string name;
	std::string parsedValue;
	int datatype; //int = 1, float = 2, string = 3.

	void setName(std::string name);
	void setValue(std::string value);
	void setDataType(int type);

	void identifyPartsInExpression(std::string &expression);
};

