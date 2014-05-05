#ifndef COLLISION_H
#define COLLISION_H

#include "player.h"
#include "bullet.h"
#include "enemy.h"

const int screenWidth = 1280;
const int screenHeight = 720;

inline void wallCollision() {
	if (player.box.min.x < 0) {
		player.ph.position.x = playerSize / 2;
	}
	if (player.box.min.y < 0) {
		player.ph.position.y = playerSize / 2;

	}
	if (player.box.max.x > screenWidth) {
		player.ph.position.x = screenWidth - playerSize / 2;
	}
	if (player.box.max.y > screenHeight) {
		player.ph.position.y = screenHeight - playerSize / 2;
		player.canJump = 1;
		player.ph.velocity.y *= 0.01f;
	}
}

#endif //"COLLISION_H