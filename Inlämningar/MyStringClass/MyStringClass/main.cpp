#include <stdlib.h>
#include <stdio.h>
#include "XString.h"

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif

int main() {

	char arr[30];

	String string;
	int s = string.StringSize(arr);
	//printf("%i", s);


	system("pause");
	return 0;
}











//_CrtDumpMemoryLeaks();