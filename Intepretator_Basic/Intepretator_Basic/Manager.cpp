#include "Manager.h"
#include "Defs.h"

using namespace std;

static std::string trimWs(const std::string &exp) {
	std::string str;
	for (const char ch : exp) {
		if (!(ch == ' ' || ch == '\n')) {
			str += ch;
		}
	}
	return str;
}

Manager::Manager() {
	//keywords = {"INPUT", "PRINT", "LET", "IF", "THEN", "GOTO", "END", "RANODM", "INT"};
	instructions.push_back("INPUT");
	instructions.push_back("PRINT");
	instructions.push_back("GOTO");
	instructions.push_back("END");

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
	}
	else {
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

		//cout << key << " | " << value << endl;

		string keyword = GetFirstWord(value);
		int len = keyword.length();
		string str = value.substr(len , (value.length() - len)); //Get the rest of the string, keyword - value.

		if (keyword == "PRINT") {
			vector<variable>::iterator it;
			for (it = varContainer.begin(); it != varContainer.end(); ++it) {
				if (it->name == str) {
					str = to_string(it->expr);
					Print(str);
				}
				else {
					str = GetLhs(str);
					Print(str);
				}
			}
			
		}
		else if (keyword == "INPUT") {
			Let(str);
		}
		else if (keyword == "LET") {
			Let(str);
		}
		else if (keyword == "IF") {
			If(str);
		}
		else if (keyword == "THEN") {

		}
		else if (keyword == "END") {
			exit(0);
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

bool Manager::FindVariable(string str, string &expr) {
	vector<variable>::iterator it;
	for (it = varContainer.begin(); it != varContainer.end(); ++it) {
		if (it->name == str) {			
			expr = to_string(it->expr);
			return true;
		}
	}
	return false;
}

std::string Manager::GetFirstWord(string str) {
	size_t found;
	found = str.find_first_of(' ');

	string word = str.substr(0, found);

	return word;
}

string Manager::GetRhs(string str, string varName) {
	size_t found;
	found = str.find_first_of('=');

	string word = str.substr(found +2, str.length());

	return word;
}

string Manager::GetLhs(string str) {
	size_t found;
	found = str.find_first_of('=');

	string word = str.substr(1, found -2);

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
	string varName = GetLhs(str);
	string varExpr = GetRhs(str, varName);
	 
	variable *newVar = new variable;
	
	int exprResult = EvaluateMathExpr(varExpr);

	newVar->expr = exprResult;
	newVar->name = varName;

	varContainer.push_back(*newVar);
}

bool Manager::If(string str) {
	//Remove whitespaces.
	string trimStr = trimWs(str);

	//Separate variables...
	size_t found1 = trimStr.find_first_of('>');
	size_t found2 = trimStr.find_first_of('<');
	char symbol;
	string word1, word2;
	if (found1 != 4294967295) {
		word1 = trimStr.substr(0, found1);
		word2 = trimStr.substr(found1 + 1, trimStr.length());
		symbol = '>';
	}
	else if (found2 != 4294967295) {
		word1 = trimStr.substr(0, found2);
		word2 = trimStr.substr(found2 + 1, trimStr.length());
		symbol = '<';
	}
	else {
		return false;
	}
	
	//Check if they exist in varContainer
	vector<variable>::iterator it;
	for (it = varContainer.begin(); it != varContainer.end(); ++it) {
		if (word1.c_str() == it->name) {
			int expr1 = it->expr;
			for (it = varContainer.begin(); it != varContainer.end(); ++it) {
				if (word2.c_str() == it->name) {
					int expr2 = it->expr;
					//Compare values (bigger/smaller).
					if (symbol == '>') {
						if (expr1 > expr2) {
							return true;
						}
						return false;
					}
					else if (symbol == '<') {
						if (expr1 < expr2) {
							return true;
						}
						return false;
					}
				}
			}
			
		}
	}
	printf("Cannot identify variables");
	return false;
}

int Manager::EvaluateMathExpr(string exp) {
	DoProviding valProvider;
	MathExpr expr(exp);
	expr.setValueProvider(&valProvider);
	int result = expr.eval();

	return result;
}

