#include <stdlib.h>
#include <stdio.h>
#include "XString.h"
#include "Defs.h"

int main() {

	const int size = 9;
	char arr[size] = {'t','\0'};
	char arr2[size] = { 'r', '\0' };


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

	system("pause");
	return 0;
}











//_CrtDumpMemoryLeaks();