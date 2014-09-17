#include <iostream>
#include "Player.h"

GameInfo gameInfo;

Player::Player() {
	player1 = "Spelare 1";
	player2 = "spelare 2";
	int offset = 0;
}

Player::~Player() {
	
}

void Player::SetP1Name(std::string name) {
	player1 = name;
}

void Player::SetP2Name(std::string name) {
	player2 = name;
}

void Player::Player1(std::string name, int wins, int loses, int numOfMoves) {
	
	loses = gameInfo.Loses();
	wins = gameInfo.Wins();

	int totNumbOfGames = loses + wins;
}

void Player::Player2(std::string name, int wins, int loses, int numOfMoves) {
	loses = gameInfo.Loses();
	wins = gameInfo.Wins();

	int totNumbOfGames = loses + wins;
}

