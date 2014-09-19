#ifndef GAMEINFO_H
#define GAMEINFO_H

class GameInfo {

public:
	GameInfo();
	~GameInfo();

	int NumbOfGames();
	int Wins();
	int Loses();
	int NumbOfMoves();
	int CheckNumbOfMoves();

	int numbOfMoves;

private:
	int numbOfGames;
	int wins;
	int loses;
	
};

// Gameboard:
//		Håller koll på spelbrädet, låter dig placera ut markörer.
//		Låter dig resetta spelet mm.


// GameboardView:
//		Tar in ett spelbräde som parameter till draw() och ritar ut det.
//		Skall designas så att du kan byta ut denna klassen mot implementation i SDL.



#endif //!GAMEINFO