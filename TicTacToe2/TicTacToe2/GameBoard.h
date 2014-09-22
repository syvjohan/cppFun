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
	bool UpdateBorder(int newValue);
	bool ValidateInput(const int value) const;
	bool ValidNumber(int input, int high, int low);
	int Returnboarder(const int col, const int row) const;
	int NumbOfMoves();
	bool ValidateMark(const int row, const int col);
	int Turn();
	bool IsRunning();
	
	void Reset();

	// Returns 0 for no winner, or the actual winner if there is one.
	int CheckForWinner() const;

	GameState SetState(GameState state);
	GameState CurrentState() const;

private:
	int size;
	int **boarder;
	int numbOfMoves;
	GameState currentState;

	int p1Score;
	int p2Score;
};

#endif //!GameBoard_H