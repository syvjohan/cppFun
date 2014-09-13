#ifndef GAMEINFO_H
#define GAMEINFO_H

class GameInfo {

public:
	GameInfo();
	~GameInfo();

	int NumberOfGames();
	int Wins();
	int Loses();

private:
	int numOfGames;
	int wins;
	int loses;
};

#endif //!GAMEINFO