#include <iostream>
#include "Graphics.h"
#include "GameBoard.h"
#include <string>

Graphics::Graphics() {

}

Graphics::~Graphics() {

}

GameBoard g;

// If board array change size interface will lock bad!!!!!
void Graphics::Board() const {
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t|");
	printf("\t%c", g.ReturnBoardMark(0));
	
	printf("\t|");
	printf("\t%c", g.ReturnBoardMark(1));
	printf("\t|");
	printf("\t%c", g.ReturnBoardMark(2));
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
	printf("\t%c", g.ReturnBoardMark(3));
	printf("\t|");
	printf("\t%c", g.ReturnBoardMark(4));
	printf("\t|");
	printf("\t%c", g.ReturnBoardMark(5));
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
	printf("\t%c", g.ReturnBoardMark(6));
	printf("\t|");
	printf("\t%c", g.ReturnBoardMark(7));
	printf("\t|");
	printf("\t%c", g.ReturnBoardMark(8));
	printf("\t|\n");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|");
	printf("\t\t|\n");
	printf("\t\t-------------------------------------------------\n");
}

void Graphics::Stats(int numbOfGames, int wins, int loses) {
	printf("\nNumber of games: %i\n", numbOfGames);
	printf("Wins: %i\n", wins);
	printf("Loses: %i\n\n\n\n", loses);
}

void Graphics::Menu() const{
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t\tPress 1 to start a new game\n"
		   "\t\t\tPress 2 to exit\n");
	printf("\t\t-------------------------------------------------\n");
}

void Graphics::MenuChooseMark(std::string playerName) const {
	printf("\n%s to put a mark in the gameboard press a number between 0 and 8: \n", playerName.c_str());
}

void Graphics::P1Name() const{
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t\tPlease write Player 1 name: ");
}

void Graphics::P2Name() const{
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t\tPlease write Player 2 name: ");
}

void Graphics::WinnerIs(std::string playerName) const {
	printf("\n\t\t-------------------------------------------------\n");
	printf("\t\tCongratulations you won %s ", playerName.c_str());
	printf("\n\n\n");
}

void Graphics::SubMenu() const {
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t\tPress 1 to play a new round\n"
		   "\t\t\tPress 2 to exit\n");
	printf("\t\t-------------------------------------------------\n");
}