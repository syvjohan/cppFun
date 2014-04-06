#include "SDLRenderer.h"

SDLRenderer::SDLRenderer(SDL_Window *target)
{
	_target = target;
	_surface = SDL_GetWindowSurface(target);
}

SDLRenderer::~SDLRenderer()
{

}

void SDLRenderer::Clear(const Color &col)
{
	int w, h;
	SDL_GetWindowSize(_target, &w, &h);
	Rect r(0, 0, w, h);
	DrawRectangle(r, col);
}

void SDLRenderer::Present()
{
	SDL_UpdateWindowSurface(_target);
}

void SDLRenderer::DrawRectangle(const Rect &r, const Color &col)
{
	SDL_Rect rect = { r.min.x, r.min.y, r.max.x - r.min.x, r.max.y - r.min.y };
	SDL_FillRect(_surface, &rect, col.AsInt32());
}