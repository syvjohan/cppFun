//AB5785 Johan Fredriksson
#include <iostream>
#include <cassert>
#include "List.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	List<int> list; 
	assert(list.Check(0));
	list.PushBack(3);
	assert(list.Check(1));
	list.PushBack(34);
	assert(list.Check(2));
	assert(list.GetFirstNode()->value == 3);
	assert(list.GetLastNode()->value == 34);
	list.PopBack();
	assert(list.GetLastNode()->value == 3);
	list.PopBack();
	list.PopBack();
	assert(list.Check(0));


	/*list.PushBack(24);
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

	if (list.AmountOfNodes(25)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}

	printf("\nNumber of elements in the list are: %i", list.AmountOfNodes());
	list.PrintList();*/

	return 0;
}