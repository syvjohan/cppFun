#ifndef SDLGRAPHICS_H
#define SDLGRAPHICS_H

#include "SDL.h" 
#include "SDL_image.h"
#undef main //SDLh includes SDL_main, replace main with the SDL_main.

#include "Defs.h"
#include "IGameView.h"

#include <iostream>
#include <string>
#include <cassert>

enum  Type {
	GRID_TYPE_NONE = 0,
	GRID_TYPE_O,
	GRID_TYPE_X
};

class SDLGraphics : public GameView {
public:
	SDLGraphics();
	~SDLGraphics();

	void InitializeSDL();
	int OnExecute();
	void OnInit();
	void OnCleanup();
	void DrawPlayer();
	void Reset();

	Type SetState(Type state);
	Type GetCurrentTypeState() const;

	void LButtonClick();
	void fillRect(int x, int y, int w, int h, int color);
	bool Transparent(SDL_Surface *surfDest, int r, int g, int b);

	void Draw();
	void HandleInput();
	/*void InitializeSDL();
	void HandleInput();
	void DrawStructure();
	bool Init();
	bool LoadMedia();
	void Close();*/

private:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	bool running;
	int grid[9];
	int currentPlayer;
	Type currentState;
	SDL_Window *window; //Rendering window.
	SDL_Renderer *renderer;
	SDL_Event event;

	SDL_Surface *screenSurface; //Surface contained by the window.
	SDL_Surface *surfGrid;
	SDL_Surface *surfX;
	SDL_Surface *surfO;

	struct Rectangle {
		int w;
		int h;
	}*rect;

	//SDL_Renderer *renderer = NULL; //The window renderer
};

#endif //!SDLGRAPHICS_H