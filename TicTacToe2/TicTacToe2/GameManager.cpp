#include "GameManager.h"
#include "GameBoard.h"
#include "IGameView.h"
#include "ConsoleView.h"
#include <cstdio>
#include <iostream>

GameManager::GameManager() {}

GameManager::~GameManager() {}

void GameManager::AttachView(GameView* view) {
	view->SetModel(&mModel);
	mViews.push_back(view);
}

void GameManager::Run() {
	mModel.InitializeGame();

	while (mModel.IsRunning()) {
		for (GameView* view : mViews)  {
			view->Draw();
			view->HandleInput();
		}
	}
}
