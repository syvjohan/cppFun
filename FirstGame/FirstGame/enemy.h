#ifndef ENEMY_H
#define ENEMY_H

#include "rectangle.h"

const int enemySize = 40;
const int numEnemy = 11;	
rect arrEnemy[numEnemy];

void EnemyRectPos() {
	for (int i = 0; i < numEnemy; i++) {
		arrEnemy[i].min.x = (rand() % 1180 + 50);
		arrEnemy[i].min.y = (rand() % 620 + 50);
		arrEnemy[i].max.x = arrEnemy[i].min.x + enemySize;
		arrEnemy[i].max.y = arrEnemy[i].min.y + enemySize;
	}

}

void eMoveLeft(const rect &r1) {
	--r1.min.x;
	--r1.max.x;
}

void eMoveRight() {
	++player.min.x;
	++player.max.x;
}

void eMoveUp() {
	--player.max.y;
	--player.min.y;
}

void eMoveDown() {
	++player.max.y;
	++player.min.y;
}


void moveEnemy(const rect &r1, const rect &r2) {
	if (r1.min.x > r2.min.x) {
		eMoveDown();
	}
	if (r1.min.x < r2.min.x) {
		eMoveLeft();
	}
	if (r1.max.y < r2.max.y) {
		eMoveUp();
	}
	if (r1.max.x > r2.max.y) {
		eMoveRight();
	}
}

#endif //!ENEMY_H