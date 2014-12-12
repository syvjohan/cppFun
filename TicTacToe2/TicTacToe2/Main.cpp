#include "Defs.h"
#include "IGameView.h"
#include "GameManager.h"
#include "ConsoleView.h"
#include "SDLGraphics.h"

#define USE_SDL

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GameView* view = nullptr;

#ifdef USE_SDL
	view = new SDLGraphics();
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



