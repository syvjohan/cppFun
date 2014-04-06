#ifndef PLAYER_H
#define PLAYER_H

#include "Utility.h"
#include "IGameObject.h"
#include "IEventListener.h"

class Player : public IGameObject, public IEventListener
{
public:
	Player();
	~Player();

	// IGameObject
	GameObjectType Type() const { return GO_PLAYER; }
	void Update();
	void Render(IRenderer *renderer);
	Rect HitBox() const { return _box; }
	void SetBox(const Rect &r) { _box = r; }

	// IEventListener
	const char *GetName() const { return "Player"; }
	bool HandleEvent(const EventPTR &evt);

private:
	Point _direction;
	Rect _box;
};

#endif // !PLAYER_h