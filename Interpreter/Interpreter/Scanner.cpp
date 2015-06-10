#include "Scanner.h"


Scanner::Scanner() {
	numberOfElements = 3;
	keywords[0] = "PRINT";
	keywords[1] = "LET";
	keywords[2] = "INPUT";
}


Scanner::~Scanner()
{
}

void Scanner::readFile(string path) {
	ifstream file(path);
	if (file.is_open()) {

		for (string line = ""; getline(file, line);) {
			int firstWhiteSpace = line.find_first_of(' ');
			int key = stoi(line.substr(0, firstWhiteSpace));

			string value = line.substr(firstWhiteSpace, line.length() - firstWhiteSpace);

			string tmp = removeSlashFromPrint(value);
			if (tmp != "") {
				value = tmp;
			}

			value = trimString(value);
			intstructionLine.insert(pair<int, string>(key, value));
		}
	}
}

std::string Scanner::trimString(std::string str) {
	std::string tmp = "";
	for (int i = 0; i != str.length(); i++) {
		if (str.at(i) != ' ' && str.at(i) != '\t' && str.at(i) != '\n' && str.at(i) != '\v') {
			tmp += str.at(i);
		}
	}
	str = tmp;
	return str;
}

string Scanner::removeSlashFromPrint(string str) {
	size_t found = str.find_first_of('\"');
	size_t found2 = str.find_last_of('\"');
	if (found != string::npos && found2 != string::npos) {
		str.erase(found, 1);		
		found2 = str.find_last_of('\"');
		str.erase(found2, 1);

		return str;
	}
	return "";
}

string Scanner::getkey(string str) {
	for (int i = 0; i != numberOfElements; i++) {
		size_t found = str.find(keywords[i]);
		if (found != string::npos) {
			return keywords[i];
		}
	}

	return "";
}

string Scanner::getExpression(string str, string strIrrelevant) {
	return str.substr(strIrrelevant.length(), (str.length() - strIrrelevant.length()));

}