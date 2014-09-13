#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "GameBoard.h"
#include "GameInfo.h"

class Graphics : GameBoard, GameInfo {

public:
	Graphics();
	~Graphics();

	void Stats();
	void Board();
	void Menu();
	void MenuChooseNumber();

private:

};


#endif //!GRAPHICS_H











