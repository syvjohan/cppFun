#pragma once

#include <iostream>
#include "Eval.h"
#include "Scanner.h"

class Manager
{
public:
	Manager();
	~Manager();

	void init();
	void table(std::string keyword, std::string expression);
};

