#pragma once

#include "parser.h"

class DoProviding : public ValueProvider {

	int provide(const std::string &expr) const {
		if (expr == "RANDOM") {
			return rand();
		}
		else if (expr == "INT") {
			//TODO typecast INT(blabla)
		}

		return ValueProvider::provide(expr);
	}
};