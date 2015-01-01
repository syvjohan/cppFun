#include "collision.h"

void wallCollision() {
	if (player.box.min.x < 0) 
	{
		player.ph.position.x = PLAYER_SIZE / 2;
	}

	if (player.box.min.y < 0) 
	{
		player.ph.position.y = PLAYER_SIZE / 2;

	}

	if (player.box.max.x > screenWidth) 
	{
		player.ph.position.x = screenWidth - PLAYER_SIZE / 2;
	}

	if (player.box.max.y > screenHeight) 
	{
		player.ph.position.y = screenHeight - PLAYER_SIZE / 2;
		player.canJump = 1;
		player.ph.velocity.y *= 0.01f;
	}
}