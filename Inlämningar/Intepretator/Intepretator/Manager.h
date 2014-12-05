#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <cassert>

using namespace std;

class Manager {
public:
	Manager();
	~Manager();
	
	void Initializer();
	void LoadFile();
	void CheckKeywordMatch();
	void CheckOperatorMatch(char &c, string varName);


private:
	vector<string> keywords;
	vector<char> symbols;
	map<int, string> containerString;
	map<int, string> containerKey;

	typedef struct variable {
		int size;
		string name;
	};
	
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
	void IsEqual();

	char SearchForOperator(string tmp);
	

};

//Shauting-yard algorithm
//Tokenizer