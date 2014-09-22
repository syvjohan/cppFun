
#include "IGameView.h"
#include "GameManager.h"
#include "ConsoleView.h"

//#define USE_SDL

int main() {

	GameView* view = nullptr;

#ifdef USE_SDL
	view = new SDLView();
#else
	view = new ConsoleView();
#endif 


	GameManager manager;
	manager.AttachView(view);
	manager.Run();

	delete view;

	return 0;
}

//#define main main(){printf("ERROR(main.cpp(1)): #PEBKAC(ID-10T)!\n"); system("pause");} int func
//printf("My Awesome program!");



