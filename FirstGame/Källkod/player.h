#ifndef PLAYER_H
#define PLAYER_H

#include "tinymath.h"

#define PLAYER_SIZE 40 

struct Player {
	tiRect box;
	tiPhysics ph;
	int canJump;
};

extern Player player;

//Update player rectangle and make sure it's centralized.
void updatePlayer();

//set pos and lineardrag
void setPlayer();

void pMoveLeft();

void pMoveRight();

void pMoveUp();

void pMoveDown();

#endif //!PLAYER_H