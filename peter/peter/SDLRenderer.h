#ifndef SDLRENDERER_H
#define SDLRENDERER_H

#include "IRenderer.h"
#include <SDL.h>

class SDLRenderer : public IRenderer
{
public:
	SDLRenderer(SDL_Window *target);
	~SDLRenderer();

	// IRenderer
	void Clear(const Color &col);
	void Present();
	void DrawRectangle(const Rect &r, const Color &col);

private:
	SDL_Window *_target;
	SDL_Surface *_surface;
};

#endif // !SDLRENDERER_H