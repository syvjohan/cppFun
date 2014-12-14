#include "Manager.h"
#include <crtdbg.h>


int main() {
	Manager manager;
	manager.Initializer();

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	system("pause");
	return 0;
}