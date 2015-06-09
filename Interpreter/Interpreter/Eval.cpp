#include "Eval.h"


Eval::Eval(const std::string &expression) {
	if (expression.length() > 0) {
		this->expression = expression;

		evaluateExpression();
		//std::cout << this->expression << std::endl;

		return;
	}

	std::cout << "Empty value" << std::endl;
}


Eval::~Eval() {

}

void Eval::evaluateExpression() {
	Parser *parser = new Parser();

	//Remove white space
	this->expression = parser->trimString(this->expression);

	//Check if syntax is correct.
	if (!parser->isParanthesesMatch(this->expression)) {
		std::cout << "Expression has wrong syntax" << std::endl;
	}
}


void Eval::loopExpression() {
	Parser *parser = new Parser();
	for (int i = 0; i != expression.length(); i++) {
		if (parser->isOperator(expression.at(i))) {
			std::cout << "is operator\n", expression.at(i);
		}
	}
}