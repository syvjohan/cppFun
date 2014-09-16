#include <iostream>
#include "Controller.h"

using namespace std;

Controller::Controller() {
	
}

Controller::~Controller() {

}

//This function is called from int main() in main.cpp
void Controller::InitializeGame() {
	Graphics::Menu();
	Start();
}

void Controller::Start() {

	int choice = 0;

	do {
		cin >> choice;
		if (choice >= 3 || choice < 1) {
			printf("Not a valid input!\n");
		} else if (choice == 1) {
			UpdateGraphics();
		} 
	} while (choice != 2);
}

void Controller::UpdateGraphics() {

	Graphics::Stats();
	Graphics::Board();
	Graphics::MenuChooseMark();
	Mark();
}

void Controller::Mark() {
	int choice = -1;
	cin >> choice;
	
	if (Isdigit(choice)) {
		if ((Graphics::ChangeGameBoard(choice))) {
			UpdateGraphics();
		} else {
			printf("The number is already taken!\n");
			UpdateGraphics();
		}
	} else {
		printf("Invalid input");
	}
}

bool Controller::Isdigit(int integer) {
	if (cin.fail()) {
		cin.clear();
		return false;
	}
	return true;
}