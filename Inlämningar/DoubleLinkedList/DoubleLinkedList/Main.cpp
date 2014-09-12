#include <iostream>
#include "Defs.h"
#include "List.h"
#include "Node.h"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	List<int> list; //List of ints.
	
	list.PushFront(40);
	list.PushFront(30);
	list.PushFront(20);
	list.PushFront(10);
	list.PushBack(50);
	list.PushBack(60);
	list.PushBack(70);

	list.PopFront();
	list.PopBack();

	list.Front();
	list.Back();

	//list.ClearList();

	//list.PrintListForward();
	list.PrintListReverse();

	
	system("pause");
	return 0;
}