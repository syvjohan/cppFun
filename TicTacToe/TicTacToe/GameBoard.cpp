#include "GameBoard.h"
#include <string>

GameBoard::GameBoard() {
	boardMarks = "012345678";

}

GameBoard::~GameBoard() {

}

//Change character at a specific position to 'X' in boarderMark.
void GameBoard::ChangeGameBoardX(const int mark){
	boardMarks[mark] = 'X';
}
//Change character at a specific position to 'O' in boarderMark.
void GameBoard::ChangeGameBoardO(const int mark) {
	boardMarks[mark] = 'O';
}

//Return character at a specific position in boarderMark
char GameBoard::ReturnBoardMark(const int pos) const{
	return boardMarks[pos];
}

//Validate the character at a specific position in boarderMark.
int GameBoard::ValidateMark(const int mark) const{
	if (isdigit(boardMarks[mark])) {
		if (boardMarks[mark] == 'X') {
			return 1;
		}
		return 0;
	}
	return -2;
}
