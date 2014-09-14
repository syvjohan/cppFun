#include <iostream>
#include "Controller.h"
#include "Player.h"
#include "Graphics.h"
#include "GameBoard.h"

Graphics graphics;
GameBoard board;

Controller::Controller() {

}

Controller::~Controller() {

}

//This function is called from int main() in main.cpp
void Controller::InitializeGame() {
	graphics.Menu();
	Start();
}

void Controller::Start() {

	int choice = 0;

	do {
		std::cin >> choice;
		if (choice >= 3 || choice < 1) {
			printf("Not a valid input!\n");
		} else if (choice == 1) {
			StartGame();
		} 
	} while (choice != 2);
}

void Controller::StartGame() {

	graphics.Stats();
	graphics.Board();
	graphics.MenuChooseNumber();
	Mark();
}

void Controller::Mark() {
	int choice = -1;

	std::cin >> choice;
	
	switch (choice) {
		case 0:
			board.ChangeGameBoard();
			graphics.Board();
			break;

	}
}