#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include "IGameView.h"

class ConsoleView : public GameView {

public:
	ConsoleView();
	~ConsoleView();

	void HandleInput();
	void Update();
	void DrawMainMenu();
	void DrawSubMenu();
	void DrawGameBoard();

private:
};

#endif //!CONSOLEVIEW_H