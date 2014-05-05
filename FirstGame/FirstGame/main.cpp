#include <SDL.h>
#include <cstdio>
#include <random>

#include "enemy.h"
#include "math_physics.h"
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
	fillRect(player.min.x, player.min.y, player.max.x - player.min.x, player.max.y - player.min.y , RGB_COLOR(255, 255, 0)); // rectSize rectSize
}

void drawEnemy() {
	for (int i = 0; i < numEnemy; i++) {
		fillRect(arrEnemy[i].min.x, arrEnemy[i].min.y, enemySize, enemySize, RGB_COLOR(255, 0, 255));		
	}
}

void drawBullets() {
	for (int i = 0; i < 2; i++) {
		fillRect(bullets.max.y, bullets.min.y, bulletSize, bulletSize, RGB_COLOR(255, 0, 255));		
	}
}

//collision between player and enemy.
void playerCollEnemy() {
	for (int i = 0; i < numEnemy; i++) {
		if (rectIntersects(player, arrEnemy[i])) {
		vec2 mtv = rectMTV(player, arrEnemy[i]);
		player.min = vec2Add(player.min, mtv);
		player.max = vec2Add(player.max, mtv);
		}
	}
}

void enemyMovement() {
	for (int i = 0; i < numEnemy; i++) {
		if (player.min.x > arrEnemy[i].min.x) {
			++arrEnemy[i].min.x;
			++arrEnemy[i].max.x;
		}
		if (player.min.x < arrEnemy[i].min.x) {
			--arrEnemy[i].min.x;
			--arrEnemy[i].max.x;
		}
		if (player.max.y < arrEnemy[i].max.y) {
			--arrEnemy[i].max.y;
			--arrEnemy[i].min.y;
		}
		if (player.max.y > arrEnemy[i].max.y) {
			++arrEnemy[i].max.y;
			++arrEnemy[i].min.y;
		}
	}
}

void shoot() {
	//if (lastBulletTime + bulletIntervall <= SDL_GetTime
}

void controlls() {
	const Uint8 *keys = SDL_GetKeyboardState(0); 
	if (keys[SDL_SCANCODE_LEFT]) {
		moveLeft();
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		moveRight();
	}
	if (keys[SDL_SCANCODE_UP]) {
		moveUp();
	}
	if (keys[SDL_SCANCODE_DOWN]) {
		moveDown();
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

	player.max.x = playerSize;
	player.max.y = playerSize;
	EnemyRectPos();

	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			// quit window
			if (event.type == SDL_QUIT) {
				running = false;
			}	
		}

		fillRect(0, 0, screenWidth, screenHeight, 0);

		drawEnemy();
		playerRect();
		drawBullets();
		//enemyMovement();

		controlls();
		wallCollision();

		playerCollEnemy();

		SDL_UpdateWindowSurface(window);
		SDL_Delay(0);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
