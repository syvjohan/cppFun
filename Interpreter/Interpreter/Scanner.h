#pragma once

#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Scanner
{
public:
	Scanner();
	~Scanner();

	void readFile(string path);

	string getkey(std::string str);
	string getExpression(string str);
	map<int, std::string> intstructionLine;
private:

	string *keywords;

	string trimString(std::string str);
};

