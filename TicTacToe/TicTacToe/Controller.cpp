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

	int choice = -1;

	do {
		cin >> choice;
		if (Isdigit() && ValidNumber(choice, 0, 9)) {
			if (choice == 1) {
				PlayerSetup();			
			} else {
				printf("Choose a alternative in the menu, try again: ");
			}
		} else {
			printf("Not a valid input, try again: ");
		}
	} while (choice != 2);
}

void Controller::PlayerSetup() {
	string name1;
	string name2;

	//Ignore old data in cin.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//Set name for player 1.
	P1Name();
	getline(cin, name1);
	SetP1Name(name1);

	//Set name for player 2.
	P2Name();
	getline(cin, name2);
	SetP2Name(name2);
	
	
	UpdateGraphics();
	
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
	
	if (Isdigit() && (!(ValidNumber(choice, 9, -1)))) {
		if ((Graphics::ChangeGameBoard(choice))) {
			UpdateGraphics();
		} else {
			printf("The number is already taken!\n");
			UpdateGraphics();
		}
	} else {
		printf("Invalid input");
		UpdateGraphics();
	}
}

bool Controller::Isdigit() {
	if (cin.fail()) {
		cin.clear();
		return false;
	}
	return true;
}

//If input is bigger or equal to "high and input is smaller or equal to low.
bool Controller::ValidNumber(int input, int high, int low) {
	if (input >= high || input <= low) {
		return true;
	}
	return false;
}