#ifndef PLAYER_H
#define PLAYER_H

#include "tinymath.h"

struct Player {
	tiRect box;
	tiPhysics ph;
	int canJump;
}player;

const int playerSize = 40;

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
		tiVec2 v = {0, -150000};
		tiPhysicsApplyForce(v, &player.ph);
		player.canJump = 0;
	}
}

inline void pMoveDown() {
	tiVec2 v = {0, 250};
	tiPhysicsApplyForce(v, &player.ph);
}

#endif //!PLAYER_H