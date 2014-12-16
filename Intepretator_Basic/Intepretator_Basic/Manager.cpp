#include "Manager.h"

using namespace std;

Manager::Manager() {
	//keywords = {"INPUT", "PRINT", "LET", "IF", "THEN", "GOTO", "END", "RANODM", "INT"};
	instructions.push_back("INPUT");
	instructions.push_back("PRINT");
	instructions.push_back("GOTO");

}

Manager::~Manager() {

}

void Manager::Initializer() {
	LoadFile();
	srand(time(NULL));
	CheckKeywordMatch();
}

void Manager::LoadFile() {
	string path;
	cout << "Write path to text file: ";
	cin >> path;
	printf("\n");

	string line;
	int key;
	ifstream file("test.txt");
	if (file.is_open()) {
		while (file >> key && getline(file, line)) {
			container.insert(pair<int, string>(key, line.substr(1, line.length() - 1)));
		}
		file.close();
	} else {
		std::cout << "Unable to open file" << endl;
	}
}

void Manager::CheckKeywordMatch() {
	string value;
	int key;

	map<int, string>::iterator it;
	it = container.begin();

	do {

		value = it->second;
		key = it->first;

		std::cout << key << " | "<< value << std::endl;

		string keyword = GetFirstWord(value);

		int len = keyword.length();
		string str = value.substr(len + 2, (value.length() - len - 3)); //Get the rest of the string, keyword - value.

		if (keyword == "PRINT") {
			Print(str);
		}
		else if (keyword == "INPUT") {

		}
		else if (keyword == "LET") {
			
			Let(str);
		}
		else if (keyword == "IF") {

		}
		else if (keyword == "THEN") {

		}
		else if (keyword == "END") {

		}
		else if (keyword == "RANDOM") {

		}
		else if (keyword == "INT") {

		}
		else if (keyword == "GOTO") {
			key = Goto(str);
			it = container.find(key);
			continue;
		}
		else {
			return;
		}

		++it;
	} while (it != container.end());
}

std::string Manager::GetFirstWord(string str) {
	size_t found;
	found = str.find_first_of(' ');

	string word = str.substr(0, found);

	return word;
}

string Manager::GetVarExpression(string str, string varName) {
	size_t found;
	found = str.find_first_of('=');

	string word = str.substr(found + 2, str.length());

	return word;
}

string Manager::GetVarName(string str) {
	size_t found;
	found = str.find_first_of('=');

	string word = str.substr(0, found);

	return word;
}

void Manager::Print(string str) {
	cout << str << endl;
}

int Manager::Goto(string str) {
	int number = atoi(str.c_str()); //convert string to int.
	return number;
}

void Manager::Let(string str) {
	string varName = GetVarName(str);
	string varExpr = GetVarExpression(str, varName);
	
	variable *newVar = new variable;

	int exprResult = EvaluateMathExpr(varExpr);

	newVar->expr = &exprResult;
	newVar->name = varName;
}

void Manager::End() {

}

int Manager::EvaluateMathExpr(string exp) {
	DoProviding valProvider;
	MathExpr expr(exp);
	expr.setValueProvider(&valProvider);
	int result = expr.eval();

	return result;
}


