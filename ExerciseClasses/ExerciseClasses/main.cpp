#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>

using namespace std;

#undef main

SDL_Window *window = NULL;
SDL_Event event;
SDL_Renderer *render = NULL;
//An SDL surface is just an image data type that contains the pixels of 
//an image along with all data needed to render it. SDL 
SDL_Surface *screenSurface, *backgroundImg = NULL;

int screenWidth = 1200;
int screenHeight = 700;

string pathBmp = "img/background.bmp";
//string pathPng = "img/grass2.png"; // Bit depth need to be 8-byte.

SDL_Surface *LoadSurface(string path) {

	//The final optimized image
	SDL_Surface *optimizedSurface = NULL;

	SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str()); //load BMP
	//SDL_Surface *loadedSurface = IMG_Load(path.c_str()); //load png
	if (loadedSurface == NULL) {
		printf("failed to load media %s\n", path.c_str(), IMG_GetError());
	}
	else {
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, NULL);

		if (optimizedSurface == NULL) {
			printf("Unable to optimize image%s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

bool LoadImage() {

	bool success = true;

	backgroundImg = LoadSurface(pathBmp); //bmp image
	if (backgroundImg == NULL) {
		printf("failed to load image %s\n");
		success = false;
	}

	return success;
}

int main() {

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("LOLOLOOOL", 600, 200, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, 0, 0);

	screenSurface = SDL_GetWindowSurface(window);
	
	bool running = true;
	while (running) {
		if (!LoadImage()) {
			printf("Failed to load backgroundimage %s\n");
		}
		else {

			while (SDL_PollEvent(&event)) {
				// quit window
				if (event.type == SDL_QUIT) {
					running = false;
				}
			}

			SDL_UpdateWindowSurface(window);
			SDL_Delay(0);
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}