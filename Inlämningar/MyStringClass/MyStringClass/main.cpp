#include <stdlib.h>
#include <stdio.h>
#include "XString.h"
#include "Defs.h"

int main() {

	const int size = 11;
	char arr[size] = {'h','e', 'j', ' ','p', 'a', ' ', 'd', 'i', 'g', '\0'};
	char arr2[size] = {};


	String string;
	//printf("%c\n", string.StringLastChar(arr));
	//printf("%i\n", string.StringSize(*arr));
	//printf("%c", string.StringFirstChar(arr));

	/*if (string.StringIsEmpty(*arr) == false) {
		printf("string is empty");
	}*/
	
	/*if (string.StringCompare(*arr, *arr2)) {
		printf("Comparison is true");
	}*/

	//string.StringCopy(arr, *arr2, 2, 8);
	//printf("%c", arr2);

	system("pause");
	return 0;
}











//_CrtDumpMemoryLeaks();