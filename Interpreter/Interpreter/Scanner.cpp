#include "Scanner.h"

Scanner::Scanner() {
	keywordsLength = 10;
	keywords[0] = "PRINT";
	keywords[1] = "LET";
	keywords[2] = "INPUT";
	keywords[3] = "IF";
	keywords[4] = "GOTO";
	keywords[5] = "END";
}

Scanner::~Scanner()
{
}

void Scanner::readFile(std::string path) {
	std::ifstream file(path);
	if (file.is_open()) {

		for (std::string line = ""; getline(file, line);) {
			int firstWhiteSpace = line.find_first_of(' ');
			int key = stoi(line.substr(0, firstWhiteSpace));

			std::string value = line.substr(firstWhiteSpace, line.length() - firstWhiteSpace);

			//find PRINT
			size_t findPRINT = value.find("PRINT");
			if (findPRINT != std::string::npos) {
				value = trimPRINT(value);
			}
			else {
				value = trimString(value);
			}

			map.pushBack(key, value);
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

std::string Scanner::trimPRINT(std::string str) {
	// if it is text.
	size_t found = str.find_first_of('\"');
	size_t found2 = str.find_last_of('\"');
	if (found != std::string::npos && found2 != std::string::npos) {
		str.erase(found, 1);		
		found2 = str.find_last_of('\"');
		str.erase(found2, 1);
	}
	//if it is a variable
	else {
		for (int i = 0; i != str.length(); i++) {
			if (isspace(str[i])) {
				str.erase(i, 1);
			}
		}
	}

	//erase first whitespace
	while (isspace(str.front())) {
		str.erase(0, 1);
	}
	//erase last whitespace
	while (isspace(str.back())) {
		str.erase(str.length() -1, 1);
	}

	return str;
}

std::string Scanner::getkeyword(std::string str) {
for (int i = 0; i != keywordsLength; i++) {
		size_t found = str.find(keywords[i]);
		if (found != std::string::npos) {
			return keywords[i];
		}
	}

	return "";
}

std::string Scanner::getExpression(std::string str, std::string strIrrelevant) {
	return str.substr(strIrrelevant.length(), (str.length() - strIrrelevant.length()));
}

std::pair<std::string, std::string> Scanner::getInstructionAt(int index) {
	std::string value = map.getElementAt(index).value;
	std::string keyword = getkeyword(value);
	std::string expression = getExpression(value, keyword);
	return std::make_pair(keyword, expression);
}

std::string Scanner::getLinenumber(int index) {
	return std::to_string(map.getElementAt(index).key);
}

int Scanner::getIndex(int linenumber) {
	for (int i = 0; i != length(); i++) {
		if (map.getElementAt(i).key == linenumber) {
			return i;
		}
	}

	return -1;
}

int Scanner::length() {
	return map.length();
}