#ifndef ENEMY_H
#define ENEMY_H

#include "tinymath.h"
#include <random>

struct Enemy {
	tiRect box;
	tiPhysics ph;
}enemy;

const int enemySize = 40;
const int numEnemy = 11;	
tiRect arrEnemy[numEnemy];

void enemyRectPos() {
	for (int i = 0; i < numEnemy; i++) {
		arrEnemy[i].min.x = (rand() % 1180 + 50);
		arrEnemy[i].min.y = (rand() % 620 + 50);
		arrEnemy[i].max.x = arrEnemy[i].min.x + enemySize;
		arrEnemy[i].max.y = arrEnemy[i].min.y + enemySize;
	}
}

//update enemy rectangle and make sure it's centralized.
inline void updateEnemy() {
	tiRectSet(enemy.ph.position.x - enemySize / 2, 
				enemy.ph.position.y - enemySize / 2,
				enemySize, enemySize,
				&enemy.box);
}

//set pos and lineardrag
inline void setEnemy() {
	enemy.ph.linearDrag = 0.003f;
	enemy.box.min.x = enemySize;
	enemy.box.max.y = enemySize;
}

inline void moveEnemy(const tiRect &r1, tiRect &r2) {
	//moveDown.
	if (r1.min.x > r2.min.x) {
			tiVec2 v = {0, -1500000};
			tiPhysicsApplyForce(v, &enemy.ph);
	}
	//moveLeft.
	if (r1.min.x < r2.min.x) {
			tiVec2 v = {-1500000, 0};
			tiPhysicsApplyForce(v, &enemy.ph);
	}
	//moveUp.
	if (r1.max.y < r2.max.y) {
			tiVec2 v = {0, 1500000};
			tiPhysicsApplyForce(v, &enemy.ph);
	}
	//moveRight.
	if (r1.max.y > r2.max.y) {
			tiVec2 v = {1500000, 0};
			tiPhysicsApplyForce(v, &enemy.ph);
	}
}

inline void eMoveLeft() {
tiVec2 v = {1500000, 0};
			tiPhysicsApplyForce(v, &enemy.ph);
}

#endif //!ENEMY_H