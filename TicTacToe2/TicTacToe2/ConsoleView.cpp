#include "ConsoleView.h"
#include "GameBoard.h"
#include <iostream>
#include <string>

using namespace std;

//GameBoard gameBoard;

ConsoleView::ConsoleView() {

}

ConsoleView::~ConsoleView() {

}

void ConsoleView::HandleInput() {
	do {
		int choice = -1;
		cin >> choice;
		if (model->ValidateInput(choice)) {
			if (choice == 1) {
				model->SetState(GS_GAME);
				return;
			} else if (choice == 2) {
				model->SetState(GS_QUIT);
				return;
			} else {
				//If the validation gets fucked upp stay in the loop!
				HandleInput();
			}
		}
	} while (model->CurrentState() != GS_QUIT);
}

void ConsoleView::Draw() {
	if (model->CurrentState() == GS_MAINMENU) {
		DrawMainMenu();
	} else if (model->CurrentState() == GS_GAME) {
		DrawGameBoard();
		GameMode();
	}
}

void ConsoleView::DrawMainMenu() {
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t\tPress 1 to start a new game\n"
		   "\t\t\tPress 2 to exit\n");
	printf("\t\t-------------------------------------------------\n");
}

void ConsoleView::DrawGameBoard() {
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t|");
	printf("\t%i", model->Returnboarder(0, 0));

	printf("\t|");
	printf("\t%i", model->Returnboarder(0, 1));
	printf("\t|");
	printf("\t%i", model->Returnboarder(0, 2));
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
	printf("\t%i", model->Returnboarder(1, 0));
	printf("\t|");
	printf("\t%i", model->Returnboarder(1, 1));
	printf("\t|");
	printf("\t%i", model->Returnboarder(1, 2));
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
	printf("\t%i", model->Returnboarder(2, 0));
	printf("\t|");
	printf("\t%i", model->Returnboarder(2, 1));
	printf("\t|");
	printf("\t%i", model->Returnboarder(2, 2));
	printf("\t|\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t-------------------------------------------------\n");
}

void ConsoleView::DrawWinner() {
	printf("\t\t-------------------------------------------------\n");
	printf("\t\tCongratulations you won!\n");
}

void ConsoleView::GameMode() {
	int input;
	do {
		printf("Choose a number to mark on the board: ");
		cin >> input;
		if (model->ValidNumber(input, 8, 0)) {
			// Insert value into array (border).
			if (model->UpdateBorder(input)) {
				model->NumbOfMoves(); // count ++ 
				DrawGameBoard();
				//Check for winner.
				if (model->CheckForWinner() == 1) {
					DrawWinner();
					model->Reset();
					model->SetState(GS_MAINMENU);
				}
			} else {
				printf("\nPlace is already occupied!\n");
			}
		} else {
			printf("\nInvalid input, try again!\n");
		}
	} while (model->CurrentState() != GS_MAINMENU);
}
