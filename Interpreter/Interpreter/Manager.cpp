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
		expression = exchangeVariableNameToValue(expression);
		evalPRINT(expression);
	}
	else if (keyword == "LET") {
		expression = exchangeVariableNameToValue(expression);
		LETNumber *var = new LETNumber(expression);
		variablesNUMBER.push_back(*var);
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

void Manager::evalPRINT(std::string &str) {
	std::cout << str << std::endl;
}

void Manager::evalINPUT(std::string &str) {
	std::string input = "";
	std::cin.clear();
	std::getline(std::cin, input);

	bool isAlpha = std::regex_match(input, std::regex("^[A-Za-z]+$"));
	size_t isINT = input.find_first_not_of("0123456789");
	size_t isFLOAT = input.find_first_not_of("0123456789.");

	if (isAlpha || isINT == std::string::npos || isFLOAT == std::string::npos) {
		str.append("||");
		str.append(input);

		LETINPUT *var = new LETINPUT(str);

		if (variablesINPUT.size() != 0) {
			for (size_t i = 0; i <= variablesINPUT.size(); i++) {
				if (var->getName() == variablesINPUT.at(i).getName()) {
					variablesINPUT.erase(variablesINPUT.begin() + i);
				}
			}
		}
		
		variablesINPUT.push_back(*var);
	}

	//Invalid input, only letters or only numbers.
	return;
}

void Manager::evalIF(std::string &str) {
	//get first variable.
	LETINPUT var1;
	LETNumber var2;

	size_t foundVar2 = -1;
	size_t foundVar1 = -1;
	for (int i = 0; i != variablesINPUT.size(); i++) {
		foundVar1 = str.find(variablesINPUT.at(i).getName());
		if (foundVar1 != std::string::npos) {
			var1 = variablesINPUT.at(i);
			break;
		}
	}
	
	//get second variable.
	for (int k = 0; k != variablesNUMBER.size(); k++) {
		foundVar2 = str.find(variablesNUMBER.at(k).getName());
		if (foundVar2 != std::string::npos) {
			var2 = variablesNUMBER.at(k);
			break;
		}
	}

	//compare datatypes.
	if (var1.getDatatype() != var2.getDatatype()) {
		// cannot compare different datatypes.
	}
	else {
		//get operator.
		if (foundVar1 != -1 && foundVar2 != -1) {
			size_t findOpGreater = str.find('>');
			size_t findOpLess = str.find('<');
			size_t findOpLessOrEqual = str.find(">=");
			size_t findOpGreaterOrEqual = str.find("=<");

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
				size_t line = str.find_first_of("0123456789");
				if (line != str.length() && line != std::string::npos) {
					std::string linenumber = str.substr(line, str.length() - line);
					
					// get instruction index.
					tableIndex = scanner.getIndex(std::stoi(linenumber));
					//++tableIndex; // offset map[0] to [1].

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

std::string Manager::getDatatype(LETNumber var) {
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