#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>

class Graphics {

public:
	Graphics();
	~Graphics();

	void Stats(int numbOfGames, int wins, int loses);
	void Board() const;
	void Menu() const;
	void MenuChooseMark(std::string playerName) const;
	void P1Name() const;
	void P2Name() const;
	void WinnerIs(std::string playerName) const;
	void SubMenu() const;

private:

};


#endif //!GRAPHICS_H











