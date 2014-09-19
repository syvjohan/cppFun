#include "ConsoleView.h"
#include "Model.h"
#include <iostream>
#include <string>

using namespace std;

GameBoard gameBoard;

ConsoleView::ConsoleView() {

}

ConsoleView::~ConsoleView() {

}

void ConsoleView::HandleInput() {
	int choice = -1;

	if (gameBoard.CurrentState() == GS_MAINMENU) {
		DrawMainMenu();
		cin >> choice;
		if ( choice == 1) {
			gameBoard.SetState(GS_GAME);
		} else if (choice == 2) {
			gameBoard.SetState(GS_QUIT);
		} else {
			HandleInput();
			}	
	} else if (gameBoard.CurrentState() == GS_GAME) {
		//We're now in game mode. Take input for game board things.
		DrawGameBoard();
	}
}

void ConsoleView::DrawMainMenu() {
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t\tPress 1 to start a new game\n"
		   "\t\t\tPress 2 to exit\n");
	printf("\t\t-------------------------------------------------\n");
}

void DrawGameBoard() {
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t|");
	printf("\t%c", gameBoard.Returnboarder(0, 0));

	printf("\t|");
	printf("\t%c", gameBoard.Returnboarder(0, 1));
	printf("\t|");
	printf("\t%c", gameBoard.Returnboarder(0, 2));
	printf("\t|\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");

	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t|");
	printf("\t%c", gameBoard.Returnboarder(1, 0));
	printf("\t|");
	printf("\t%c", gameBoard.Returnboarder(1, 1));
	printf("\t|");
	printf("\t%c", gameBoard.Returnboarder(1, 2));
	printf("\t|\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");

	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t|");
	printf("\t%c", gameBoard.Returnboarder(2, 0));
	printf("\t|");
	printf("\t%c", gameBoard.Returnboarder(2, 1));
	printf("\t|");
	printf("\t%c", gameBoard.Returnboarder(2, 2));
	printf("\t|\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t-------------------------------------------------\n");
}

void ConsoleView::Update() {
	if (gameBoard.CurrentState() == GS_MAINMENU)  {
		// Draw Main Menu...
	} else if (gameBoard.CurrentState() == GS_GAME)  {
		// Draw Game board...
	}
}
