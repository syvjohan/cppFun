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

	void Instructions();

	typedef struct {
		std::string name;
		void *pVoid;
		int sizeInt;
		std::string sizeString;
		int expr;
	}variable;

private:
	std::vector<std::string> instructions; //{"INPUT", "PRINT", "LET", "IF", "THEN", "GOTO", "END", "RANODM", "INT"};
	std::map<int, std::string> container; //txt file..
	std::vector<variable> varContainer;

	//Keywords.
	void Print(std::string str);
	int Goto(std::string str);
	void Let(std::string str);
	void If(std::string str);

	//Evaluate functions
	int EvaluateMathExpr(std::string exp);
	std::string GetFirstWord(std::string str);
	std::string GetLhs(std::string str);
	std::string GetRhs(std::string str1, std::string str2);
	std::string DeleteQuotationMark(std::string &str);
	//int IsString(std::string str);
	void FindVariable(std::string str, std::string &expr);
	char FindRelationalOperator(std::string strToSearch, std::string &word1, std::string &word2);
	std::string FindSpecInstruction(std::string str, std::string instr1, std::string instr2);
	
};
