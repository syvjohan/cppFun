#include "Model.h"
#include <iostream>

int CheckTile(int** board, int row, int col);

GameBoard::GameBoard() {
	size = 3;
	//boarder = new int*[size];
	for (int i = 0; i != size; i++) {
		boarder[i] = new int[size];
	}
}
GameBoard::~GameBoard() {
	delete[] boarder;
}

void GameBoard::UpdateBorder(int row, int col, int newValue) {
	boarder[row][col] = newValue;
}

bool GameBoard::ValidateValue(const int newValue, const int oldValue) const {
	if (isdigit(newValue)) {
		if (newValue == 1 || newValue == 2) {
			if (!(oldValue == 1 || oldValue == 2)) {
				return true;
			}
		}
	}
	return false;
}

int GameBoard::Returnboarder(const int col, const int row) const {
	return boarder[row][col];
}

GameState GameBoard::SetState(GameState state ) {
	 return (currentState = state);
}

//Call this function from main() in main.cpp
void GameBoard::StartGame() {
	currentState = GS_MAINMENU;
}

//Reset GameBoard.
void GameBoard::Reset() {
	memset(boarder, 0, sizeof(int) * 9);
	turn = 0;
	currentState = GS_MAINMENU;
}

int GameBoard::CheckForWinner() const {

	int winner = 0;

	for (int i = 0; i != 3; ++i)
	for (int j = 0; j != 3; ++j) {
		if (!(i % 2 || j % 2)) {
			winner = CheckTile(boarder, i, j);

			if (winner)
				return winner;
		}
	}

	return winner;
}

int CheckTile(const int** board, int row, int col) {
	int value = board[row][col];

	if (col == 1 && row == 1) {
		if (board[row - 1][col - 1] == value && board[row + 1][col + 1] == value) return value;
		if (board[row - 1][col + 1] == value && board[row + 1][col - 1] == value) return value;
	} else if (col == 1) {
		// Check rows
		if (board[row][col - 1] == value && board[row][col + 1] == value)
			return value;
	} else if (row == 1) {
		// Check columns
		if (board[row - 1][col] == value && board[row + 1][col] == value)
			return value;
	}

	return 0;
}

int GameBoard::ReturnNumbOfMoves() {
	if ((numbOfMoves % 2) == 0) {
		return 0;
	}
	return 1;
}