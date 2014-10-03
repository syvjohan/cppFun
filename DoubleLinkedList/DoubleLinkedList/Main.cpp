#include <iostream>
#include "List.h"

int main() {

	List list; 
	list.PushBack(24);
	list.PushBack(25);
	list.PushFront(14);
	list.PushFront(15);
	list.PushFront(16);
	
	list.PushBack(24);
	list.PushBack(25);
	list.PushFront(17);

	list.PrintList();

	system("pause");
	return 0;
}