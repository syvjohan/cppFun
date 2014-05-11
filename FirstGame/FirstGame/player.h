#ifndef PLAYER_H
#define PLAYER_H

#include "tinymath.h"

struct Player {
	tiRect box;
	tiPhysics ph;
	int canJump;
}player;

const int playerSize = 40;

//Update player rectangle and make sure it's centralized.
inline void updatePlayer() {
	tiRectSet(player.ph.position.x - playerSize / 2, 
				player.ph.position.y - playerSize / 2,
				playerSize, playerSize,
				&player.box);
}

//set pos and lineardrag
inline void setPlayer() {
	player.ph.linearDrag = 0.003f;
	player.box.min.x = playerSize;
	player.box.max.y = playerSize;
}

inline void pMoveLeft() {
	tiVec2 v = {-250, 0};
	tiPhysicsApplyForce(v, &player.ph);
}

inline void pMoveRight() {
	tiVec2 v = {250, 0};
	tiPhysicsApplyForce(v, &player.ph);
}

inline void pMoveUp() {
	if(player.canJump && player.ph.velocity.y > 0) {
		tiVec2 v = {0, -1500000}; //change the jump.
		tiPhysicsApplyForce(v, &player.ph);
		player.canJump = 0;
	}
}

inline void pMoveDown() {
	tiVec2 v = {0, 250};
	tiPhysicsApplyForce(v, &player.ph);
}

#endif //!PLAYER_H