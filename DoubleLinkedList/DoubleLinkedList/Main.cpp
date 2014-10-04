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
	
	list.PushBack(27);
	list.PushBack(28);
	list.PushFront(29);

	if (list.Check(25)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}

	printf("\nNumber of elements in the list are: %i", list.AmountOfNodes());
	list.PrintList();

	system("pause");
	return 0;
}