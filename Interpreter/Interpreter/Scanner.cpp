#include "Scanner.h"


Scanner::Scanner() {
	keywords = new string[3] { "PRINT", "INPUT", "END" };

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

string Scanner::getkey(string str) {
	size_t numberOfElements = sizeof(keywords) / sizeof(keywords[0]);
	for (int i = 0; i != numberOfElements; i++) {
		size_t found = str.find(keywords[i]);
		if (found >= 0) {
			return keywords[i];
		}
	}

	return "";
}

string Scanner::getExpression(string str) {
	return str;
}