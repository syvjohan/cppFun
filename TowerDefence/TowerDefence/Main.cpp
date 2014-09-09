#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 840


void Window();

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING); //returns -1 when error occurce.

	Window();

	return 0;
}

void Window() {

	//Window properties.
	SCREEN_HEIGHT;
	SCREEN_WIDTH;

	SDL_Window* window = NULL;
	
	SDL_Surface *screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	} else {
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		} else {
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait two seconds
			SDL_Delay(000);
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();
}