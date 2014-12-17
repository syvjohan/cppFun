#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <time.h>
#include <string>
#include <stdlib.h>

#include "parser.h"
#include "DoProviding.h"

class Manager {
public:
	Manager();
	~Manager();
	
	void Initializer();
	void LoadFile();

	void CheckKeywordMatch();

	typedef struct {
		std::string name;
		void *pVoid;
		int sizeInt;
		std::string sizeString;
		int expr;
	}variable;

private:
	std::vector<std::string> instructions;
	std::map<int, std::string> container;
	std::vector<variable> varContainer;

	//Keywords.
	void Print(std::string str);
	int Goto(std::string str);
	void Let(std::string str);
	bool If(std::string str);

	//Evaluate functions
	int EvaluateMathExpr(std::string exp);
	std::string GetFirstWord(std::string str);
	std::string GetLhs(std::string str);
	std::string GetRhs(std::string str1, std::string str2);
	//int IsString(std::string str);
	bool FindVariable(std::string str, std::string &expr);
};
