#include <SDL.h>
#include <cstdio>

#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "collision.h"
#include "level.h"

#define RGB_COLOR(R, G, B) (((B) << 24) | ((G) << 16) | ((R) << 8)) 
#undef main

SDL_Window *window;
SDL_Event event;
SDL_Renderer *render;
SDL_Surface *surface;

void fillRect(int x, int y, int w, int h, int color) {
	SDL_Rect rect = {x, y, w, h};
	SDL_FillRect(surface, &rect, color);
}

void drawPlayer() {
	fillRect(player.box.min.x, player.box.min.y, player.box.max.x - player.box.min.x, player.box.max.y - player.box.min.y , RGB_COLOR(255, 255, 0));
}

void drawEnemy() {
	for (int i = 0; i < numEnemy; i++) {
		fillRect(arrEnemy[i].min.x, arrEnemy[i].min.y, arrEnemy[i].max.x - arrEnemy[i].min.x, arrEnemy[i].max.y - arrEnemy[i].min.y, RGB_COLOR(255, 0, 255));		
	}	
}

//void drawBullets() {
//	for (int i = 0; i < 2; i++) {
//		fillRect(bullets.max.y, bullets.min.y, bulletSize, bulletSize, RGB_COLOR(255, 0, 255));		
//	}
//}

//collision between player and enemy.
void playerCollEnemy() {
	for (int i = 0; i < numEnemy; i++) {
		if (tiRectIntersects(player.box, arrEnemy[i])) {
		tiVec2 mtv = tiRectMTV(player.box, arrEnemy[i]);
		player.ph.position = tiVec2Add(player.ph.position, mtv);
		}
	}
}

//make enemy chase player.
void chasePlayer() {
	for (int i = 0; i < numEnemy; i++) {
		moveEnemy(player.box, arrEnemy[i]);
	}
}

void shoot() {
	//if (lastBulletTime + bulletIntervall <= SDL_GetTime
}

//controlls for player movement.
void controlls() {
	const Uint8 *keys = SDL_GetKeyboardState(0); 
	if (keys[SDL_SCANCODE_LEFT]) {
		pMoveLeft();
		eMoveLeft();
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		pMoveRight();
	}
	if (keys[SDL_SCANCODE_UP]) {
		pMoveUp();
	}
	if (keys[SDL_SCANCODE_DOWN]) {
		pMoveDown();
	}
	if (keys[SDL_SCANCODE_J]) {
		shoot();
	}
}

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("FirstGame", 600, 200, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, 0, 0);
	surface = SDL_GetWindowSurface(window);

	int time;
	int lastTime;
	float delta;
	time = lastTime = SDL_GetTicks(); // båda får samma värde

	//set pos and lineardrag.
	setEnemy();
	setPlayer();

	//blockPosition();
	enemyRectPos();

	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			// quit window
			if (event.type == SDL_QUIT) {
				running = false;
			}	
		}

		time = SDL_GetTicks();
		delta = ((float)time - (float)lastTime) /1000.0f; //sekunder

		fillRect(0, 0, screenWidth, screenHeight, 0);

		//drawing objects.
		//drawBlock();
		drawEnemy();
		drawPlayer();
		//drawBullets();

		//Objects for chasing other objects
		chasePlayer();

		//controlls for player movement.
		controlls();
	
		// Integrates a physics object using standard newton.
		tiPhysicsIntegrate(&player.ph, delta);
		tiPhysicsIntegrate(&enemy.ph, delta);

		//update objects.
		updatePlayer();
		updateEnemy();

		//collision.
		wallCollision();
		playerCollEnemy();

		SDL_UpdateWindowSurface(window);
		SDL_Delay(0);
		lastTime = time;
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
