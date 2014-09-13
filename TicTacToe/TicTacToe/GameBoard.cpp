#include "GameBoard.h"
#include <iostream>


GameBoard::GameBoard() {
	size = 9;
	board = new int[size];
	nextIndex = 0;
}

GameBoard::~GameBoard() {
	delete[] board;
}

int GameBoard::CreateBoard(int input) {
	*board = 0, 1, 2, 3, 4, 5, 6, 7, 8;

	for (int i = 0; i <= size; i++) {
		if (input == i) {
			return i;
		} 
	}
}