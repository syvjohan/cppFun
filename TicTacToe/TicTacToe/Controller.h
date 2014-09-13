#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
	friend class Graphics;

public: 
	Controller();
	~Controller();

	void GetInput(int i);
	bool CheckIndex(int i);
	void InitializeGame();
	void Start();
	void StartGame();

private:
	

};

#endif //!ControlLer