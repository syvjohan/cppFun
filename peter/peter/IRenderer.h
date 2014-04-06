#ifndef RENDERER_H
#define RENDERER_H

#include "Utility.h"

class IRenderer
{
public:
	virtual ~IRenderer() { }

	virtual void Clear(const Color &col) = 0;
	virtual void Present() = 0;

	virtual void DrawRectangle(const Rect &rect, const Color &col) = 0;
};

#endif // RENDERER_H