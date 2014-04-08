#include "SDL.h"
#include "cstdio"

#undef main

SDL_Window *window;
SDL_Event event;

const int screenWidth = 1280;
const int screenHeight = 720;

int main(int argc, char argv) {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("FirstGame", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			// quit window
			if (event.type == SDL_QUIT) {
				running = false;
			}
			if (event.type == SDL_KEYDOWN) {
				//TODO key events
			}
		}

		SDL_Delay(3);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}