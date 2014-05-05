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

#endif //!ENEMY_H