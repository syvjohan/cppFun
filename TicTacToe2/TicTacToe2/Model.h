#ifndef GameBoard_H
#define GameBoard_H

enum GameState {
	GS_MAINMENU = 0,
	GS_SUBMENU,
	GS_GAME,
	GS_QUIT
};

class GameBoard {
public:
	GameBoard();
	~GameBoard();

	void InitializeGame();
	void UpdateBorder(int row, int col, int newValue);
	bool ValidateValue(const int newValue, const int oldValue) const;
	int Returnboarder(const int col, const int row) const;
	int ReturnNumbOfMoves();
	
	//Call this function from main() in main.cpp
	void StartGame(); 
	void Reset();

	// Returns 0 for no winner, or the actual winner if there is one.
	int CheckForWinner() const;

	GameState SetState(GameState state);
	GameState CurrentState() const;

private:
	int size;
	int **boarder;
	int turn;
	GameState currentState;

	int numbOfMoves;
	int wins;
	int lost;
};

#endif //!GameBoard_H