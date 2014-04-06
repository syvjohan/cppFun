#include "Wall.h"
#include "IRenderer.h"

Wall::Wall(const Rect &box)
{
	_box = box;
}

void Wall::Update()
{

}

void Wall::Render(IRenderer *renderer)
{
	renderer->DrawRectangle(_box, Color(1.0f, 0, 0, 1));
}
