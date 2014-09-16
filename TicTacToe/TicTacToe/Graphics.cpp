#include <iostream>
#include "Graphics.h"

Graphics::Graphics() {

}

Graphics::~Graphics() {

}
// If board array change size interface will lock bad!!!!!
void Graphics::Board() {
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t|");
	printf("\t%c", GameBoard::ReturnBoardMark(0));
	
	printf("\t|");
	printf("\t%c", GameBoard::ReturnBoardMark(1));
	printf("\t|");
	printf("\t%c", GameBoard::ReturnBoardMark(2));
	printf("\t|\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");

	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t|");
	printf("\t%c", GameBoard::ReturnBoardMark(3));
	printf("\t|");
	printf("\t%c", GameBoard::ReturnBoardMark(4));
	printf("\t|");
	printf("\t%c", GameBoard::ReturnBoardMark(5));
	printf("\t|\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");

	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t|");
	printf("\t%c", GameBoard::ReturnBoardMark(6));
	printf("\t|");
	printf("\t%c", GameBoard::ReturnBoardMark(7));
	printf("\t|");
	printf("\t%c", GameBoard::ReturnBoardMark(8));
	printf("\t|\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t-------------------------------------------------\n");
}

void Graphics::Stats() {
	printf("\nNumber of games: %i\n", GameInfo::NumberOfGames());
	printf("Wins: %i\n", GameInfo::Wins());
	printf("Loses: %i\n\n\n\n", GameInfo::Loses());
}

void Graphics::Menu() {
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t\tPress 1 to start a new game\n"
		   "\t\t\tPress 2 to exit\n");
	printf("\t\t-------------------------------------------------\n");
}

void Graphics::MenuChooseMark() {
	printf("\nTo put a mark in the gameboard press a number between 0 and 8: \n");
}
