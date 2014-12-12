#include "SDLGraphics.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *window = NULL; //Rendering window.

SDL_Surface *screenSurface = NULL; //Surface contained by the window.
SDL_Surface *image = NULL;

SDL_Renderer *renderer = NULL; //The window renderer

SDLGraphics::SDLGraphics() {
	InitializeSDL();
}

SDLGraphics::~SDLGraphics() {

}

void SDLGraphics::Draw() {

}

void SDLGraphics::HandleInput() {

}

void SDLGraphics::InitializeSDL() {
	//Start up SDL and create window
	if (!Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!LoadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				DrawBackground();

				//Update screen
				SDL_RenderPresent(renderer);
			}
		}
	}

	//Free resources and close SDL
	Close();
	
}

void SDLGraphics::DrawStructure() {
	//Clear screen
	SDL_SetRenderDrawColor(renderer, 0x50, 0x50, 0x50, 0xFF);
	SDL_RenderClear(renderer);

	SDL_Rect fillRect = { SCREEN_HEIGHT, SCREEN_WIDTH };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);

	////Render red filled quad
	//SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_RenderFillRect(renderer, &fillRect);

	//Render yellow outlined quad
	SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawRect(renderer, &outlineRect);

	////Draw horizontal line
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	//SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

	//Draw vertical line of yellow dots
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	{
		SDL_RenderDrawPoint(renderer, SCREEN_WIDTH * 2 / 3, i);
	}

	//Draw vertical line of yellow dots
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	{
		SDL_RenderDrawPoint(renderer, SCREEN_WIDTH * 2 / 4, i);
	}

	//Draw vertical line of yellow dots
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	{
		SDL_RenderDrawPoint(renderer, SCREEN_WIDTH * 2 / 6, i);
	}

	//Draw horizontal lines of yellow dots
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	for (int i = 0; i < SCREEN_WIDTH; i += 4)
	{
		SDL_RenderDrawPoint(renderer, SCREEN_HEIGHT / 4 , i);
	}

	////Draw horizontal lines of yellow dots
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	//for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	//{
	//	SDL_RenderDrawPoint(renderer, SCREEN_HEIGHT * 2 / 4, i);
	//}

	////Draw horizontal lines of yellow dots
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	//for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	//{
	//	SDL_RenderDrawPoint(renderer, SCREEN_HEIGHT * 2 / 6, i);
	//}
}

bool SDLGraphics::Init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool SDLGraphics::LoadMedia() {

	//Loading success flag
	bool success = true;

	//Nothing to load
	return success;

	////Loading success flag
	//bool success = true;

	////Load splash image
	//image = SDL_LoadBMP("hello_world.bmp");
	//if (image == NULL)
	//{
	//	printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
	//	success = false;
	//}

	//return success;
}

void SDLGraphics::Close() {
	//Destroy window	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}



