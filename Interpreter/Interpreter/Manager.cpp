#include "Manager.h"


Manager::Manager()
{
}


Manager::~Manager()
{
}

void Manager::init() {
	Scanner *scanner = new Scanner();
	scanner->readFile("Instructions.txt");
	
	//Iterate line by line
	string keyword = "";
	string expression = "";
	for (auto &p : scanner->intstructionLine) {
		keyword = scanner->getkey(p.second);
		expression = scanner->getExpression(p.second);
	}
	
}




int main() {

	Manager *manager = new Manager();
	manager->init();


	//Eval *eval = new Eval("((2+2)+(2+3))");



	system("pause");
	return 0;
}


/*for (auto &t : intstructionLine) {
cout << t.first << "\n"
<< t.second << endl;
}*/