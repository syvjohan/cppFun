#include <SDL.h>
#include <cstdio>
#include <random>


#undef main
#define RGB_COLOR(R, G, B) (((B) << 24) | ((G) << 16) | ((R) << 8)) 

SDL_Window *window;
SDL_Event event;
SDL_Renderer *render;
SDL_Surface *surface;

const int screenWidth = 1280;
const int screenHeight = 720;

struct point {
	int x;
	int y;
};

struct rectangle {
	point width;
	point height;
} player, barrier;

const int rectSize = 40;
const int numBarrier = 10;

struct matrix {
	int arrX[numBarrier];
	int arrY[numBarrier];
}arr;

bool run = true;


void fillRect(int x, int y, int w, int h, int color) {
	SDL_Rect rect = {x, y, w, h};
	SDL_FillRect(surface, &rect, color);
}

void barrierRect(int x[], int y[]) {
	int pX;
	int pY;
	x = arr.arrX;
	y = arr.arrY;

	if (!run) {
		int drawBarrier(int x[], int y[]);
	}
	else if (run) {
 		for (int i = 0; i < numBarrier; i++) {
			pX = (rand() % 1180 + 50);
			pY = (rand() % 620 + 50);

			barrier.width.x = pX + 50;
			x[i] = barrier.width.x;

			barrier.height.y = pY + 50;
			y[i] = barrier.height.y;
		}
		run = false;	
	}
}

int drawBarrier(int x[], int y[]) {
	int p = 0;
	x = arr.arrX;
	y = arr.arrY;
	for (int i = 0; i <= x[i]; i++) {
		for (int k = 0; k <= y[k]; k++) {
			fillRect(x[i], y[k], rectSize, rectSize, RGB_COLOR(255, 0, 255));
		}
	}
	return p;
}

void playerRect() {
	fillRect(player.width.x, player.height.y, rectSize, rectSize, RGB_COLOR(255, 255, 0));
}

void wallCollision() {
	if (player.width.x > screenWidth) {
			player.width.x= screenWidth - rectSize;
		}
		if (player.height.y > screenHeight) {
			player.height.y = screenHeight - rectSize;
		}
		if (player.width.x < 0) {
			player.width.x = 0 + rectSize;
		}
		if (player.height.y < 0) {
			player.height.y = 0 + rectSize;
		}
		return;
}

void DoCollisions() {
	
}

void controlls() {
	const Uint8 *keys = SDL_GetKeyboardState(0); 
			if (keys[SDL_SCANCODE_LEFT]) {
				--player.width.x;
			}

			if (keys[SDL_SCANCODE_RIGHT]) {
				++player.width.x;
			}
			if (keys[SDL_SCANCODE_UP]) {
				--player.height.y;
			}
			if (keys[SDL_SCANCODE_DOWN]) {
				++player.height.y;
			}
}

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("FirstGame", 150, 150, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, 0, 0);
	surface = SDL_GetWindowSurface(window);

	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			// quit window
			if (event.type == SDL_QUIT) {
				running = false;
			}	
		}

		fillRect(50, 50, screenWidth, screenHeight, 0);

		barrierRect (arr.arrX, arr.arrY);	

		playerRect();

		controlls();
		wallCollision();

		SDL_UpdateWindowSurface(window);
		SDL_Delay(1);
	}
	
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

