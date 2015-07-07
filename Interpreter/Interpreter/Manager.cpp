#include "Manager.h"

Manager::Manager() {
	
}

Manager::~Manager()
{
}

void Manager::init() {
	scanner.readFile("1.1Instructions.txt"); //code file to be read from!

	int len = scanner.length();
	for (tableIndex = 0; tableIndex != len; tableIndex++) {
		table(scanner.getInstructionAt(tableIndex).first, scanner.getInstructionAt(tableIndex).second);
	}
}

void Manager::table(std::string keyword, std::string expression) {
	if (keyword == "PRINT") {
		evalPRINT(expression);
	}
	else if (keyword == "LET") {
		evalLET(expression);
	}
	else if (keyword == "INPUT") {
		evalINPUT(expression);
	}
	else if (keyword == "IF") {
		evalIF(expression);
	}
	else if (keyword == "GOTO") {
		evalGOTO(expression);
	}
	else if (keyword == "END") {
		std::this_thread::sleep_for(std::chrono::milliseconds(50000));
		exit(0);
	}
	else if (keyword == "FOR") {
		evalFOR(expression);
	}
	else {
		return;
	}
}

void Manager::evalPRINT(std::string &expression) {
	expression = exchangeVariableNameToValue(expression);
	expression = exchangeVariableNameToValue(expression);
	size_t foundSemicolon = expression.find(';');
	if (foundSemicolon != std::string::npos) {
		expression = expression.erase(expression.length() -1, 1);
		std::cout << expression;
	}
	else {
		std::cout << expression << std::endl;
	}
}

void Manager::evalLET(std::string &expression) {
	expression = exchangeVariableNameToValue(expression);
	
	LET *var = new LET(expression);
	overwriteOldVariableValue(var);
}

void Manager::evalINPUT(std::string &expression) {
	std::string input = "";
	std::cin.clear();
	std::getline(std::cin, input);

	expression.append("||");
	expression.append(input);

	LET *var = new LET(expression);

	overwriteOldVariableValue(var);
}

void Manager::evalIF(std::string &expression) {

	LET var1;
	LET var2;
	LET *tmp = nullptr;

	size_t foundVar2 = -1;
	size_t foundVar1 = -1;

	bool isVariable1 = false;
	bool isVariable2 = false;

	//get first variable.
	for (int i = 0; i != variables.size(); i++) {
		foundVar1 = expression.find(variables.at(i).getName());
		if (foundVar1 != std::string::npos && foundVar1 < getCompareOperatorPos(&expression)) {
			var1 = variables.at(i);
			isVariable1 = true;
			break;
		}
	}
	
	//get second variable.
	for (int k = 0; k != variables.size(); k++) {
		foundVar2 = expression.find(variables.at(k).getName());
		if (foundVar2 != std::string::npos && foundVar2 > getCompareOperatorPos(&expression)) {
			var2 = variables.at(k);
			isVariable2 = true;
			break;
		}
	}

	//If compared values are no variables instead they are hardcoded values.
	std::string value = "";
	size_t foundOp = getCompareOperatorPos(&expression);
	size_t foundTHEN = expression.find("THEN");
	if (!isVariable2) {
		if (foundOp != std::string::npos && foundTHEN != std::string::npos) {
			value = expression.substr(foundOp + 1, foundTHEN - foundOp - 1);
		}
	}
	else if (!isVariable1) {
		if (foundOp != std::string::npos && foundTHEN != std::string::npos) {
			value = expression.substr(0, foundOp);
		}
	}
	else {
		//syntax error, problem with equal operator and keyword THEN.
	}

	if (!isVariable1 || !isVariable2) {
		std::string newExpression = "";
		//is value a string or a number. 
		bool isAlpha = std::regex_match(value, std::regex("^[A-Za-z]+$"));
		size_t isNumber = value.find_first_not_of("0123456789.");

		//If it is text
		if (isAlpha) {
			newExpression.append("tmp");
			newExpression.append("=");
			newExpression.append(value);
			tmp = new LET(newExpression);
		}
		//if it is a number.
		else if (isNumber != std::string::npos) {
			newExpression.append("tmp");
			newExpression.append(value);
			tmp = new LET(newExpression);
		}
		else {
			//syntax error, numbers and letters are mixed!
		}

		// create a temporary variable.
		if (!isVariable1) {
			var1 = *tmp;
		}
		else {
			var2 = *tmp;
		}
	}
	
	//compare datatypes.
	if (var1.getDatatype() != var2.getDatatype()) {
		// cannot compare different datatypes.
	}
	else {
		//get operator.
		if (var1.getValue() != "" && var2.getValue() != "") {
			size_t findOpGreater = expression.find('>');
			size_t findOpLess = expression.find('<');
			size_t findOpEqual = expression.find("=");

			//comapre variables.
			bool result = false;
			if (findOpGreater != std::string::npos) {
				result = var1.getValue() > var2.getValue();
			}
			else if (findOpLess != std::string::npos) {
				result = var1.getValue() < var2.getValue();
			}
			else if (findOpEqual != std::string::npos) {
				result = var1.getValue() == var2.getValue();
			}
			else {
				result = false;
				//No operator was found
			}

			if (result) {
				//get linenumber.
				size_t line = expression.find_first_of("0123456789");
				if (line != expression.length() && line != std::string::npos) {
					std::string linenumber = expression.substr(line, expression.length() - line);
					
					//GOTO that line
					table("GOTO", linenumber);
				}
				else {
					// Line number is missing
				}
			}
			else {
				// Move to next line.
			}
		}
		else {
			//syntax error variables to compare has not been defined!
		}
	}

	delete tmp;
	tmp = NULL;
}

