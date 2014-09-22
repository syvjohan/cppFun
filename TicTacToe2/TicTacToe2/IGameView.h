#ifndef IGAMEVIEW_H
#define IGAMEVIEW_H

class GameBoard;

class GameView {

public:
	GameView() { model = nullptr; }
	
	void SetModel(GameBoard* board)
	{
		model = board;
	}

	virtual ~GameView() {};

	virtual void HandleInput() = 0;
	virtual void Draw() = 0;

protected:
	GameBoard* model;

private:

};

#endif //!IGAMEVIEW_H