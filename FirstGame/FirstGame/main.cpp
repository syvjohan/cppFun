#include <SDL.h>
#include <cstdio>
#include <random>

#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "collision.h"

#define RGB_COLOR(R, G, B) (((B) << 24) | ((G) << 16) | ((R) << 8)) 
#undef main

SDL_Window *window;
SDL_Event event;
SDL_Renderer *render;
SDL_Surface *surface;

//const int screenWidth = 1280; //TODO lös problemet med screen varibel placeringen!
//const int screenHeight = 720;

void fillRect(int x, int y, int w, int h, int color) {
	SDL_Rect rect = {x, y, w, h};
	SDL_FillRect(surface, &rect, color);
}

void playerRect() {
	fillRect(player.box.min.x, player.box.min.y, player.box.max.x - player.box.min.x, player.box.max.y - player.box.min.y , RGB_COLOR(255, 255, 0)); // rectSize rectSize
}

void drawEnemy() {
	for (int i = 0; i < numEnemy; i++) {
		fillRect(arrEnemy[i].min.x, arrEnemy[i].min.y, enemySize, enemySize, RGB_COLOR(255, 0, 255));		
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

// make enemy chase player.
//void chaseplayer() {
//	for (int i = 0; i < numEnemy; i++) {
//		moveEnemy(arrEnemy[i], player);
//	}
//}


void shoot() {
	//if (lastBulletTime + bulletIntervall <= SDL_GetTime
}

void controlls() {
	const Uint8 *keys = SDL_GetKeyboardState(0); 
	if (keys[SDL_SCANCODE_LEFT]) {
		pMoveLeft();
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

	player.ph.linearDrag = 0.003f;
	player.box.min.x = playerSize;
	player.box.max.y = playerSize;
	/*player.max.x = playerSize;
	player.max.y = playerSize;*/
	EnemyRectPos();

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

		drawEnemy();
		playerRect();
		//drawBullets();
		//moveEnemy();
	
		controlls();
	
		tiPhysicsIntegrate(&player.ph, delta);

		//uppdaterar spelarens rektangle så den är centrerad.
		tiRectSet(player.ph.position.x - playerSize / 2, 
					player.ph.position.y - playerSize / 2,
					playerSize, playerSize,
					&player.box);

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
