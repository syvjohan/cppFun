#include "LETINPUT.h"

LETINPUT::LETINPUT() {}

LETINPUT::LETINPUT(std::string &expression)
{
	if (expression != "") {
		identifyPartsInExpression(expression);
	}
	else {
		//Empty expression.
	}
}

LETINPUT::~LETINPUT()
{
}

int LETINPUT::getDatatype() {
	if (datatype == 3) {
		return 3;
	}
	else if (datatype == 2) {
		return 2;
	}
	else if (datatype == 1) {
		return 1;
	}

	return 3;
}

std::string LETINPUT::getName() {
	return this->name;
}

std::string LETINPUT::getValue() {
	return this->parsedValue;
}

void LETINPUT::setDataType(int type) {
	if (type == 1) {
		datatype = 1;
	}
	else if (type == 2) {
		datatype = 2;
	}
	else if (type == 3) {
		datatype = 3;
	}
}

void LETINPUT::setName(std::string name) {
	this->name = name;
}

void LETINPUT::setValue(std::string value) {
	this->parsedValue = value;
}

void LETINPUT::identifyPartsInExpression(std::string &expression) {
	//get name
	size_t foundArbitration = expression.find("||");
	setName(expression.substr(0, foundArbitration));

	//get value
	std::string value = expression.substr(foundArbitration + 2, expression.length() - foundArbitration);
	setValue(value);

	//get datatype.
	bool isAlpha = std::regex_match(value, std::regex("^[A-Za-z]+$"));
	size_t isINT = value.find_first_not_of("0123456789");
	size_t isFLOAT = value.find_first_not_of("0123456789.");

	if (isAlpha) {
		setDataType(3);
	}
	else if (isINT == std::string::npos) {
		setDataType(1);
	}
	else if (isFLOAT == std::string::npos) {
		setDataType(2);
	}
}