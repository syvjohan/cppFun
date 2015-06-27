#include "Manager.h"

Manager::Manager() {
	
}

Manager::~Manager()
{
}

void Manager::init() {
	scanner.readFile("Instructions.txt"); //code file to be read from!

	for (int i = 0; i != scanner.getInstructionLength(); i++) {
		 table(scanner.getInstructionAt(i).first, scanner.getInstructionAt(i).second);
	}
}

void Manager::table(std::string keyword, std::string expression) {
	if (keyword == "PRINT") {
		evalPRINT(expression);
	}
	else if (keyword == "LET") {
		LETNumber *var = new LETNumber(expression);
		variablesNUMBER.push_back(*var);
	}
	else if (keyword == "INPUT") {
		evalINPUT(expression);
	}
	else if (keyword == "IF") {
		evalIF(expression);
	}
	else {
		return;
	}
}

void Manager::evalPRINT(std::string str) {
	std::cout << str << std::endl;
}

void Manager::evalINPUT(std::string &str) {
	std::string input;
	std::getline(std::cin, input);

	bool isAlpha = std::regex_match(input, std::regex("^[A-Za-z]+$"));
	size_t isINT = input.find_first_not_of("0123456789");
	size_t isFLOAT = input.find_first_not_of("0123456789.");

	if (isAlpha || isINT == std::string::npos || isFLOAT == std::string::npos) {
		str.append("||");
		str.append(input);

		LETINPUT *var = new LETINPUT(str);
		variablesINPUT.push_back(*var);
	}

	//Invalid input, only letters or only numbers.
	return;
}

void Manager::evalIF(std::string &str) {
	//get first variable.
	LETNumber var1;
	LETINPUT var2;
	for (int i = 0; i != variablesINPUT.size(); i++) {
		size_t foundVar2 = str.find(variablesINPUT.at(i).getName());
		if (foundVar2 != std::string::npos) {
			var2 = variablesINPUT.at(i);
		}
	}
	
	//get second variable.
	for (int k = 0; k != variablesNUMBER.size(); k++) {
		size_t foundVar1 = str.find(variablesNUMBER.at(k).getName());
		if (foundVar1 != std::string::npos) {
			var1 = variablesNUMBER.at(k);
		}
	}


	// do if true/false
}

int main() {

	Manager manager;
	manager.init();



	system("pause");
	return 0;
}