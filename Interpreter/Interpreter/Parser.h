#pragma once

#include <string>
#include <iostream>

class Parser
{
public:
	Parser();
	~Parser();

	bool isOperator(char op);
	std::string trimString(std::string str);
	bool isParanthesesMatch(std::string str);

	

};

