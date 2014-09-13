#include <iostream>
#include "GameInfo.h"


GameInfo::GameInfo() {
	numOfGames = -1;
	wins = -1;
	loses = -1;
}

GameInfo::~GameInfo() {

}

int GameInfo::NumberOfGames() {
	return ++numOfGames;
}

int GameInfo::Wins() {
	return ++wins;
}

int GameInfo::Loses() {
	return ++loses;
}