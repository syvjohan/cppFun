#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <time.h>
#include <string>

#include "parser.h"

class Manager : public ValueProvider {
public:
	Manager();
	~Manager();
	
	void Initializer();
	void LoadFile();
	int provide(const std::string &expr) const;
	std::string GetFirstWord(std::string str);
	std::string GetRestOfString(std::string str, int length);
	void CheckKeywordMatch();

	//Keywords.
	void Print(std::string str);
	int Goto(const int &key);
	void End();

private:
	std::vector<std::string> instructions;
	std::map<int, std::string> container;
};
