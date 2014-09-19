#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {

public: 
	Controller();
	~Controller();

	void InitializeGame();
	void StartMenu();
	void UpdateGraphics();
	bool Isdigit();
	bool ValidNumber(int input, int low, int high);
	void PutMark();
	void ChoosePlayerName();
	void DecidePlayerTurn(int choice);
	std::string GetNumbOfMoves();

private:

};
 
#endif //!ControlLer