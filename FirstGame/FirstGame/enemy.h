#ifndef ENEMY_H
#define ENEMY_H

#include "tinymath.h"

struct Enemy {
	tiRect box;
	tiPhysics ph;
}enemy;

const int enemySize = 40;
const int numEnemy = 11;	
tiRect arrEnemy[numEnemy];

inline void EnemyRectPos() {
	for (int i = 0; i < numEnemy; i++) {
		arrEnemy[i].min.x = (rand() % 1180 + 50);
		arrEnemy[i].min.y = (rand() % 620 + 50);
		arrEnemy[i].max.x = arrEnemy[i].min.x + enemySize;
		arrEnemy[i].max.y = arrEnemy[i].min.y + enemySize;
	}
}

//inline void eMoveLeft() {
//	tiVec2 v = {-50, 0};
//	tiPhysicsApplyForce(v, &player.ph);
//	/*--r1.min.x;
//	--r1.max.x;*/
//}
//
//inline void eMoveRight() {
//	tiVec2 v = {50, 0};
//	tiPhysicsApplyForce(v, &player.ph);
//	/*++r1.min.x;
//	++r1.max.x;*/
//}
//
//inline void eMoveUp() {
//	tiVec2 v = {0, 50};
//	tiPhysicsApplyForce(v, &player.ph);
//	//--player.max.y;
//	//--player.min.y;
//}
//
//inline void eMoveDown() {
//	tiVec2 v = {0, -50};
//	tiPhysicsApplyForce(v, &player.ph);
//	/*++player.max.y;
//	++player.min.y;*/
//}
//
//inline void moveEnemy(const rect &r1, const rect &r2) {
//	if (r1.min.x > r2.min.x) {
//		eMoveDown();
//	}
//	if (r1.min.x < r2.min.x) {
//		eMoveLeft();
//	}
//	if (r1.max.y < r2.max.y) {
//		eMoveUp();
//	}
//	if (r1.max.x > r2.max.y) {
//		eMoveRight();
//	}
//}

#endif //!ENEMY_H