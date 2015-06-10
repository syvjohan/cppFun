#pragma once

#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

//#pragma optimize("", on)

using namespace std;

class Scanner
{
public:
	Scanner();
	~Scanner();

	void readFile(string path);

	string removeSlashFromPrint(string str);
	string getkey(string str);
	string getExpression(string str, string strIrrelevant);
	map<int, string> intstructionLine;
private:
	int numberOfElements;
	string keywords[4];

	string trimString(string str);
};

