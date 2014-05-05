#ifndef PLAYER_H
#define PLAYER_H
#include "rectangle.h"

rect player;
const int playerSize = 40;

void pMoveLeft() {
	--player.min.x;
	--player.max.x;
}

void pMoveRight() {
	++player.min.x;
	++player.max.x;
}

void pMoveUp() {
	--player.max.y;
	--player.min.y;
}

void pMoveDown() {
	++player.max.y;
	++player.min.y;
}

#endif //!PLAYER_H