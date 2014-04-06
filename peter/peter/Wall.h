#ifndef WALL_H
#define WALL_H

#include "Utility.h"
#include "IGameObject.h"

class Wall : public IGameObject
{
public:
	Wall(const Rect &box);


	GameObjectType Type() const { return GO_WALL; }
	void Update();
	void Render(IRenderer *renderer);
	Rect HitBox() const { return _box; }
	void SetBox(const Rect &r) { _box = r; }

private:
	Rect _box;
};


#endif // !WALL_H