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
		evalInput(expression);
	}
	else if (keyword == "LET") {
		LETNumber *var = new LETNumber(expression);
		variables.push_back(*var);
	}
	else if (keyword == "INPUT") {
		//LETString *var = new LETString(expression);
		//variables.push_back(*var);
	}
	else {
		return;
	}
	
}

void Manager::evalInput(std::string str) {
	std::cout << str << std::endl;
}

int main() {

	Manager manager;
	manager.init();



	system("pause");
	return 0;
}