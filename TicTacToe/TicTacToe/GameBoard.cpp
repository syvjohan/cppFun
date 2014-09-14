#include "GameBoard.h"
#include <iostream>


GameBoard::GameBoard() {
	size = 10;
	boardMark = new char[size];
	boardMark = "012345678";
	nextIndex = 0;
}

GameBoard::~GameBoard() {
	delete[] boardMark;
}

void GameBoard::ChangeGameBoard() {

	boardMark[0] = 'X';
	
}

// O 79 88 X