void Manager::evalGOTO(std::string &expression) {
	int len = scanner.length();
	std::string linenumber = "";
	for (int i = 0; i != len; i++) {
		linenumber = scanner.getLinenumber(i);
 		if (linenumber == expression) {
			std::string value = scanner.getInstructionAt(i).second;
			std::string key = scanner.getInstructionAt(i).first;

			// get instruction index.
			tableIndex = scanner.getIndex(std::stoi(linenumber));

			table(key, value);
			break;
		}
	}
	// Line has not been defiend, cannot goto undefiend line.
}

void Manager::evalFOR(std::string &expression) {
	size_t foundOpEqual = expression.find("=");
	size_t foundTO = expression.find("TO");
	if (foundOpEqual && foundTO != std::string::npos && foundTO != expression.length()) {
		//create increment variable
		std::string incrementVarName = expression.substr(0, foundOpEqual);
		std::string incrementVarValue = expression.substr(foundOpEqual + 1, foundTO - foundOpEqual -1);
		std::string incrementVar = "";
		incrementVar.append(incrementVarName).append("=").append(incrementVarValue);
		LET *var = new LET(incrementVar);
		variables.push_back(*var);

		//stop value.
		std::string stopVar = expression.substr(foundTO + 1, expression.length() - foundTO);
		bool isAlpha = std::regex_match(stopVar, std::regex("^[A-Za-z]+$"));
		size_t isNumber = stopVar.find_first_not_of("0123456789");
		bool validRhsValue = false;
		if (isAlpha) {
			//check if variable exist
			for (int i = 0; i != variables.size(); i++) {
				if (variables[i].getName() == stopVar && var->getDatatype() == 3) {
					validRhsValue = true;
				}
			}

			if (!validRhsValue) {
				// cannot use a none initialized variable.
			}
		}
		else if (isNumber && var->getDatatype() == 1) {
			validRhsValue = true;
		}
		else {
			// No valid rhs value!
		}
	}
	else {
		// syntax error keyword TO and equal operator are incorrect.
	}
}

