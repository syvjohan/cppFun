#include "Eval.h"


Eval::Eval() {

}


Eval::~Eval() {

}

int Eval::evaluateExpression(std::string line) {
	if (expression.length() > 0) {
		this->expression = line;
		Parser *parser = new Parser();

		//Remove white space
		this->expression = parser->trimString(this->expression);

		//Check if syntax is correct.
		if (!parser->isParanthesesMatch(this->expression)) {
			return -1;
			std::cout << "Expression has wrong syntax" << std::endl;
		}

		return 1;
	}

	std::cout << "Empty value" << std::endl;
	return -2;
}


void Eval::loopExpression() {
	Parser *parser = new Parser();
	for (int i = 0; i != expression.length(); i++) {
		if (parser->isOperator(expression.at(i))) {
			std::cout << "is operator\n", expression.at(i);
		}
	}
}

std::string Eval::calculateExpression() {
	int exp1 = 0;
	int exp2 = 0;

/*	for (int i = 0; i < expression.length(); i++) {
		
	}*/

	return 0;
}