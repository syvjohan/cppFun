#ifndef SDLGRAPHICS_H
#define SDLGRAPHICS_H

#include "SDL.h" 
#include "SDL_image.h"
#undef main //SDLh includes SDL_main so replace main with the SDL_main.

#include "Defs.h"
#include "IGameView.h"

#include <iostream>

class SDLGraphics : public GameView {
public:
	SDLGraphics();
	~SDLGraphics();

	void InitializeSDL();
	void HandleInput();
	void Draw();
	void DrawStructure();
	bool Init();
	bool LoadMedia();
	void Close();

private:
};

#endif //!SDLGRAPHICS_H