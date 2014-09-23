#include "Defs.h"
#include "ConsoleView.h"
#include "GameBoard.h"
#include <iostream>
#include <string>

using namespace std;

ConsoleView::ConsoleView() {

}

ConsoleView::~ConsoleView() {

}

void ConsoleView::HandleInput() {
	model->SetState(GS_MAINMENU);

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
			}
		} else {
			printf("\nInvalid input try again!\n");
			ClearStream();
		}
	} while (model->CurrentState() != GS_QUIT);
}

void ConsoleView::Draw() {
	if (model->CurrentState() == GS_MAINMENU) {
		DrawMainMenu();
	} else if (model->CurrentState() == GS_GAME) {
		DrawHighscore();
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
	printf("\n\n");
	for (int i = 0; i != 3; ++i) {
		printf("\n\t\t-------------------------------------------------\n");
		printf("\t\t|");
		printf("\t\t|");
		printf("\t\t|");
		printf("\t\t|\n");
		printf("\t\t|");
		for (int j = 0; j != 3; ++j) {
			if (model->boarder[i][j] != 0) {
				printf("\t%c", model->boarder[i][j] == 1 ? 'X' : 'O');
			} else {
				printf("\t%i", i * 3 + j);
			}
			printf("\t|");
		}
	}
	printf("\n\t\t-------------------------------------------------\n");
}

void ConsoleView::DrawWinner() {
	printf("\t\t-------------------------------------------------\n");
	printf("\t\tCongratulations you won!\n");
}

void ConsoleView::DrawHighscore() {
	printf("\nPlayer 1 (O) wins: %i", model->GetP1Score());
	printf("\nPlayer 2 (X) wins: %i", model->GetP2Score());
}


void ConsoleView::GameMode() {
	int input;
	do {
		printf("\nChoose a number to mark on the board (0 - 8): ");
		cin >> input;
		if (model->ValidNumber(input, 8, 0)) {
			// Insert value into array (border).
			if (model->UpdateBorder(input)) {
				model->NumbOfMoves(); // count++ 
				DrawGameBoard();
				//Check for winner.
				if (model->CheckForWinner() != 0) {
					model->HighScore();
					DrawWinner();
					model->Reset();
					DrawMainMenu();
				}
			} else {
				printf("\nPlace is already occupied!\n");
				ClearStream();
			}
		} else {
			printf("\nInvalid input, try again!\n");
			ClearStream();
		}
	} while (model->CurrentState() != GS_MAINMENU);
}

void ConsoleView::ClearStream() {
	cin.clear();
	cin.ignore(std::numeric_limits<streamsize>::max(), ' ');
}