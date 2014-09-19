#ifndef IGAMEVIEW_H
#define IGAMEVIEW_H

class GameView {

public:
	GameView();
	virtual ~GameView();

	virtual void HandleInput() = 0;

	//Updates the visual.
	virtual void Update() = 0;

private:

};

#endif //!IGAMEVIEW_H