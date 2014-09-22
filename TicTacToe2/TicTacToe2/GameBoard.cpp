#include "GameBoard.h"
#include <iostream>

typedef int** IntArray2D;
typedef const int * const * ConstIntArray2D;

int CheckTile(ConstIntArray2D board, int row, int col);

GameBoard::GameBoard() {
	currentState = GS_MAINMENU;
	numbOfMoves = 0;
	size = 3;
	boarder = new int*[size];
	for (int i = 0; i != size; i++) {
		boarder[i] = new int[size];
		for (int j = 0; j != size; ++j)  {
			boarder[i][j] = 0;
		}
	}
}
GameBoard::~GameBoard() {
	delete[] boarder;
}

void GameBoard::InitializeGame() {

}

bool GameBoard::IsRunning() {
	if (CurrentState() != GS_QUIT) {
		return true;
	}
	return false;
}

bool GameBoard::UpdateBorder(int newValue) {
	int row = newValue % 3;
	int col = newValue / 3;
	if (ValidateMark(row, col)) {
		boarder[row][col] = Turn();
		return true;
	}
	return false;
}

bool GameBoard::ValidateMark(const int row, const int col) {
	if (boarder[row][col] == 0) {
		return true;
	}
	return false;
}

bool GameBoard::ValidateInput(const int value) const {
	if (!(isdigit(value))) {
		if (value == 1 || value == 2) {
			return true;
		}
	}
	return false;
}

//If input is bigger or equal to "high and input is smaller or equal to low.
bool GameBoard::ValidNumber(int input, int high, int low) {
	if (!isdigit(input)) {
		if (input <= high && input >= low) {
			return true;
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

GameState GameBoard::CurrentState() const {
	return currentState;
}

//Reset GameBoard.
void GameBoard::Reset() {
	memset(boarder, 0, sizeof(int) * 9);
	numbOfMoves = 0;
	currentState = GS_MAINMENU;
}

int GameBoard::CheckForWinner() const {

	int winner = 0;

	for (int i = 0; i != 3; ++i)
	for (int j = 0; j != 3; ++j) {
		if (!(i % 2 || j % 2)) {
			winner = CheckTile(boarder, i, j);
			if (winner) {
				return winner;
			}
		}
	}
	return winner;
}

int CheckTile(ConstIntArray2D board, int row, int col) {
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

int GameBoard::NumbOfMoves() {
	return numbOfMoves++;
}

int GameBoard::Turn() {
	if ((numbOfMoves % 2) == 0) {
		return 2;
	}
	return 1;
}