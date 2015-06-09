#include "Parser.h"

Parser::Parser()
{
}


Parser::~Parser()
{
}

std::string Parser::trimString(std::string str) {
	std::string tmp = "";
	for (int i = 0; i != str.length(); i++) {
		if (str.at(i) != ' ' && str.at(i) != '\t' && str.at(i) != '\n' && str.at(i) != '\v') {
			tmp += str.at(i);
		}
	}
	str = tmp;
	return str;
}

bool Parser::isOperator(char op) {
	return (op == '+' || op == '-' || op == '/' || op == '*' || op == '%');
}

bool Parser::isParanthesesMatch(std::string str) {
	int rIndex = str.length();
	for (int i = 0; i < rIndex; i++) {
		rIndex = str.length() - i -1;
		if ((str.at(i) != '(' && str.at(rIndex) == ')') || (str.at(i) == '(' && str.at(rIndex) != ')')) {
			return false;
		}
	}

	return true;
}