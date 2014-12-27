#include "SDLGraphics.h"

#define RGB_COLOR(R, G, B) (((B) << 24) | ((G) << 16) | ((R) << 8)) 

SDLGraphics::SDLGraphics() {

	//InitializeSDL();
}

SDLGraphics::~SDLGraphics() {

}

void SDLGraphics::InitializeSDL() {
	surfGrid = NULL;
	surfX = NULL;
	surfO = NULL;
	window = NULL;
	screenSurface = NULL;
	window = NULL;
	renderer = NULL;
	currentPlayer = 0;
	OnExecute();
}

int SDLGraphics::OnExecute() {
	int time;
	int lastTime;
	float delta;
	time = lastTime = SDL_GetTicks(); // båda får samma värde
	OnInit();

	while (running) {
		while (SDL_PollEvent(&event)) {
			// quit window
			if (event.type == SDL_QUIT) {
				running = false;
			}

			if (event.type = SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT)
					LButtonClick();
			}
		}

		time = SDL_GetTicks();
		delta = ((float)time - (float)lastTime) / 1000.0f; //sekunder


		SDL_UpdateWindowSurface(window);
		SDL_Delay(0);
		lastTime = time;

		//OnRenderer();
	}

	OnCleanup();

	return 0;
}

void SDLGraphics::OnCleanup() {
	SDL_FreeSurface(surfO);
	SDL_FreeSurface(surfX);
	SDL_FreeSurface(surfGrid);
	SDL_FreeSurface(screenSurface);

	SDL_DestroyWindow(window);
	SDL_Quit();
}

void SDLGraphics::OnInit() {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Tic Tac Toe", 600, 200, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, 0, 0);
	screenSurface = SDL_GetWindowSurface(window);
	assert(window || renderer || screenSurface);


	surfGrid = SDL_LoadBMP("Images/hello_world.bmp");
	SDL_BlitSurface(surfGrid, NULL, screenSurface, NULL);
	assert(surfGrid && SDL_GetError());

	surfO = SDL_LoadBMP("./Images/o.bmp");
	assert(surfO && SDL_GetError());


	surfX = SDL_LoadBMP("./Images/x.bmp");
	assert(surfX && SDL_GetError());

	Transparent(surfO, 255, 0, 255);
	Transparent(surfX, 255, 0, 255);
	Reset();
}

void SDLGraphics::DrawPlayer() {

	for (int i = 0; i < 9; i++) {
		int x = (i % 3) * 200;
		int o = (i / 3) * 200;

		if (grid[i] == GRID_TYPE_NONE) {
			fillRect(x, o, rect->w, rect->h, RGB_COLOR(255, 255, 0));
		}
		else if (grid[i] == GRID_TYPE_O) {
			fillRect(x, o, rect->w, rect->h, RGB_COLOR(255, 255, 0));
		}
	}

	//SDL_Rect fillRect = { SCREEN_HEIGHT, SCREEN_WIDTH };
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//SDL_RenderFillRect(renderer, &fillRect);
}

void SDLGraphics::fillRect(int x, int y, int w, int h, int color) {
	SDL_Rect r = {x, y, w, h };
	SDL_FillRect(screenSurface, &r, color);
}

bool SDLGraphics::Transparent(SDL_Surface *surfDest, int r, int g, int b) {
	if (surfDest == NULL) {
		return false;
	}
	
	SDL_SetColorKey(surfDest, SDL_TRUE | SDL_RLEACCEL, SDL_MapRGB(surfDest->format, r, g, b));
	return true;
}

void SDLGraphics::Reset() {
	for (int i = 0; i < 9; i++) {
		grid[i] = GRID_TYPE_NONE;
	}
}

void SDLGraphics::LButtonClick() {
	int ID = event.button.x / 200;
	ID = ID + ((event.button.y / 200) * 3);

	if (grid[ID] == GRID_TYPE_X) {
		return;
	}

	if (currentPlayer == 0) {
		SetState(GRID_TYPE_X);
		currentPlayer = 1;
	}
	else {
		SetState(GRID_TYPE_O);
		currentPlayer = 0;
	}
}

Type SDLGraphics::SetState(Type state) {
	return currentState = state;
}

Type SDLGraphics::GetCurrentTypeState() const {
	return currentState;
}

void SDLGraphics::Draw() {
	InitializeSDL();
}

void SDLGraphics::HandleInput() {

}

