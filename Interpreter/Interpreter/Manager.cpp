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
		LET *let = new LET(expression);
		variables.push_back(*let);
	}
	else if (keyword == "INPUT") {

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


	//Eval *eval = new Eval("((2+2)+(2+3))");



	system("pause");
	return 0;
}