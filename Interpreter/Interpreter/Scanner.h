#pragma once

#include "Map.h"

#include <fstream>
#include <string>

//#pragma optimize("", on)

class Scanner {
public:
	Scanner();
	~Scanner();

	void readFile(std::string path);

	std::string getkeyword(std::string str);
	std::string getExpression(std::string str, std::string strIrrelevant);
	std::pair<std::string, std::string> getInstructionAt(int index);
	int getInstructionLength();

private:
	Map map;

	int keywordsLength;
	std::string keywords[10];

	std::string trimString(std::string str);
	std::string trimPRINT(std::string str);
};

