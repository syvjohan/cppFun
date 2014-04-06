#include <SDL.h>
#include <cstdio>

#include "Game.h"
#include "SDLRenderer.h"

#undef main

SDL_Window *window;
SDL_Event event;

const int screenWidth = 1280;
const int screenHeight = 720;

int main (int argc, char **argv) {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("GameBoard", 50, 50, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

	SDLRenderer renderer(window);
	Game game;


	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			// make it possible to quit window
			if (event.type == SDL_QUIT) {
				running = false;
			}

			if (event.type == SDL_KEYDOWN)
			{
				// Ignore repeating keys
				if (event.key.repeat == 0)
				{
					Point direction;

					if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
						direction.x = 1;
					if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
						direction.x = -1;
					if (event.key.keysym.scancode == SDL_SCANCODE_UP)
						direction.y = -1;
					if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
						direction.y = 1;


					EventManager::PushEvent(EventPTR(new MoveEvent(direction)));
				}
			}

			if (event.type == SDL_KEYUP)
			{
				Point direction;

				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					direction.x = -1;
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					direction.x = 1;
				if (event.key.keysym.scancode == SDL_SCANCODE_UP)
					direction.y = 1;
				if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
					direction.y = -1;

				EventManager::PushEvent(EventPTR(new MoveEvent(direction)));
			}
		}

		// Update game state.
		game.Update();

		EventManager::HandleEvents();

		// Render Game.
		game.Render(&renderer);


		SDL_Delay(0);
	}

	SDL_DestroyWindow(window);

	SDL_Quit();
	
	return 0;
}

//dll filen ska ligga i samma map som exe för att exe ska kunna köras.
// Rachel Moore spel tutorials.
//Pick and stick