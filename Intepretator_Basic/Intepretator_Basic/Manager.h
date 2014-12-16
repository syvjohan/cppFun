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
		void *expr;
	}variable;

private:
	std::vector<std::string> instructions;
	std::map<int, std::string> container;



	std::vector<variable> varContainer;

	//Keywords.
	void Print(std::string str);
	int Goto(std::string str);
	void End();
	void Let(std::string str);

	//Evaluate functions
	int EvaluateMathExpr(std::string exp);
	std::string GetFirstWord(std::string str);
	std::string GetVarName(std::string str);
	std::string GetVarExpression(std::string str, std::string str2);
};
