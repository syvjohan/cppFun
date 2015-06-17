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
	std::string tmpExpression = expression;
	int requestTypeCast = 0; //0 = notypecast needed, 1 = typecast to int, 2 = typecast to float, 3 = no typecast was requested.
	for (int i = 0; i != tmpExpression.length(); i++) {

		//find name.
		size_t opEqual = tmpExpression.find_first_of('=');
		if (opEqual != std::string::npos) {
			setName(tmpExpression.substr(0, opEqual));
			tmpExpression.erase(0, opEqual +1);
		}

		//find datatype.
		size_t typeInt = tmpExpression.find("INT");
		size_t typeFloat = tmpExpression.find("FLOAT");
		if (typeInt != std::string::npos) {
			setDataType(tmpExpression.substr(typeInt, typeInt +2));
			tmpExpression.erase(typeInt, typeInt + 2);
			requestTypeCast = 1;
		}
		else if (typeFloat != std::string::npos) {
			setDataType(tmpExpression.substr(typeFloat, typeInt +6));
			tmpExpression.erase(typeFloat, typeFloat + 6);
			requestTypeCast = 2;
		}
		else {
			setDataType("INT");
			requestTypeCast = 3;
		}

		//find value.
		if (opEqual != std::string::npos) {
			if (requestTypeCast == 1) {
				setValueToBeParsed(ManageValueClassification(tmpExpression.substr(typeInt + 3, (tmpExpression.length() - typeInt)), "", 1));
				return;
			}
			else if (requestTypeCast == 2) {
				setValueToBeParsed(ManageValueClassification(tmpExpression.substr(typeInt + 3, (tmpExpression.length() - typeInt)), "", 1));
				return;
			}

			setValueToBeParsed(ManageValueClassification(tmpExpression.substr(typeInt + 1, (tmpExpression.length() - typeInt)), "", 1));
			return;
		}
	}
}

//Recursive function!
std::string LET::ManageValueClassification(std::string expression, std::string subExpression, int opHierarchy) {
	if (findNewParanthesSet) {
		//Identify paranthesis position
		setParanthesisPos(expression);
		findNewParanthesSet = false;
	}
	
	if (parantheses.open != NULL && parantheses.close != NULL) {
		subExpression = expression.substr(parantheses.open + 1, (parantheses.close - 1) - parantheses.open);
		restLeft = expression.substr(0, parantheses.open);
		restRight = expression.substr(parantheses.close +1, (expression.length() - parantheses.close));
		
		expression.erase(parantheses.open, (parantheses.close +1) - parantheses.open);
		insertPos = parantheses.open;

		parantheses.close = NULL;
		parantheses.open = NULL;
	}


	for (int index = 0; index < subExpression.length(); index++) {
		if (validateOperatorType(subExpression.at(index)) == 1 && opHierarchy == 1) {
			subExpression = subdivideValue(subExpression, index);
		}
		else if (validateOperatorType(subExpression.at(index)) == 2 && opHierarchy == 2) {
			subExpression = subdivideValue(subExpression, index);
		}
		else if (validateOperatorType(subExpression.at(index)) == 3 && opHierarchy == 3) {
			//not an operator!
		}
	}

	if (opHierarchy == 1) {
		ManageValueClassification(expression, subExpression, 2);
	}
	else if (opHierarchy == 2) {
		ManageValueClassification(expression, subExpression, 3);
	}
	else {

	}
	
	//Check if there is more to calculate in expression.
 	if (!(isDigits(expression))) {
		expression = "";
		expression.append(restLeft);
		expression.append(subExpression);
		expression.append(restRight);
		
		subExpression = expression;
		restLeft = "";
		restRight = "";

		findNewParanthesSet = true;

		ManageValueClassification(expression, subExpression, 1);
	}
	
	return expression;
}

std::string LET::subdivideValue(std::string expression, int index) {	
	std::string lhs = "";
	std::string rhs = "";
	int posLeft = 0;
	int posRight = 0;
	int nextOp = expression.length();

	//find left value off operator.
	for (int l = index - 1; l >= 0; l--) {
		//If there is a character left of value
		if (isParanthesis(expression[l]) || isOperator(expression[l])) {
			posLeft = l + 1;
			lhs = expression.substr(posLeft, index - (l + 1));
			break;
		}
		//If there is nothing left of value.
		else if (l == 0) {
			posLeft = l;
			lhs = expression.substr(posLeft, index - l);
			break;
		}
	}
			
	//find next operator.
	for (int k = index + 1; k != expression.length(); k++) {
		if (isOperator(expression.at(k))) {
			nextOp = k;
			break;
		}
	}

	//find right value off op
	posRight = nextOp -1;
	rhs = expression.substr(index +1, posRight - index);

	//transform left and right values to float
	float lNumber = atoi(lhs.c_str());
	float rNumber = atoi(rhs.c_str());

	//calculate the values
	float result = doCalc(lNumber, validateOperator(expression.at(index)), rNumber);
	std::string tmpResult = std::to_string(result);

	std::string restLeft = expression.substr(0, posLeft);
	std::string restRight = expression.substr(nextOp, expression.length() - posRight);

	expression = "";
	expression.append(restLeft);
	expression.append(tmpResult);
	expression.append(restRight);

	return expression;
}

int LET::calculateExpression() {
	float expression = 0.0f;
	
	bool multValues = false;
	for (int i = 0; i != valueToBeParsed.length(); i++) {
		if (validateOperator(valueToBeParsed.at(i)) != ' ') {
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

	char isOpL = validateOperator(valueToBeParsed[findOpLeft]);
	char isOpR = validateOperator(valueToBeParsed[findOpRight]);

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

char LET::validateOperator(char op) {
	if (op == '+' || op == '-' || op == '/' || op == '*') {
		return op;
	}
	return ' ';
}

bool LET::isOperator(char op) {
	return (op == '+' || op == '-' || op == '/' || op == '*');
}

int LET::validateOperatorType(char op) {
	if (op == '*' || op == '/') {
		return 1;
	}
	else if (op == '+' || op == '-') {
		return 2;
	}
	return 3;
}

bool LET::isParanthesis(char op) {
	return (op == '(' || op == ')');
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

void LET::setParanthesisPos(std::string str) {
	parantheses.open = NULL;
	parantheses.close = NULL;
	for (int i = 0; i != str.length(); i++) {
		if (str[i] == '(') {
			parantheses.open = i;
		} else if (str[i] == ')') {
			parantheses.close = i;
		}

		if (parantheses.close != NULL && parantheses.open != NULL) { return; }
	}
}

bool LET::isDigits(const std::string str) {
	return str.find_first_not_of("0123456789.") == std::string::npos;
}