#include "GameBoard.h"
#include <iostream>
#include <string>

GameBoard::GameBoard() {
	boardMark = "012345678";
	nextIndex = 0;
}

GameBoard::~GameBoard() {

}
bool GameBoard::ChangeGameBoard(const int mark){
	if (isdigit(boardMark.at(mark))) {
		boardMark.at(mark) = 'X';
		return true;
	}
	return false;
}

char GameBoard::ReturnBoardMark(const int pos) const{
	char s = boardMark.at(pos);
	return s;
}
