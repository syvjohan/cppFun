#include "LET.h"

LET::LET(std::string expression) {
	if (expression != "") {
		identifyPartsInExpression(expression);
		calculateExpression();
	}
}

LET::~LET() {

}

void LET::setName(std::string name) {
	this->name = name;
}

void LET::setValue(float value) {

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

std::string LET::getName() {
	return this->name;
}

std::string LET::getValue() {
	return std::to_string(parsedValue);
}

std::string LET::getDatatype() {
	if (this->datatype == 2) {
		return "FLOAT";
	}
	
	return "INT";
}

void LET::identifyPartsInExpression(std::string expression) {
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
				//setValueToBeParsed(expression.substr(typeInt + 3, (expression.length() - typeInt)));

				subdivideValues(expression.substr(typeInt + 3, (expression.length() - typeInt)));
				return;
			}
			else if (requestTypeCast == 2) {
				//setValueToBeParsed(expression.substr(typeFloat + 5, (expression.length() - typeFloat)));

				subdivideValues(expression.substr(typeInt + 3, (expression.length() - typeInt)));
				return;
			}

			//setValueToBeParsed(expression.substr(opEqual + 1, (expression.length() - opEqual)));

			subdivideValues(expression.substr(typeInt + 3, (expression.length() - typeInt)));
		}
	}
}

void LET::subdivideValues(std::string expression) {
	std::vector<float> resultValues;
	std::string value = "";
	std::string lhs = "";
	std::string rhs = "";
	for (int i = 0; i != expression.length(); i++) {
		if (isOperator(expression.at(i))) {
			//find left and right values off op
			lhs = expression.substr(0, i - 1);
			rhs = expression.substr(i + 1, expression.length());

			//transform left and right values to float
			float lNumber = atoi(lhs.c_str());
			float rNumber = atoi(rhs.c_str());

			//calculate the values
			float result = doCalc(lNumber, getOperator(expression.at(i)), rNumber);
			resultValues.push_back(result);

		}









		 //if there is a open parantheses.
			//if true find end paranthese.	
				//copy text between parantheses
				//iterate that part
				//Identify operators and prioritate / and *
				//Calculate values
				//Save value in array
			//if false return wrong in expression syntax.
		//If there is NO parantheses.
			//find first op / or *.
			//identify value to left and right by that op.
			//calculate these values.
			//save in array.
			//Erase this part from expression
			//start to loop from beginning.
			//do it all over untill lenght is 0


	}
}

int LET::calculateExpression() {
	float expression = 0.0f;
	
	bool multValues = false;
	for (int i = 0; i != valueToBeParsed.length(); i++) {
		if (getOperator(valueToBeParsed.at(i)) != ' ') {
			multValues = true;
		}
	}

	//More than one value
	if (multValues) {
		//If expression request RANDOM.
		size_t findRandom = valueToBeParsed.find("RANDOM");
		if (findRandom != std::string::npos) {
			expression = isRandom(findRandom);
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

		float value = std::atoi(str.c_str());
		expression = value;
	}

	//If reguested result is an int or float.
	if (datatype == 1) {
		int i = (int)(expression + 0.5);
		return i;
	}

	return expression;
}

float LET::isRandom(int posRandom) {
	float expression = 0.0f;

	int tmp = 0;
	int findOpLeft = posRandom - 1;
	int findOpRight = posRandom + 6;

	char isOpL = getOperator(valueToBeParsed[findOpLeft]);
	char isOpR = getOperator(valueToBeParsed[findOpRight]);

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

		int index = findOpRight + 1;
		std::string rStr = "";
		while (isdigit(valueToBeParsed[index])) {
			rStr += valueToBeParsed[index];
			++index;
		}

		int rValue = std::atoi(rStr.c_str());
		expression = doCalc(rValue, isOpR, generateRandomNumber());
	}

	return expression;
}

char LET::getOperator(char op) {
	if (op == '+' || op == '-' || op == '/' || op == '*') {
		return op;
	}
	return ' ';
}

bool LET::isOperator(char op) {
	return (op == '+' || op == '-' || op == '/' || op == '*');
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

std::string LET::sortStringForward(std::string str) {
	std::string tmp;
	for (int i = str.length() -1; i >= 0; i--) {
		tmp += str[i];
	}
	str = tmp;
	return str;
}