#pragma once

#include "Variable.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <cassert>

class Manager {
public:
	Manager();
	~Manager();
	
	void Initializer();
	void LoadFile();
	void CheckKeywordMatch();
	void CheckOperatorMatch(char &c, std::string &varName, int &expression);


private:
	Variable *var;

	std::list<Variable> listVar; //Storage for variables.
	std::vector<std::string> keywords;
	std::vector<char> symbols;
	std::map<int, std::string> containerString;
	std::map<int, std::string> containerKey;
	
	//Keywords.
	void Print(const int &key);
	void Input(const int &key);
	void Let(const int &key);
	bool If(const int &key);
	void Then();
	int Goto(const int &key);
	void End();
	int Random();
	int INT();

	//Symbols.
	void Add();
	void Minus();
	void Multiplication();
	void Division();
	void CloseParenthesis();
	void OpenParanthesis();
	void Less();
	void More();
	void IsEqual(std::string &varName, int &expression);

	void SearchForOperator(char &cTmp, std::string sTmp, int &expression);
	

};

//Shauting-yard algorithm
//Tokenizer