#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GameBoard.h"
#include <vector>
class GameView;

class GameManager {

public:
	GameManager();
	~GameManager();
	void Run();

	void AttachView(GameView* view);
private:
	GameBoard mModel;
	std::vector<GameView*> mViews;
};

#endif //!GAMEMANAGER_H