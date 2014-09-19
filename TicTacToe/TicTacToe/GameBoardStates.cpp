#include "GameBoardStates.h"
#include <stdio.h>

//GameBoardStates::GameBoardStates() {}
//GameBoardStates::~GameBoardStates() {}
//
//int GameBoardStates::CheckStates() {
//	// När någon av funktionerna innehåller endast X
//	if ((StateOne() || StateTwo() || StateTree() ||
//		StateFour() || StateFive() || StateSix() ||
//		StateSeven() || StateEight()) == 1) {
//		return 1;
//	}
//	// När någon av funktionerna innehåller endast O
//	else if ((StateOne() || StateTwo() || StateTree() ||
//		StateFour() || StateFive() || StateSix() ||
//		StateSeven() || StateEight()) == 0) {
//		return 0;
//	}
//	//När ingen av funktionera innehåller endast X eller O
//	else {
//		return -2;
//	}
//}
//
//
//int GameBoardStates::StateOne() {
//	// De efterfrågade elementen är X
//	if ((GameBoard::ValidateMark(0) == 1) && (GameBoard::ValidateMark(1) == 1) && (GameBoard::ValidateMark(2) == 1)) {
//		return 1;
//		//De efterfrågade elementen är O
//	} else if ((GameBoard::ValidateMark(0) == 0) && (GameBoard::ValidateMark(1) == 0) && (GameBoard::ValidateMark(2) == 0)) {
//		return 0;
//	} else {
//		return -2;
//	}
//}
//
//bool GameBoardStates::StateTwo() {
//	if (isdigit(GameBoard::ValidateMark(3) && GameBoard::ValidateMark(4) && GameBoard::ValidateMark(5))) {
//		return true;
//	}
//	return false;
//}
//
//bool GameBoardStates::StateTree() {
//	if (isdigit(GameBoard::ValidateMark(6) && GameBoard::ValidateMark(7) && GameBoard::ValidateMark(8))) {
//		return true;
//	}
//	return false;
//}
//
//bool GameBoardStates::StateFour() {
//	if (isdigit(GameBoard::ValidateMark(0) && GameBoard::ValidateMark(3) && GameBoard::ValidateMark(6))) {
//		return true;
//	}
//	return false;
//}
//
//bool GameBoardStates::StateFive() {
//	if (isdigit(GameBoard::ValidateMark(1) && GameBoard::ValidateMark(4) && GameBoard::ValidateMark(7))) {
//		return true;
//	}
//	return false;
//}
//
//bool GameBoardStates::StateSix() {
//	if (isdigit(GameBoard::ValidateMark(2) && GameBoard::ValidateMark(5) && GameBoard::ValidateMark(8))) {
//		return true;
//	}
//	return false;
//}
//
//bool GameBoardStates::StateSeven() {
//	if (isdigit(GameBoard::ValidateMark(0) && GameBoard::ValidateMark(4) && GameBoard::ValidateMark(8))) {
//		return true;
//	}
//	return false;
//}
//
//bool GameBoardStates::StateEight() {
//	if (isdigit(GameBoard::ValidateMark(2) && GameBoard::ValidateMark(4) && GameBoard::ValidateMark(6))) {
//		return true;
//	}
//	return false;
//}