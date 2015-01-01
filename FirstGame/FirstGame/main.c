#include <SDL.h>
#include <stdio.h>

#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "collision.h"
#include "level.h"
#include "Defs.h"

#undef main

SDL_Window *window = NULL;
SDL_Event event;
SDL_Renderer *render = NULL;
SDL_Surface *surface, *background = NULL/*, *mario, *sprite*/;
//SDL_PixelFormat *pixelformat;
//SDL_Rect Sprite, src;

//void loadImages() {
//	background = SDL_LoadBMP("img/wallpaper.bmp");
//	//mario = SDL_LoadBMP("img/mario.bmp");
//	/*sprite = SDL_ConvertSurface(mario, pixelformat, 0);*/
//	//SDL_FreeSurface(mario);
//}

void loadImage() {
	background = SDL_LoadBMP("img/wallpaper.bmp");
}

void fillRect(int x, int y, int w, int h, int color) {
	SDL_Rect rect = {x, y, w, h};
	SDL_FillRect(surface, &rect, color);
}

//void drawImage(SDL_Surface *img, int x, int y) {
//	SDL_Rect rect;
//	rect.x = x;
//	rect.y = y;
//	SDL_BlitSurface(img, NULL, surface, &rect);
//	SDL_BlitSurface(sprite, &Sprite, surface, &src);
//}

//void drawBackground() {
//	drawImage(background, 0, 0);
//}

void drawPlayer() {
	fillRect(player.box.min.x, player.box.min.y, player.box.max.x - player.box.min.x, player.box.max.y - player.box.min.y , RGB_COLOR(255, 255, 0));
}

void drawEnemy() {
	int i;
	for (i = 0; i < NUM_ENEMY; i++) {
		fillRect(arrEnemy[i].box.min.x, arrEnemy[i].box.min.y, arrEnemy[i].box.max.x - arrEnemy[i].box.min.x, arrEnemy[i].box.max.y - arrEnemy[i].box.min.y, RGB_COLOR(255, 0, 255));		
	}	
}

//void drawBullets() {
//	for (int i = 0; i < 2; i++) {
//		fillRect(bullets.max.y, bullets.min.y, bulletSize, bulletSize, RGB_COLOR(255, 0, 255));		
//	}
//}

//collision between player and enemy.
void playerCollEnemy() {
	int i;
	for (i = 0; i < NUM_ENEMY; i++) 
	{
		if (tiRectIntersects(player.box, arrEnemy[i].box)) 
		{
			tiVec2 mtv = tiRectMTV(player.box, arrEnemy[i].box);
			player.ph.position = tiVec2Add(player.ph.position, mtv);
		}
	}
}

//make enemy chase player.
void chasePlayer() {
	int i;
	for (i = 0; i < NUM_ENEMY; i++) 
	{
		return moveEnemy(player.box, arrEnemy[i].box);
	}
}

void shoot() {
	//if (lastBulletTime + bulletIntervall <= SDL_GetTime
}

void integratePhysics(float delta) {
	tiPhysicsIntegrate(&player.ph, delta);

	int i;
	for (i = 0; i < NUM_ENEMY; i++) 
	{
		tiPhysicsIntegrate(&arrEnemy[i].ph, delta);
	}
}

//controlls for player movement.
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

	window = SDL_CreateWindow("FirstGame", 600, 200, screenWidth, screenHeight, SDL_WINDOW_SHOWN); //Second and third argument is for screen position
	render = SDL_CreateRenderer(window, 0, 0);
	surface = SDL_GetWindowSurface(window);

	int time;
	int lastTime;
	float delta;
	time = lastTime = SDL_GetTicks(); // båda får samma värde

	//set pos and lineardrag.
	setEnemy();
	setPlayer();


	SDL_Rect backRect;
	backRect.x = 100;
	backRect.y = 120;

	SDL_FillRect(surface, NULL, 0x221122);

	//loadImage();
	//loadImages();

	//Sprite.x = 150;
	//Sprite.y = 120;

	//src.x = 128;
	//src.y = 0;
	//src.w = SPRITESIZE;
	//src.h = SPRITESIZE;

	//blockPosition();
	setEnemyStartPos();

	bool running = 1;
	while (running == 1) {
		while (SDL_PollEvent(&event)) 
		{
			// quit window
			if (event.type == SDL_QUIT) 
			{
				running = 0;
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
	/*	drawBackground();*/

		//Objects for chasing other objects
		//chasePlayer();

		//controlls for player movement.
		controlls();
	
		// Integrates a physics object using standard newton.
		integratePhysics(delta);

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
