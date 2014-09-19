#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <string>

class GameBoard {

public:
	GameBoard();
	~GameBoard();

	void ChangeGameBoardX(const int mark);
	void ChangeGameBoardO(const int mark);
	char ReturnBoardMark(const int pos) const;
	int ValidateMark(const int mark) const;

private:
	std::string boardMarks;

};

#endif //!GAMEBOARD_H