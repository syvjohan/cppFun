#include "enemy.h"

Enemy arrEnemy[NUM_ENEMY];

void setEnemyStartPos() {
	for (int i = 0; i < NUM_ENEMY; i++) 
	{
		arrEnemy[i].ph.position.x = (rand() % 1180) + 50;
		arrEnemy[i].ph.position.y = (rand() % 620) + 50;
		/*arrEnemy[i].box.min.x = (rand() % 1180 + 50);
		arrEnemy[i].box.min.y = (rand() % 620 + 50);
		arrEnemy[i].box.max.x = arrEnemy[i].box.min.x + ENEMY_SIZE;
		arrEnemy[i].box.max.y = arrEnemy[i].box.min.y + ENEMY_SIZE;*/
	}
}

//update enemy rectangle and make sure it's centralized.
void updateEnemy() {
	for (int i = 0; i < NUM_ENEMY; i++) 
	{
		tiRectSet(arrEnemy[i].ph.position.x - ENEMY_SIZE / 2, 
				arrEnemy[i].ph.position.y - ENEMY_SIZE / 2,
				ENEMY_SIZE, ENEMY_SIZE,
				&arrEnemy[i].box);
	}
}

//set pos and lineardrag
void setEnemy() {
	for (int i = 0; i < NUM_ENEMY; i++) 
	{
		arrEnemy[i].ph.linearDrag = 0.003f;
		arrEnemy[i].box.min.x = ENEMY_SIZE;
		arrEnemy[i].box.max.y = ENEMY_SIZE;
	}
}

void moveEnemy(const tiRect &r1, tiRect &r2) {
	for (int i = 0; i < NUM_ENEMY; i++) 
	{
		//moveDown.
		if (r1.min.x > r2.min.x) 
		{
				tiVec2 v = {0, -1500000};
				tiPhysicsApplyForce(v, &arrEnemy[i].ph);
		}
		//moveLeft.
		if (r1.min.x < r2.min.x) 
		{
				tiVec2 v = {-1500000, 0};
				tiPhysicsApplyForce(v, &arrEnemy[i].ph);
		}
		//moveUp.
		if (r1.max.y < r2.max.y) 
		{
				tiVec2 v = {0, 1500000};
				tiPhysicsApplyForce(v, &arrEnemy[i].ph);
		}
		//moveRight.
		if (r1.max.y > r2.max.y) 
		{
				tiVec2 v = {1500000, 0};
				tiPhysicsApplyForce(v, &arrEnemy[i].ph);
		}
	}
}