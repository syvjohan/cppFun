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
rectangle arr[];

void fillRect(int x, int y, int w, int h, int color) {
	SDL_Rect rect = {x, y, w, h};
	SDL_FillRect(surface, &rect, color);
}

rectangle barrierRect() {
	int pX;
	int pY;
	for (int i = 0; i != 10; i++) {
		pX = (barrier.width.x = (rand()  % 1180 + 50));
		pY = (barrier.height.y = (rand() % 620 + 50));
		arr[px];
		arr[pY];
		fillRect(pX, pY, rectSize, rectSize, RGB_COLOR(255, 0, 255));
	}

	for (

	return barrier;
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
		barrierRect();
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

