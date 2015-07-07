#include "Manager.h"

Manager::Manager() {
	
}

Manager::~Manager()
{
}

void Manager::init() {
	scanner.readFile("Instructions.txt"); //code file to be read from!

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
		exit(0);
	}
	else {
		return;
	}
}

void Manager::evalPRINT(std::string &expression) {
	expression = exchangeVariableNameToValue(expression);

	std::cout << expression << std::endl;
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

	size_t foundVar2 = -1;
	size_t foundVar1 = -1;

	bool isVariable1 = false;
	bool isVariable2 = false;

	//get first variable.
	for (int i = 0; i != variablesNUMBER.size(); i++) {
		foundVar1 = expression.find(variablesNUMBER.at(i).getName());
		if (foundVar1 != std::string::npos) {
			var1 = variablesNUMBER.at(i);
			isVariable1 = true;
			break;
		}
	}
	
	//get second variable.
	for (int k = 0; k != variablesNUMBER.size(); k++) {
		foundVar2 = expression.find(variablesNUMBER.at(k).getName());
		if (foundVar2 != std::string::npos) {
			var2 = variablesNUMBER.at(k);
			isVariable2 = true;
			break;
		}
	}

	//If compared values are no variables instead they are hardcoded values.
	/*if (!isVariable1) {
		size_t foundOpEqual = str.find("=");
		size_t foundTHEN = str.find("THEN");
		if (foundOpEqual != std::string::npos && foundTHEN != std::string::npos) {
			std::string value = str.substr(foundOpEqual + 1, foundTHEN - foundOpEqual +1);

			//is value a string or a number.
			bool isAlpha = std::regex_match(value, std::regex("^[A-Za-z]+$"));
			size_t isINT = value.find_first_not_of("0123456789");
			size_t isFLOAT = value.find_first_not_of("0123456789.");


		}
	}
	else if (!isVariable2) {

	}*/

	//compare datatypes.
	if (var1.getDatatype() != var2.getDatatype()) {
		// cannot compare different datatypes.
	}
	else {
		//get operator.
		if (foundVar1 != -1 && foundVar2 != -1) {
			size_t findOpGreater = expression.find('>');
			size_t findOpLess = expression.find('<');
			size_t findOpLessOrEqual = expression.find(">=");
			size_t findOpGreaterOrEqual = expression.find("=<");

			//comapre variables.
			bool result = false;
			if (findOpGreater != std::string::npos && findOpGreater < foundVar2) {
				result = var1.getValue() > var2.getValue();
			}
			else if (findOpLess != std::string::npos && findOpLess < foundVar2) {
				result = var1.getValue() < var2.getValue();
			}
			else if (findOpGreaterOrEqual != std::string::npos && findOpGreaterOrEqual < foundVar2) {
				result = var1.getValue() >= var2.getValue();
			}
			else if (findOpLessOrEqual != std::string::npos && findOpLessOrEqual < foundVar2) {
				result = var1.getValue() <= var2.getValue();
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
					
					// get instruction index.
					tableIndex = scanner.getIndex(std::stoi(linenumber));

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

//Change variable name to variable value in string if variable name exist in expression.
std::string Manager::exchangeVariableNameToValue(std::string expression) {
	//if it is not a variable
	size_t foundStr = expression.find_first_of('"');
	if (foundStr != std::string::npos) {
		return expression;
	}

	//find already defined variables.
	for (int i = 0; i != variablesNUMBER.size(); i++) {
		size_t foundVariable = expression.find(variablesNUMBER.at(i).getName());
		size_t foundOpEqual = expression.find('=');
		if (foundVariable == 0 && foundOpEqual == std::string::npos) {
			expression.erase(foundVariable, variablesNUMBER.at(i).getName().length());
			std::string value = getDatatype(variablesNUMBER.at(i));
			expression.insert(foundVariable, value);
		}
		else if (foundOpEqual != std::string::npos) {
			std::string strRhs = expression.substr(foundOpEqual + 1, expression.length() - foundOpEqual);
			std::string strLhs = expression.substr(0, foundOpEqual +1);
			size_t foundVar = strRhs.find(variablesNUMBER.at(i).getName());
			if (foundVar == 0) {
				strRhs.erase(foundVar, variablesNUMBER.at(i).getName().length());
				std::string value = getDatatype(variablesNUMBER.at(i));
				strRhs.insert(foundVar, value);
				expression = "";
				expression.append(strLhs);
				expression.append(strRhs);
			}
		}
	}

	return expression;
}

//overwrite the old value with the new value.
void Manager::overwriteOldVariableValue(LET *newVar) {
	if (variablesNUMBER.size() != 0) {
		for (size_t i = 0; i != variablesNUMBER.size(); i++) {
			if (newVar->getName() == variablesNUMBER.at(i).getName()) {
				variablesNUMBER.erase(variablesNUMBER.begin() + i);
			}
		}
	}

	variablesNUMBER.push_back(*newVar);
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

int main() {

	Manager manager;
	manager.init();

	system("pause");
	return 0;
}