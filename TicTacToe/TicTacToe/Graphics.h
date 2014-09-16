#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "GameBoard.h"
#include "GameInfo.h"

class Graphics : public GameBoard, public GameInfo {

public:
	Graphics();
	~Graphics();

	void Stats();
	void Board();
	void Menu();
	void MenuChooseMark();

private:

};


#endif //!GRAPHICS_H











