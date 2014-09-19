#include <iostream>
#include "GameInfo.h"

GameInfo::GameInfo() {
	numbOfGames = -1;
	wins = -1;
	loses = -1;
	numbOfMoves = -1;
}

GameInfo::~GameInfo() {

}

int GameInfo::NumbOfGames() {
	return ++numbOfGames;
}

int GameInfo::Wins() {
	return ++wins;
}

int GameInfo::Loses() {
	return ++loses;
}

int GameInfo::NumbOfMoves() {
	return ++numbOfMoves;
}

//Calculate if variable numbOfMoves is odd or even.
int GameInfo::CheckNumbOfMoves() {
	if ((NumbOfMoves() % 2) == 0) {
		return 0;
	}
	return 1;
}
