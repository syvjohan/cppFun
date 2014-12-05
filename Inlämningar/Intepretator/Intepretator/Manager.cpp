#include "Manager.h"

Manager::Manager() {
	symbols = { '+', '-', '*', '/', '(', ')', '<', '>', '=' };
	keywords = { "INPUT", "PRINT", "LET", "IF", "THEN", "GOTO", "END", "RANODM", "INT"};
}

Manager::~Manager() {

}

void Manager::Initializer() {
	LoadFile();
	CheckKeywordMatch();
}

//void eval(const string& code) {
//	// Evaluate one instruction
//}

//void basic_goto(const string &str) {
//	int line = 0; // Läs ut vilken instruktion man vill hoppa till från str
//	eval(myMapOfInstructions[line]);
//}

void Manager::LoadFile() {
	string path;
	cout << "Write path to text file: ";
	cin >> path;
	printf("\n");

	string line;
	string word;
	int key;
	ifstream file("test.txt");
	if (file.is_open()) {
	START:while (file >> key) {
			while (file >> line) {
				//Bör kontrollera om det är ett keyword innan det lagras.
				for (int i = 0; i != keywords.size(); ++i) {
					if (line == keywords[i]) {
						containerKey.insert(std::pair<int, string>(key, line));
						break;
					}					
				}	

				while (getline(file, line)) {
					containerString.insert(std::pair<int, string>(key, line));
					goto START;
				}
			}
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file" << endl;
	}

	return;
}

void Manager::CheckKeywordMatch() {
	string value;
	int key;
	map<int, string>::iterator it;
	for (it = containerKey.begin(); it != containerKey.end(); ++it) {
		value = it->second;
		key = it->first;
		
  CHECK:if (value == "PRINT") {
			Print(key);
		}
		else if (value == "INPUT") {
			Input(key);
		}
		else if (value == "LET") {
			Let(key);
		}
		else if (value == "IF") {
			If(key);
		}
		else if (value == "THEN") {

		}
		else if (value == "END") {
			End();
		}
		else if (value == "RANDOM") {

		}
		else if (value == "INT") {

		}
		else if (value == "GOTO") {
			key = Goto(key);

			//If the referenced value is not found in map, assertion failer will be shown.
			value = containerKey.find(key)->second;
			goto CHECK;
		}
		else {
			return;
		}
	}
}

void Manager::Print(const int &key) {
	cout << containerString.find(key)->second << endl;
}

void Manager::Let(const int &key) {
	variable *var = new variable;
	list<variable> listVar;
	
	var->name = containerKey.find(key)->second;

	string tmp = containerString.find(key)->second;
	char c = SearchForOperator(tmp);
	CheckOperatorMatch(c, var->name);

	//var->size = sizeof(containerKey.find(key)->second);
}

char Manager::SearchForOperator(string tmp) {
	for (char &c : tmp) {
		for (int j = 0; j != symbols.size(); ++j) {
			if (tmp[c] == symbols[j]) { 
				return c;
			}
		}	
	}
}

void Manager::Input(const int &key) {
	Let(key);
}

void Manager::End() {
	return;
}

int Manager::Goto(const int &key) {
	string str = containerString.find(key)->second;
	int number = atoi(str.c_str()); //convert string to int.
	
	return number;
}

bool Manager::If(const int &key) {
	return true;
}

void Manager::CheckOperatorMatch(char &c, string varName) {
	if (c == '+') {

	}
	else if (c == '-') {

	}
	else if (c == '*') {

	}
	else if (c == '/') {

	}
	else if (c == '(') {

	}
	else if (c == ')') {

	}
	else if (c == '<') {

	}
	else if (c == '>') {

	}
	else if (c == '=') {
		void IsEqual();
	}
	else {
		return;
	}
}

void Manager::IsEqual() {

}

