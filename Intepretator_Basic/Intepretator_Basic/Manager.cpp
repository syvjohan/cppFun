#include "Manager.h"
#include "Defs.h"

using namespace std;

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
	Instructions();
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

void Manager::Instructions() {
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
		string str = value.substr(len, (value.length() - len)); //Get the rest of the string, keyword - value.

		if (keyword == "PRINT") {
			vector<variable>::iterator it;
			string line = DeleteQuotationMark(str);

			//If there is no variables in the varConatainer
			if (varContainer.begin() == varContainer.end()) {
				Print(line);
			}

			for (it = varContainer.begin(); it != varContainer.end(); ++it) {
				if (it->name == line) {
					line = to_string(it->expr);
					Print(line);
				}
				else {
					Print(line);
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
			//Exercises in FindSpecInstruction(string str, string inst1, string instr2);
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

//bool Manager::FindVariable(string str, string &expr) {
//	vector<variable>::iterator it;
//	for (it = varContainer.begin(); it != varContainer.end(); ++it) {
//		if (it->name == str) {			
//			expr = to_string(it->expr);
//			return true;
//		}
//	}
//	return false;
//}


//bool isAlpha = ((string[i] > 'a' && string[i] < 'z') || (string[i] > 'A' && string[i] < 'Z'));
string Manager::DeleteQuotationMark(string &str) {
	string result;
	string::iterator it;
	string::reverse_iterator rit;
	int countFor = 0;
	int countRev = 0;

	for (it = str.begin(); it != str.end(); ++it) {
		if (isalpha(*it)) {
			break;
		}
		++countFor;
	}

	for (rit = str.rbegin(); rit != str.rend(); ++rit) {
		if (isalpha(*rit)) {
			break;
		}
		++countRev;
	}
	
	result = str.substr(countFor, str.length() - countRev);
	return result;
}

string Manager::GetFirstWord(string str) {
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

string Manager::FindSpecInstruction(string str, string inst1, string instr2) {
	//Check for "THEN" in string.
	size_t findInstr1 = str.find(inst1);
	assert(findInstr1 != 4294967295 && "Wrong syntax");
	string secondExpr = str.substr(findInstr1, str.length());
	string firstExpr = str.substr(1, findInstr1 - 2);

	//Split second expression.
	//Check for "GOTO" in string.
	size_t findInstr2 = secondExpr.find(instr2);
	assert(findInstr2 != 4294967295 && "Wrong syntax");
	string instr = secondExpr.substr(findInstr2, 4);
	string number = secondExpr.substr(findInstr2 + instr.length() + 1, secondExpr.length());

	//return line for GOTO instruction
	return number;
}

char Manager::FindRelationalOperator(string strToSearch, string &word1, string &word2) {
	//Separate variables...
	size_t found1 = strToSearch.find_first_of('>');
	size_t found2 = strToSearch.find_first_of('<');
	char symbol;

	if (found1 != 4294967295) {
		word1 = strToSearch.substr(0, found1);
		word2 = strToSearch.substr(found1 + 1, strToSearch.length());
		return symbol = '>';
	}
	else if (found2 != 4294967295) {
		word1 = strToSearch.substr(0, found2);
		word2 = strToSearch.substr(found2 + 1, strToSearch.length());
		return symbol = '<';
	}
	assert("ERROR: no realtional operator implemented in IF!");
	return 'g'; //Relational operators not found
}

void Manager::If(string str) {

	string word1;
	string word2;
	char symbol = FindRelationalOperator(str, word1, word2);

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
							string goLine = FindSpecInstruction(str, "THEN", "GOTO");
							Goto(goLine);
						}
						else if (symbol == '<') {
							if (expr1 < expr2) {
								string goLine = FindSpecInstruction(str, "THEN", "GOTO");
								Goto(goLine);
							}
						}
					}
					
				}
			}
			
		}
	}
	assert("Cannot identify variables");
}

int Manager::EvaluateMathExpr(string exp) {
	DoProviding valProvider;
	MathExpr expr(exp);
	expr.setValueProvider(&valProvider);
	int result = expr.eval();

	return result;
}