//void SDLGraphics::InitializeSDL() {



	////Start up SDL and create window
	//if (!Init())
	//{
	//	printf("Failed to initialize!\n");
	//}
	//else
	//{
	//	//Load media
	//	if (!LoadMedia())
	//	{
	//		printf("Failed to load media!\n");
	//	}
	//	else
	//	{
	//		//Main loop flag
	//		bool quit = false;

	//		//Event handler
	//		SDL_Event e;

	//		//While application is running
	//		while (!quit)
	//		{
	//			//Handle events on queue
	//			while (SDL_PollEvent(&e) != 0)
	//			{
	//				//User requests quit
	//				if (e.type == SDL_QUIT)
	//				{
	//					quit = true;
	//				}
	//			}

	//			DrawStructure();

	//			//Update screen
	//			SDL_RenderPresent(renderer);
	//		}
	//	}
	//}

	////Free resources and close SDL
	//Close();
	//
//}

//void SDLGraphics::DrawStructure() {



	////Clear screen
	//SDL_SetRenderDrawColor(renderer, 0x50, 0x50, 0x50, 0xFF);
	//SDL_RenderClear(renderer);

	//SDL_Rect fillRect = { SCREEN_HEIGHT, SCREEN_WIDTH };
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//SDL_RenderFillRect(renderer, &fillRect);

	//////Render red filled quad
	////SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	////SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	////SDL_RenderFillRect(renderer, &fillRect);

	////Render yellow outlined quad
	//SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	//SDL_RenderDrawRect(renderer, &outlineRect);

	//////Draw horizontal line
	////SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	////SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

	////Draw vertical line of yellow dots
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	//for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	//{
	//	SDL_RenderDrawPoint(renderer, SCREEN_WIDTH * 2 / 3, i);
	//}

	////Draw vertical line of yellow dots
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	//for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	//{
	//	SDL_RenderDrawPoint(renderer, SCREEN_WIDTH * 2 / 4, i);
	//}

	////Draw vertical line of yellow dots
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	//for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	//{
	//	SDL_RenderDrawPoint(renderer, SCREEN_WIDTH * 2 / 6, i);
	//}

	////Draw horizontal lines of yellow dots
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	//for (int i = 0; i < SCREEN_WIDTH; i += 4)
	//{
	//	SDL_RenderDrawPoint(renderer, SCREEN_HEIGHT / 4 , i);
	//}

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
//}

//bool SDLGraphics::Init() {
	////Initialization flag
	//bool success = true;

	////Initialize SDL
	//if (SDL_Init(SDL_INIT_VIDEO) < 0)
	//{
	//	printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
	//	success = false;
	//}
	//else
	//{
	//	//Set texture filtering to linear
	//	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	//	{
	//		printf("Warning: Linear texture filtering not enabled!");
	//	}

	//	//Create window
	//	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	//	if (window == NULL)
	//	{
	//		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
	//		success = false;
	//	}
	//	else
	//	{
	//		//Create renderer for window
	//		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//		if (renderer == NULL)
	//		{
	//			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	//			success = false;
	//		}
	//		else
	//		{
	//			//Initialize renderer color
	//			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//			//Initialize PNG loading
	//			int imgFlags = IMG_INIT_PNG;
	//			if (!(IMG_Init(imgFlags) & imgFlags))
	//			{
	//				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	//				success = false;
	//			}
	//		}
	//	}
	//}

	//return success;
//}

//bool SDLGraphics::LoadMedia() {
//
//	//Loading success flag
//	bool success = true;
//
//	//Nothing to load
//	return success;
//
//	////Loading success flag
//	//bool success = true;
//
//	////Load splash image
//	//image = SDL_LoadBMP("hello_world.bmp");
//	//if (image == NULL)
//	//{
//	//	printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
//	//	success = false;
//	//}
//
//	//return success;
//	}

//void SDLGraphics::Close() {
	////Destroy window	
	//SDL_DestroyRenderer(renderer);
	//SDL_DestroyWindow(window);
	//window = NULL;
	//renderer = NULL;

	////Quit SDL subsystems
	//IMG_Quit();
	//SDL_Quit();
//}

//SDL_Texture* loadTexture(std::string path) {
	////The final texture
	//SDL_Texture* newTexture = NULL;

	////Load image at specified path
	//SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	//if (loadedSurface == NULL)
	//{
	//	printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	//}
	//else
	//{
	//	//Create texture from surface pixels
	//	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	//	if (newTexture == NULL)
	//	{
	//		printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	//	}

	//	//Get rid of old loaded surface
	//	SDL_FreeSurface(loadedSurface);
	//}

	//return newTexture;
//}



