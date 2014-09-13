#include <iostream>
#include "Controller.h"
#include "Player.h"
#include "Graphics.h"

Graphics graphics;

Controller::Controller() {

}

Controller::~Controller() {

}

//This function is called from int main() in main.cpp
void InitializeGame() {
	graphics.Menu();
	void Start();
}

bool Controller::CheckIndex(int i) {
	return true;
}

void Start() {

	int choice = 0;
	std::cin >> choice;;

	while (choice != 2) {

		switch (choice) {

		case 1:
			void StartGame();
			break;
		}
	}
}

void Controller::GetInput(int choice) {

}

void Controller::StartGame() {
	
	graphics.Stats();
	graphics.Board();
	graphics.MenuChooseNumber();
}
