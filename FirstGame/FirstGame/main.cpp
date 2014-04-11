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
	point min;
	point max;
} player, barrier;

const int rectSize = 40;
const int numBarrier = 10;

rectangle arr[numBarrier];

void fillRect(int x, int y, int w, int h, int color) {
	SDL_Rect rect = {x, y, w, h};
	SDL_FillRect(surface, &rect, color);
}

void drawBarriers() {
	for (int i = 0; i < numBarrier; i++) {
		fillRect(arr[i].min.x, arr[i].min.y, rectSize, rectSize, RGB_COLOR(255, 0, 255));		
	}
}

void barrierRect() {
 	for (int i = 0; i < numBarrier; i++) {
		arr[i].min.x = (rand() % 1180 + 50);
		arr[i].min.y = (rand() % 620 + 50);
		arr[i].max.x = arr[i].min.x + rectSize;
		arr[i].max.y = arr[i].min.y + rectSize;
	}
}

void playerRect() {
	fillRect(player.min.x, player.min.y, player.max.x - player.min.x, player.max.y - player.min.y, RGB_COLOR(255, 255, 0));
}

void wallCollision() {
	if (player.min.x < 0) {
			player.min.x = 0;
			player.max.x = rectSize;
	}
	if (player.min.y < 0) {
			player.min.y = 0;
			player.max.y = rectSize;
	}
	if (player.max.x > screenWidth) {
			player.max.x = screenWidth;
			player.min.x = screenWidth - rectSize;
	}
	if (player.max.y > screenHeight) {
			player.max.y = screenHeight;
			player.min.y = screenHeight - rectSize;
	}
}

void DoCollisions() {
	
}

void controlls() {
	const Uint8 *keys = SDL_GetKeyboardState(0); 
			if (keys[SDL_SCANCODE_LEFT]) {
				--player.min.x;
				--player.max.x;
			}
			if (keys[SDL_SCANCODE_RIGHT]) {
				++player.min.x;
				++player.max.x;
			}
			if (keys[SDL_SCANCODE_UP]) {
				--player.max.y;
				--player.min.y;
			}
			if (keys[SDL_SCANCODE_DOWN]) {
				++player.max.y;
				++player.min.y;
			}
}

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("FirstGame", 150, 150, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, 0, 0);
	surface = SDL_GetWindowSurface(window);

	barrierRect();	

	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			// quit window
			if (event.type == SDL_QUIT) {
				running = false;
			}	
		}

		fillRect(0, 0, screenWidth, screenHeight, 0);

		drawBarriers();
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

