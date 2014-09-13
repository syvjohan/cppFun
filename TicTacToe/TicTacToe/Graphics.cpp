#include <iostream>
#include "Graphics.h"

GameInfo gameInfo;
GameBoard gameBoard;

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
	printf("\t%i", gameBoard.CreateBoard(0));
	printf("\t|");
	printf("\t%i", gameBoard.CreateBoard(1));
	printf("\t|");
	printf("\t%i", gameBoard.CreateBoard(2));
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
	printf("\t%i", gameBoard.CreateBoard(3));
	printf("\t|");
	printf("\t%i", gameBoard.CreateBoard(4));
	printf("\t|");
	printf("\t%i", gameBoard.CreateBoard(5));
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
	printf("\t%i", gameBoard.CreateBoard(6));
	printf("\t|");
	printf("\t%i", gameBoard.CreateBoard(7));
	printf("\t|");
	printf("\t%i", gameBoard.CreateBoard(8));
	printf("\t|\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t-------------------------------------------------\n");

}

void Graphics::Stats() {
	printf("\nNumber of games: %i\n", gameInfo.NumberOfGames());
	printf("Wins: %i\n", gameInfo.Wins());
	printf("Loses: %i\n\n\n\n", gameInfo.Loses());
}

void Graphics::Menu() {
	printf("\t\t-------------------------------------------------\n");
	printf("Press 1 to start a new game\n"
		   "Press 2 to exit\n");
	printf("\t\t-------------------------------------------------\n");
}

void Graphics::MenuChooseNumber() {
	printf("\nTo put a mark in the gameboard press a number between 0 and 8: \n");
}
