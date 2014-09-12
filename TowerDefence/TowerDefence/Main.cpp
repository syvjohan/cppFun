#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Defs.h"

SDL_Surface *pngSurface = nullptr;
SDL_Surface *LoadSurface(std::string path);
SDL_Surface *screenSurface = nullptr;
SDL_Window* window = nullptr;


void Window();
bool LoadMedia();
void Close();

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING); //returns -1 when error occurce.

	Window();

	if (LoadMedia()) {

		//Apply the png image
		SDL_BlitSurface(pngSurface, NULL, screenSurface, NULL);

		//Update the surface
		SDL_UpdateWindowSurface(window);
	} else {
		printf("failed to load media");
	}

	//Wait two seconds
	SDL_Delay(3000);

	Close();

	return 0;
}

void Window() {


	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	} else {
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		} else {

			//Initialize PNG loading
			int imgFlag = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlag) & imgFlag)) {
				printf("SDL_image could't be initialized");
			}

			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

		}
	}
}

bool LoadMedia() {
	
	pngSurface = LoadSurface("map.png");
	if (pngSurface != nullptr) {
		return true;
	} 
	return false;
}

SDL_Surface *LoadSurface( std::string path) {

	SDL_Surface *optimizedSurface = nullptr;

	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr) {
		printf("Unable to load surface and image:  %s\n", path.c_str());
	} else {
		// Convert surface to screen format.
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, NULL);
		if (optimizedSurface == nullptr) {
			printf("Unable tooptimize image");
		}

		//Get ride of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

void Close() {

	//Free loaded image.
	SDL_FreeSurface(pngSurface);
	pngSurface = nullptr;

	//Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;

	//Quit SDL subsystem
	IMG_Quit;
	SDL_Quit;

}
