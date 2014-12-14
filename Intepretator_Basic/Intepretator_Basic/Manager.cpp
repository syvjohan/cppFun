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
			container.insert(std::pair<int, string>(key, line));
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

	while (it != container.end()) {

	value = it->second;
	key = it->first;
	string keyword = GetFirstWord(value);

	int len = keyword.length();
	string str = GetRestOfString(value, len);


		if (keyword == "PRINT") {
			Print(str);
		}
		else if (keyword == "INPUT") {

		}
		else if (keyword == "LET") {

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
			key = Goto(key);
			continue;
		}
		else {
			return;
		}

		++it;
	}	
}

std::string Manager::GetFirstWord(std::string str) {
	size_t found;
	found = str.find_first_of('\"'); 

	string word = str.substr(1, (found - 2));

	return word;
}

std::string Manager::GetRestOfString(std::string str, int length) {
	size_t found;
	found = str.find_last_of('"');

	string restOfStr = str.substr((length + 1), (found - 2));

	return restOfStr;
}

void Manager::Print(std::string str) {
	cout << str << endl;
}

int Manager::Goto(const int &key) {
	string str = container.find(key)->second;
	int number = atoi(str.c_str()); //convert string to int.
	return number;
}

void Manager::End() {

}
