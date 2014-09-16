#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <string>

class GameBoard {

public:
	GameBoard();
	~GameBoard();
	std::string boardMark;

	bool ChangeGameBoard(const int mark);
	char ReturnBoardMark(const int pos) const;

private:
	int nextIndex;
};

#endif //!GAMEBOARD_H