#include <iostream>
#include "List.h"

int main() {

	List list; 
	list.PushFront(14);
	list.PushFront(15);
	list.PushFront(16);
	list.PushBack(20);

	list.PrintList();


	system("pause");
	return 0;
}