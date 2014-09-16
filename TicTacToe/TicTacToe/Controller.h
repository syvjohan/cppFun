#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Graphics.h"

class Controller : public Graphics {

public: 
	Controller();
	~Controller();

	void InitializeGame();
	void Start();
	void UpdateGraphics();
	bool Isdigit(int integer);
	void Mark();

private:
	

};

#endif //!ControlLer