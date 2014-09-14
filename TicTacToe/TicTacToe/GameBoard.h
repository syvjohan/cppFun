#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class GameBoard {

public:
	GameBoard();
	~GameBoard();
	char *boardMark;

	void ChangeGameBoard();

private:
	int size;
	int nextIndex;
};

#endif //!GAMEBOARD_H