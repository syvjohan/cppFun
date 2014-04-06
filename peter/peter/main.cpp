#include <SDL.h>
#include <cstdio>

#undef main
#define RGB_COLOR(R, G, B) (((B) << 24) | ((G) << 16) | ((R) << 8)) // macron kopieras där den används

SDL_Window *window;
SDL_Event event;
SDL_Renderer *render;
SDL_Surface *screenSurface;

struct POINT {
	int x;
	int y;
};

struct RECT {
	POINT topleft;
	POINT bottomRight;
}playerRect, barrierRect;

int dirX = 1;
int dirY = 1;

const int screenWidth = 1280;
const int screenHeight = 720;

const int rectSize = 40;

void fillRect(int x, int y, int w, int h, int color) {
	SDL_Rect rect = {x, y, w, h};
	SDL_FillRect(screenSurface, &rect, color);
}

void playerControll() {

	//Key, controll the key state.
	const Uint8 *keys = SDL_GetKeyboardState(0); 
	if (keys[SDL_SCANCODE_LEFT]) {
		--playerRect.bottomRight.x;
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		++playerRect.bottomRight.x;
	}
	if (keys[SDL_SCANCODE_UP]) {
		--playerRect.topleft.y;
	}
	if (keys[SDL_SCANCODE_DOWN]) {
		++playerRect.topleft.y;
	}
}

void rectGameBoard() { 
		fillRect(120, 120, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		/*fillRect(80, 50, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		fillRect(120, 50, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		fillRect(200, 50, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		fillRect(240, 50, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		fillRect(320, 50, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		fillRect(200, 180, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		fillRect(200, 220, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		fillRect(200, 240, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		fillRect(200, 280, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		fillRect(200, 320, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		fillRect(200, 360, rectSize, rectSize, RGB_COLOR(255, 0, 255));
		fillRect(200, 400, rectSize, rectSize, RGB_COLOR(255, 0, 255));*/
}

bool intersectRect (RECT playerRect, RECT barrierRect) {
	if (barrierRect.topleft.x >= playerRect.bottomRight.x
		|| barrierRect.bottomRight.x <= playerRect.topleft.x
		|| barrierRect.topleft.y <= playerRect.bottomRight.y
		|| barrierRect.bottomRight.y >=  playerRect.topleft.y)
		return true;

	return false;
}

void collisionWall() {
		if (playerRect.bottomRight.x > screenWidth) {
			playerRect.bottomRight.x= screenWidth - rectSize;
		}
		if (playerRect.topleft.y > screenHeight) {
			playerRect.topleft.y = screenHeight - rectSize;
		}
		if (playerRect.bottomRight.x < 0) {
			playerRect.bottomRight.x = 0 + rectSize;
		}
		if (playerRect.topleft.y < 0) {
			playerRect.topleft.y = 0 + rectSize;
		}
		return;
}

int main (int argc, char **argv) {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("GameBoard", 50, 50, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, 0, 0);
	screenSurface = SDL_GetWindowSurface(window);

	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			// make it possible to quit window
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		playerControll();

		fillRect(0, 0, screenWidth, screenHeight, 0);
		fillRect(playerRect.bottomRight.x, playerRect.topleft.y, rectSize, rectSize, RGB_COLOR(255, 255, 0));
		
		rectGameBoard();

		//collision wall
		collisionWall();
		// collision between player and barrier
		if (intersectRect(playerRect, barrierRect)) {
			printf("ba");
		}

		SDL_UpdateWindowSurface(window);

		SDL_Delay(0);
	}

	SDL_DestroyWindow(window);

	SDL_Quit();
	
	return 0;
}

//dll filen ska ligga i samma map som exe för att exe ska kunna köras.
// Rachel Moore spel tutorials.
//Pick and stick