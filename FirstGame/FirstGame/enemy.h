#ifndef ENEMY_H
#define ENEMY_H

#include "tinymath.h"
#include <random>

#define ENEMY_SIZE 40
#define NUM_ENEMY 11

typedef struct _Enemy {
	tiRect box;
	tiPhysics ph;
}Enemy;
	
extern Enemy arrEnemy[NUM_ENEMY];

void setEnemyStartPos();
//update enemy rectangle and make sure it's centralized.
void updateEnemy();
//set pos and lineardrag
void setEnemy();
void moveEnemy(const tiRect &r1, tiRect &r2);
#endif //!ENEMY_H

//använd def fil