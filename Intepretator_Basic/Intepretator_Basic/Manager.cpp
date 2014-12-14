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
			container.insert(std::pair<int, string>(key, line.substr(1, line.length() - 1)));
		}
		file.close();
	} else {
		std::cout << "Unable to open file" << endl;
	}
}

int Manager::provide(const std::string &expr) const {
	if (expr == "RANDOM") {
		return rand();
	} else if (expr == "INT") {
		//TODO typecast INT(blabla)
	}

	return ValueProvider::provide(expr);
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
		string str = value.substr(len, value.length() - len); //Get the rest of the string, keyword - value.

		if (keyword == "PRINT") {
			Print(str);
		}
		else if (keyword == "INPUT") {

		}
		else if (keyword == "LET") {
			
			Let(str, len);
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

std::string Manager::GetFirstWord(std::string str) {
	size_t found;
	found = str.find_first_of(' ');

	string word = str.substr(0, found);

	return word;
}

std::string Manager::GetVarExpression(std::string str, int len) {
	size_t found;
	found = str.find_first_of('=');

	string word = str.substr(len, found);

	return word;
}

std::string Manager::GetVarName(std::string str, int len) {
	size_t found;
	found = str.find_first_of('=');

	string word = str.substr(len, found - len);

	return word;
}

void Manager::Print(std::string str) {
	cout << str << endl;
}

int Manager::Goto(std::string str) {
	int number = atoi(str.c_str()); //convert string to int.
	return number;
}

void Manager::Let(std::string str, int len) {
	string varExpr = GetVarExpression(str, len);
	string varName = GetVarName(str, len);

	var *newVar = new var;

	variable.expr = &varExpr;
}

void Manager::End() {

}
