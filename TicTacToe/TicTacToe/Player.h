#ifndef PLAYER_H
#define PLAYER_H

class Player {

public:
	Player();
	~Player();

	void SetP1Name(std::string name);
	void SetP2Name(std::string name);
	std::string GetP1Name() const;
	std::string GetP2Name() const;

private:
	std::string player1;
	std::string player2;
	
	
};

#endif //!PLAYER_H
