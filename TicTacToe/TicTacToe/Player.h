#ifndef PLAYER_H
#define PLAYER_H

#include "GameInfo.h"

class Player {
	friend  class GameInfo;
public:
	Player();
	~Player();

	void Player1(std::string name, int wins, int loses, int numOfMoves);
	void Player2(std::string name, int wins, int loses, int numOfMoves);
	void SetP1Name(std::string name);
	void SetP2Name(std::string name);

private:
	std::string player1;
	std::string player2;
	int offset;
	
};

#endif //!PLAYER_H
