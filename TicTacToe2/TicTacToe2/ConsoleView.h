#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include "IGameView.h"

class ConsoleView : public GameView {

public:
	ConsoleView();
	~ConsoleView();

	void HandleInput();
	void GameMode();
	void DrawMainMenu();
	void DrawGameBoard();
	void DrawWinner();

	void Draw();

private:
};

#endif //!CONSOLEVIEW_H