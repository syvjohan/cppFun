#include "Scanner.h"

Scanner::Scanner() {
	keywordsLength = 4;
	keywords[0] = "PRINT";
	keywords[1] = "LET";
	keywords[2] = "INPUT";
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

			std::string tmp = removeSlashFromPrint(value);
			if (tmp != "") {
				value = tmp;
			}

			value = trimString(value);
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

std::string Scanner::removeSlashFromPrint(std::string str) {
	size_t found = str.find_first_of('\"');
	size_t found2 = str.find_last_of('\"');
	if (found != std::string::npos && found2 != std::string::npos) {
		str.erase(found, 1);		
		found2 = str.find_last_of('\"');
		str.erase(found2, 1);

		return str;
	}
	return "";
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

int Scanner::getInstructionLength() {
	return map.Length();
}