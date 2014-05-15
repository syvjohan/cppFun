#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>


using namespace std;

#undef main

SDL_Window *window = NULL;
SDL_Event event;
SDL_Renderer *render = NULL;
//An SDL surface is just an image data type that contains the pixels of 
//an image along with all data needed to render it. SDL 
SDL_Surface *surface, *backgroundBMP = NULL;

int screenWidth = 1200;
int screenHeight = 700;

string imgPath = "img/background.bmp";

SDL_Surface *LoadSurface(string path) {

	//The final optimized image
	SDL_Surface *optimizedSurface = NULL;

	SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL) {
		printf("failed to load media");
	}
	else {
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, surface->format, NULL);

		if (optimizedSurface == NULL) {
			printf("Unable to optimize image%s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

bool LoadImage() {

	bool success = false;

	backgroundBMP = LoadSurface("img/background.bmp");
	if (backgroundBMP == NULL) {
		printf("failed to load image");
		success = false;
	}
	else{
		success = true;
	}

	return success;
}

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("LOLOLOOOL", 600, 200, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, 0, 0);
	surface = SDL_GetWindowSurface(window);


	bool running = true;
	while (running) {

		if (!LoadImage()) {
			printf("Failed to load backgroundimage\n");
		}
		else {

			while (SDL_PollEvent(&event)) {
				// quit window
				if (event.type == SDL_QUIT) {
					running = false;
				}
			}
			//Kod för körning här!

			SDL_Rect stretchRect;
			stretchRect.x = 0;
			stretchRect.y = 0;
			stretchRect.w = screenWidth;
			stretchRect.h = screenHeight;
			// scale the image to the same size as the window...
			SDL_BlitScaled(backgroundBMP, NULL, surface, &stretchRect);


			SDL_UpdateWindowSurface(window);
			SDL_Delay(0);

		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}