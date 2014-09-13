#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class GameBoard {

public:
	GameBoard();
	~GameBoard();

	int CreateBoard(int i);

private:
	int *board;
	int size;
	int nextIndex;
};

#endif //!GAMEBOARD_H