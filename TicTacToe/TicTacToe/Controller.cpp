#include <iostream>
#include "Controller.h"
#include "Graphics.h"
#include "Player.h"
#include "GameBoard.h"
#include "GameBoardStates.h"
#include "GameInfo.h"

using namespace std;

Controller::Controller() {

}

Controller::~Controller() {

}

GameBoard gameBoard;
GameBoardStates gameBoardStates;
GameInfo gameInfo;
Graphics graphics;
Player player;

//This function is called from int main() in main.cpp
void Controller::InitializeGame() {
	graphics.Menu();
	StartMenu();
}

void Controller::StartMenu() {

	int choice = -1;

	do {
		cin >> choice;
		if (Isdigit() && ValidNumber(choice, 0, 9)) {
			if (choice == 1) {
				ChoosePlayerName();
			} else {
				printf("Choose an alternative in the menu, try again: ");
			}
		} else {
			printf("Not a valid input, try again: ");
		}
	} while (choice != 2);
}

void Controller::ChoosePlayerName() {
	string name1;
	string name2;

	//Ignore old data in cin.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//Set name for player 1.
	graphics.P1Name();
	getline(cin, name1);
	player.SetP1Name(name1);

	//Set name for player 2.
	graphics.P2Name();
	getline(cin, name2);
	player.SetP2Name(name2);

	UpdateGraphics();
}

//Decide if it's player 1 or player 2 turn to put a mark on the board.
void Controller::DecidePlayerTurn(int choice) {

	if (gameInfo.CheckNumbOfMoves() == 0) {
		gameBoard.ChangeGameBoardX(choice);
	} else {
		gameBoard.ChangeGameBoardO(choice);
	}
}

void Controller::UpdateGraphics() {
	string playerName = GetNumbOfMoves();

	graphics.Stats(gameInfo.NumbOfGames(), gameInfo.Wins(), gameInfo.Loses());
	graphics.Board();
	graphics.MenuChooseMark(playerName);
	PutMark();
}

//Put a mark on the board and check if player 1/2 have won or not.
void Controller::PutMark() {
	string playerName = GetNumbOfMoves();
	int choice = -1;
	cin >> choice;

	if (Isdigit() && (!(ValidNumber(choice, 9, -1)))) {
		DecidePlayerTurn(choice);
		//Only check if three or more marks have been put on the game board.
		if (gameInfo.numbOfMoves >= 3) {
			////Check if someone have won!
			//if (gameBoardStates.CheckStates() == 0) {
			//	graphics.WinnerIs(playerName);

			//	graphics.SubMenu();
			//} else if (gameBoardStates.CheckStates() == 1) {
			//	graphics.WinnerIs(playerName);

			//	graphics.SubMenu();
			///*} */else {
			//	UpdateGraphics();
			//}
		} else {
			UpdateGraphics();
		}
	} else {
		printf("Invalid input");
		UpdateGraphics();
	}
}

//Check if user input contains digits or not. If it's digit it returns true.
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

//returns player name based on even or odd number of moves.
std::string Controller::GetNumbOfMoves() {
	if ((gameInfo.numbOfMoves % 2) == 0) {
		//If the number is even 
		return player.GetP1Name();
	} else {
		//If the number is odd
		return player.GetP2Name();
	}
}