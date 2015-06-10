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
			setDataType(expression.substr(typeFloat, typeInt + 2));
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
	//If reguested result is an int or float.
	if (datatype == 1) {
		int(expression) = 0.0f;
	}

	
	for (int i = 0; i != valueToBeParsed.length(); i++) {
		//More than one value
		if (isOperator(valueToBeParsed.at(i))) {

			//If expression request RANDOM.
			size_t random = valueToBeParsed.find("RANDOM");
			if (random != std::string::npos) {
				int tmp = 0;
				size_t findOpLeft = valueToBeParsed.find(random - 1);
				size_t findOpRight = valueToBeParsed.find(random + 7);
				if (findOpLeft != std::string::npos){

					char isOpL = isOperator(valueToBeParsed[findOpLeft]);
					if (isOpL != ' ') {

						int index = findOpLeft + 1;
						std::string lStr = "";
						while (isdigit(valueToBeParsed[index])) {
							lStr += valueToBeParsed[i];
							++index;
						}

						int lValue = std::stoi(lStr, nullptr, 10);
						expression = lValue + isOpL + generateRandomNumber();
					}
				}
				else if (findOpRight != std::string::npos) {
					char isOpR = isOperator(valueToBeParsed[findOpRight]);
					if (isOpR != ' ') {

						int index = findOpRight +1;
						std::string rStr = "";
						while (isdigit(valueToBeParsed[index])) {
							rStr += valueToBeParsed[i];
							++index;
						}

						int rValue = std::stoi(rStr, nullptr, 10);
						expression = rValue + isOpR + generateRandomNumber();
					}
				}

				
			}
		}
		//Only one value.
		else {
			int index = valueToBeParsed.find_first_of('=') +1;
			std::string str = "";
			while (isdigit(valueToBeParsed[index])) {
				str += valueToBeParsed[i];
				++index;
			}

			int value = std::stoi(str, nullptr, 10);
			expression = value;
		}

	}

	return expression;
}

char LET::isOperator(char op) {
	if (op == '+' || op == '-' || op == '/' || op == '*' || op == '%') {
		return op;
	}
	return ' ';
}

float LET::generateRandomNumber() {
	return (rand() / (float)(RAND_MAX + 1));
}