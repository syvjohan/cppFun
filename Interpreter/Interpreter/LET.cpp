#include "LET.h"

LET::LET(std::string expression) {
	if (expression != "") {
		parseExpression(expression);
		calculateExpression();
	}
}


LET::~LET()
{
}

void LET::setName(std::string name) {
	this->name = name;
}

void LET::setValue(int value) {

}

void LET::setValueToBeParsed(std::string str) {
	this->valueToBeParsed = str;
}

void LET::setDataType(std::string datatype) {
	if (datatype == "FLOAT") {
		this->datatype = 2;
	}
	else {
		this->datatype = 1;
	}
}

string LET::getName() {
	return this->name;
}

string LET::getValue() {
	return to_string(parsedValue);
}

string LET::getDatatype() {
	if (this->datatype == 2) {
		return "FLOAT";
	}
	
	return "INT";
}

void LET::parseExpression(std::string expression) {
	int requestTypeCast = 0; //0 = notypecast needed, 1 = typecast to int, 2 = typecast to float, 3 = no typecast was requested.
	for (int i = 0; i != expression.length(); i++) {

		//find name.
		size_t opEqual = expression.find_first_of('=');
		if (opEqual != std::string::npos) {
			setName(expression.substr(0, opEqual));
		}

		//find datatype.
		size_t typeInt = expression.find("INT");
		size_t typeFloat = expression.find("FLOAT");
		if (typeInt != std::string::npos) {
			setDataType(expression.substr(typeInt, typeInt + 2));
			requestTypeCast = 1;
		}
		else if (typeFloat != std::string::npos) {
			setDataType(expression.substr(typeFloat, typeInt + 6));
			requestTypeCast = 2;
		}
		else {
			setDataType("INT");
			requestTypeCast = 3;
		}

		//find value.
		if (opEqual != std::string::npos) {

			if (requestTypeCast == 1) {
				setValueToBeParsed(expression.substr(typeInt + 3, (expression.length() - typeInt)));
				return;
			}
			else if (requestTypeCast == 2) {
				setValueToBeParsed(expression.substr(typeFloat + 1, (expression.length() - typeFloat)));
				return;
			}

			setValueToBeParsed(expression.substr(opEqual + 1, (expression.length() - opEqual)));
		}
	}
}

int LET::calculateExpression() {
	float expression = 0;
	
	bool multValues = false;
	for (int i = 0; i != valueToBeParsed.length(); i++) {
		if (isOperator(valueToBeParsed.at(i)) != ' ') {
			multValues = true;
		}
	}

		//More than one value
		if (multValues) {

			//If expression request RANDOM.
			size_t findRandom = valueToBeParsed.find("RANDOM");
			if (findRandom != std::string::npos) {
				int tmp = 0;
				int findOpLeft = findRandom - 1;
				int findOpRight = findRandom + 6;

				char isOpL = isOperator(valueToBeParsed[findOpLeft]);
				char isOpR = isOperator(valueToBeParsed[findOpRight]);

				if (isOpL != ' ') {

					int index = findOpLeft - 1;
					std::string lStr = "";
					while (isdigit(valueToBeParsed[index])) {
						lStr += valueToBeParsed[index];
						--index;
					}

					int lValue = std::atoi(sortStringForward(lStr).c_str());
					expression = doCalc(lValue, isOpL, generateRandomNumber());

				}
				else if (isOpR != ' ') {

						int index = findOpRight +1;
						std::string rStr = "";
						while (isdigit(valueToBeParsed[index])) {
							rStr += valueToBeParsed[index];
							++index;
						}

						int rValue = std::atoi(rStr.c_str());
						expression = doCalc(rValue, isOpR, generateRandomNumber());
				}

				
			}
		}
		//Only one value.
		else {
			int index = valueToBeParsed.find_first_of('=') +1;
			std::string str = "";
			while (isdigit(valueToBeParsed[index])) {
				str += valueToBeParsed[index];
				++index;
			}

			int value = std::atoi(str.c_str());
			expression = value;
		}

	//If reguested result is an int or float.
	if (datatype == 1) {
		int i = (int)(expression + 0.5);
		return i;
	}

	return expression;
}

char LET::isOperator(char op) {
	if (op == '+' || op == '-' || op == '/' || op == '*') {
		return op;
	}
	return ' ';
}

float LET::generateRandomNumber() {
	return (rand() / (float)(RAND_MAX + 1));
}

float LET::doCalc(float value1, char op, float value2) {
	float result = 0.0f;
	switch (op) {
		case '*':
			result = value1 * value2;
			break;
		case '/':
			result = value1 / value2;
			break;
		case '+':
			result = value1 + value2;
			break;
		case '-':
			result = value1 - value2;
			break;
	}

	return result;
}

string LET::sortStringForward(std::string str) {
	string tmp;
	for (int i = str.length() -1; i >= 0; i--) {
		tmp += str[i];
	}
	str = tmp;
	return str;
}