//Change variable name to variable value in string if variable name exist in expression.
std::string Manager::exchangeVariableNameToValue(std::string expression) {
	//if it is not a variable
	size_t foundStr = expression.find_first_of('"');
	if (foundStr != std::string::npos) {
		return expression;
	}

	std::string tmp = "";
	if (expression != "") {
		for (int i = 0; i <= expression.length(); i++) {
			size_t foundOperator = getOperatorPos(&expression);
			std::string lhs = "";
			std::string lhsValue = "";
			std::string op = "";
			std::string rhs = "";
			if (foundOperator != std::string::npos) {
				lhs = expression.substr(0, foundOperator);
				op = expression.substr(foundOperator, 1);
				rhs = expression.substr(foundOperator + 1, expression.length() - foundOperator);

				//change name to value.
				for (int k = 0; k != variables.size(); k++) {
					if (lhs == variables[k].getName()) {
						lhsValue = variables[k].getValue();
					}
				}

				tmp.append(lhsValue);
				tmp.append(op);

				expression.erase(0, lhs.length() + op.length());
			}
		}
		//only one value
		if (expression.length() != 0) {
			//change name to value.
			for (int k = 0; k != variables.size(); k++) {
				if (expression == variables[k].getName()) {
					expression = variables[k].getValue();
				}
			}

			tmp.append(expression);
			expression.erase(0, expression.length());
		}

		expression = tmp;
	}

	return expression;

	//find already defined variables.
	/*for (int i = 0; i != variables.size(); i++) {
		size_t foundVariable = expression.find(variables.at(i).getName());
		size_t foundOperator = getOperatorPos(&expression);
		if (foundVariable == 0 && foundOperator == std::string::npos) {
			expression.erase(foundVariable, variables.at(i).getName().length());
			std::string value = getDatatype(variables.at(i));
			expression.insert(foundVariable, value);
		}
		else if (foundOperator != std::string::npos) {
			std::string strRhs = expression.substr(foundOperator + 1, expression.length() - foundOperator);
			std::string strLhs = expression.substr(0, foundOperator + 1);
			size_t foundVar = strLhs.find(variables.at(i).getName());
			if (foundVar == 0) {
				strRhs.erase(foundVar, variables.at(i).getName().length());
				std::string value = getDatatype(variables.at(i));
				strRhs.insert(foundVar, value);
				expression = "";
				expression.append(strLhs);
				expression.append(strRhs);
			}
		}
	}*/
}

//overwrite the old value with the new value.
void Manager::overwriteOldVariableValue(LET *newVar) {
	if (variables.size() != 0) {
		for (size_t i = 0; i != variables.size(); i++) {
			if (newVar->getName() == variables.at(i).getName()) {
				variables.erase(variables.begin() + i);
			}
		}
	}

	variables.push_back(*newVar);
}

std::string Manager::getDatatype(LET var) {
	std::string value = var.getValue();
	if (var.getDatatype() == 1) {
		size_t foundDot = var.getValue().find('.');
		if (foundDot != std::string::npos) {
			value = var.getValue().erase(foundDot, var.getValue().length() - foundDot);
		}
	}
	
	return value;
}

size_t Manager::getCompareOperatorPos(std::string *expression) {
	size_t opEqual = expression->find("=");
	size_t opLess = expression->find("<");
	size_t opLarger = expression->find(">");
	if (opEqual != std::string::npos) {
		return opEqual;
	}
	else if (opLess != std::string::npos) {
		return opLess;
	}
	else if (opLarger != std::string::npos) {
		return opLarger;
	}

	return std::string::npos;
}

size_t Manager::getOperatorPos(std::string *expression) {
	size_t opEqual = expression->find("=");
	size_t opLess = expression->find("<");
	size_t opLarger = expression->find(">");
	size_t opAsterix = expression->find("*");
	size_t opPlus = expression->find("+");
	size_t opMinus = expression->find("-");
	size_t opDividing = expression->find("/");
	size_t opModulos = expression->find("%");
	if (opEqual != std::string::npos) {
		return opEqual;
	}
	else if (opLess != std::string::npos) {
		return opLess;
	}
	else if (opLarger != std::string::npos) {
		return opLarger;
	}
	else if (opAsterix != std::string::npos) {
		return opAsterix;
	}
	else if (opPlus != std::string::npos) {
		return opPlus;
	}
	else if (opMinus != std::string::npos) {
		return opMinus;
	}
	else if (opMinus != std::string::npos) {
		return opMinus;
	}
	else if (opDividing != std::string::npos) {
		return opDividing;
	}
	else if (opModulos != std::string::npos) {
		return opModulos;
	}

	return std::string::npos;
}

int main() {

	Manager manager;
	manager.init();

	system("pause");
	return 0;
}