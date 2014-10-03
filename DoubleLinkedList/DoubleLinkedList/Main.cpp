#include <iostream>
#include "List.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	List list; 
	list.PushBack(24);
	list.PushBack(25);
	list.PushBack(26);

	list.PushFront(14);
	list.PushFront(15);
	list.PushFront(16);

	list.PopFront();
	list.PopBack();
	
	list.PushBack(24);
	list.PushBack(25);
	list.PushFront(17);

	if (list.Check(35)) {
		printf("true");
	}
	else {
		printf("false");
	}

	list.PrintList();

	system("pause");
	return 0;
}