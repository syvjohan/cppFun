#include "LETNumber.h"

LETNumber::LETNumber() {}

LETNumber::LETNumber(std::string &expression) {
	if (expression != "") {
		identifyPartsInExpression(expression);
	}
}

LETNumber::~LETNumber() {

}

void LETNumber::setName(std::string name) {
	this->name = name;
}

void LETNumber::setValue(std::string value) {
	this->parsedValue = value;
}

void LETNumber::setDataType(std::string datatype) {
	if (datatype == "FLOAT") {
		this->datatype = 2;
	}
	else {
		this->datatype = 1;
	}
}

std::string LETNumber::getName() {
	return this->name;
}

std::string LETNumber::getValue() {
	return parsedValue;
}

std::string LETNumber::getDatatype() {
	if (this->datatype == 2) {
		return "FLOAT";
	}
	
	return "INT";
}

void LETNumber::identifyPartsInExpression(std::string &expression) {
	int requestTypeCast = 0; //0 = notypecast needed, 1 = typecast to int, 2 = typecast to float, 3 = no typecast was requested.
	for (int i = 0; i != expression.length(); i++) {

		//find name.
		size_t opEqual = expression.find_first_of('=');
		if (opEqual != std::string::npos) {
			setName(expression.substr(0, opEqual));
			expression.erase(0, opEqual + 1);
		}

		//find datatype.
		size_t typeInt = expression.find("INT");
		size_t typeFloat = expression.find("FLOAT");
		if (typeInt != std::string::npos) {
			setDataType(expression.substr(typeInt, typeInt + 2));
			expression.erase(typeInt, typeInt + 3);
			requestTypeCast = 1;
		}
		else if (typeFloat != std::string::npos) {
			setDataType(expression.substr(typeFloat, typeInt + 6));
			expression.erase(typeFloat, typeFloat + 5);
			requestTypeCast = 2;
		}
		else {
			setDataType("INT");
			requestTypeCast = 3;
		}

		//find value.
		if (opEqual != std::string::npos && opEqual + 1 != expression.length()) {
			expression = transformKeywordsToValues(expression);
			expression = subdivideValue(expression);
			if (expression != "") { 
				setValue(expression); 
			}
			else {
				//Syntax wrong in expression.
			}
		}
		else {
			//Invalid value
		}

		return;
	}
}

std::string& LETNumber::subdivideValue(std::string &expression) {	
	std::string subExpression = "";
	int nextOp = expression.length();
	std::string restInsideParanthes = "";

	size_t openParanthes = expression.find_first_of('(');
	size_t closeParanthes = expression.find_first_of(')');
	//Matching paranthesis
	if (openParanthes != std::string::npos && closeParanthes != std::string::npos) {
		subExpression = expression.substr(openParanthes + 1, (closeParanthes - 1) - openParanthes);

		std::string restAfterParanthesis = "";
		// check if there is some char after close paranthes.
		if (subExpression.length() != closeParanthes) {
			restAfterParanthesis = expression.substr(closeParanthes + 1, expression.length() - closeParanthes); 
		}
			
		//check number of operators.
		int countOp = 0;
		for (int op = 0; op != subExpression.length(); op++) {
			if (isOperator(subExpression[op])) {
				++countOp;
			}
		}

		for (int k = 0; k != subExpression.length(); k++) {
			if (isOperator(subExpression[k])) {

				//find next operator.
				for (int n = k + 1; n != subExpression.length(); n++) {
					if (isOperator(subExpression[n])) {
						nextOp = n;
						break;
					}

					nextOp = subExpression.length();
				}

				//find right value.
				size_t v1 = subExpression.length();
				std::string rhs = subExpression.substr(k + 1, v1 - k);
				float rNumber = atof(rhs.c_str());

				//find left value.
				std::string lhs = subExpression.substr(0, k);
				float lNumber = atof(lhs.c_str());

				// find rest.
				if (nextOp != subExpression.length()) {
					restInsideParanthes = subExpression.substr(nextOp, subExpression.length() - nextOp + 1);
				}

				//calculate the values
				float result = doCalc(lNumber, validateOperator(subExpression.at(k)), rNumber);
				std::string tmpResult = std::to_string(result);

				// create the new expression.
				expression = "";
				expression.append(tmpResult);
				expression.append(restInsideParanthes);
				expression.append(restAfterParanthesis);
				if (countOp > 1) {
					expression.insert(tmpResult.length() + restInsideParanthes.length(), ")");
					expression.insert(0, "(");
				}

				return subdivideValue(expression);
			}
		}
	}
	//Missing parantheses!
	else if (openParanthes == std::string::npos && closeParanthes == std::string::npos) {
		for (int k = 0; k != expression.length(); k++) {
			if (isOperator(expression[k])) {

				//find next operator.
				for (int n = k + 1; n != expression.length(); n++) {
					if (isOperator(expression[n])) {
						nextOp = n;
					}
				}

				//find right value.
				size_t v1 = nextOp;
				std::string rhs = expression.substr(k + 1, v1 - k);
				float rNumber = atof(rhs.c_str());

				//find left value.
				std::string lhs = expression.substr(0, k);
				float lNumber = atof(lhs.c_str());

				// find rest.
				if (nextOp != expression.length()) {
					restInsideParanthes = expression.substr(nextOp - 1, expression.length() - nextOp + 1);
				}
					
				//calculate the values
				float result = doCalc(lNumber, validateOperator(expression.at(k)), rNumber);
				std::string tmpResult = std::to_string(result);

				// create the new expression.
				expression = "";
				expression.append(tmpResult);
				expression.append(restInsideParanthes);

				//Check if there is more to calculate.
				for (int op = 0; op != expression.length(); op++) {
					if (isOperator(expression[op])) {
						subdivideValue(expression);
					}
				}
				break;
			}
		}
	}
	else {
		//paranthesis mismatch!
	}

	 //Invalid expression
	 return expression;
}

char LETNumber::validateOperator(char op) {
	if (op == '+' || op == '-' || op == '/' || op == '*') {
		return op;
	}
	return ' ';
}

bool LETNumber::isOperator(char op) {
	return (op == '+' || op == '-' || op == '/' || op == '*');
}

int LETNumber::validateOperatorType(char op) {
	if (op == '*' || op == '/') {
		return 1;
	}
	else if (op == '+' || op == '-') {
		return 2;
	}
	return 3;
}

bool LETNumber::isParanthesis(char op) {
	return (op == '(' || op == ')');
}

float LETNumber::generateRandomNumber() {
	return (rand() / (float)(RAND_MAX + 1));
}

float LETNumber::doCalc(float value1, char op, float value2) {
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

std::string LETNumber::sortStringForward(std::string str) {
	std::string tmp;
	for (int i = str.length() -1; i >= 0; i--) {
		tmp += str[i];
	}
	str = tmp;
	return str;
}

bool LETNumber::isNumber(const std::string str) {
	return str.find_first_not_of("0123456789.") == std::string::npos;
}

std::string LETNumber::transformKeywordsToValues(std::string str) {

	size_t foundRandom = str.find("RANDOM");
	if (foundRandom != std::string::npos) {
		std::string random = std::to_string(generateRandomNumber());
		str.erase(foundRandom, 6);
		str.insert(foundRandom, random);
	}

	size_t foundPI = str.find("PI");
	if(foundPI != std::string::npos) {
		std::string pi = std::to_string(3.14159265359);
		str.erase(foundPI, 2);
		str.insert(foundPI, pi);
	}
	
	return str;
}