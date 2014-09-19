#ifndef IGAMEVIEW_H
#define IGAMEVIEW_H

#include "PGameBoard.h"
class PGameBoard;

// Abstract interface for views.
class GameView {
public:
	virtual ~GameView() {}

	GameView(PGameBoard* board) {
		mGameBoard = board;
	}

	virtual void HandleInput() = 0;

	// Update visual representation.
	virtual void Update() = 0;

protected:
	PGameBoard* mGameBoard;
};

class ConsoleView : public GameView {
	// Implement console view here..

	void HandleInput() {
		int row, col, value;
		//std::cin >> row >> col >> value;
		mGameBoard->Update(row, col, value);

		int winner = mGameBoard->CheckForWinner();
		if (winner)  {
			//printf("Winner is: %i\n", winner);
			mGameBoard->Reset();
		}
	}

	void Update() {
		//printf(mGameBoard->boardMarks.c_str());
	}
};

class SDLView : public GameView {
	// Implement SDLView here.
	void Update() {
		//RenderWithSDL(mGameBoard->boardMarks);
	}
};

#endif // !IGAMEVIEW_H