#ifndef PLAYER_H
#define PLAYER_H
#include "rectangle.h"

rect player;
const int playerSize = 40;

void moveLeft() {
	--player.min.x;
	--player.max.x;
}

void moveRight() {
	++player.min.x;
	++player.max.x;
}

void moveUp() {
	--player.max.y;
	--player.min.y;
}

void moveDown() {
	++player.max.y;
	++player.min.y;
}

#endif //!PLAYER_H