#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Utility.h"
#include <vector>
#include "EventManager.h"
#include "IEventListener.h"

class IRenderer;
class IGameObject;

class Game : public IEventListener
{
public:
	Game();
	~Game();

	void Update();
	void Render(IRenderer *renderer);

	const char *GetName() const { return "Game"; }
	bool HandleEvent(const EventPTR &evt);

private:
	void DoCollisions();

	Player *_player;
	std::vector<IGameObject*> _objects;
};

#endif // !GAME_H