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
//		H�ller koll p� spelbr�det, l�ter dig placera ut mark�rer.
//		L�ter dig resetta spelet mm.


// GameboardView:
//		Tar in ett spelbr�de som parameter till draw() och ritar ut det.
//		Skall designas s� att du kan byta ut denna klassen mot implementation i SDL.



#endif //!GAMEINFO