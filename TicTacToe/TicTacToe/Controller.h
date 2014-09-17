#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Graphics.h"
#include "Player.h"

class Controller : public Graphics, public Player {

public: 
	Controller();
	~Controller();

	void InitializeGame();
	void Start();
	void UpdateGraphics();
	bool Isdigit();
	bool ValidNumber(int input, int low, int high);
	void Mark();
	void PlayerSetup();

private:

};

#endif //!ControlLer