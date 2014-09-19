#include <iostream>
#include "Player.h"
#include <string>

Player::Player() {
	player1 = "Spelare 1";
	player2 = "spelare 2";
}

Player::~Player() {
	
}

void Player::SetP1Name(std::string name) {
	player1 = name;
}

void Player::SetP2Name(std::string name) {
	player2 = name;
}

std::string Player::GetP1Name() const {
	return player1;
}

std::string Player::GetP2Name() const {
	return player2;
}

