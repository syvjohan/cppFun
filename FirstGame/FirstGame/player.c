#include "player.h"


Player player;

//Update player rectangle and make sure it's centralized.
void updatePlayer() {
	tiRectSet(player.ph.position.x - PLAYER_SIZE / 2, 
				player.ph.position.y - PLAYER_SIZE / 2,
				PLAYER_SIZE, PLAYER_SIZE,
				&player.box);
}

//set pos and lineardrag
void setPlayer() {
	player.ph.linearDrag = 0.003f;
	player.box.min.x = PLAYER_SIZE;
	player.box.max.y = PLAYER_SIZE;
}

void pMoveLeft() {
	tiVec2 v = {-250, 0};
	tiPhysicsApplyForce(v, &player.ph);
}

void pMoveRight() {
	tiVec2 v = {250, 0};
	tiPhysicsApplyForce(v, &player.ph);
}

void pMoveUp() {
	if(player.canJump && player.ph.velocity.y > 0) 
	{
		tiVec2 v = {0, -1500000}; //change the jump height.
		tiPhysicsApplyForce(v, &player.ph);
		player.canJump = 0;
	}
}

void pMoveDown() {
	tiVec2 v = {0, 250};
	tiPhysicsApplyForce(v, &player.ph);
}