#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include "XString.h"
#include "Defs.h"
#include "PeterString.h"

char *StrInsert(char *target, char *source, int index);

void PeterTest() {
	PString str = "Hej och ar fet";

	//str.Append("Peter").Append(" och ditt ar ").Append("Johan");

	PString p1 = str.SubString(0, 4);
	p1.Append("peter");
	PString p2 = str.SubString(3, str.Length() - 4);
	p1.Append(p2);



	str.Insert("peter ", 4);

	//PString sub = str.SubString(4, 4);



	printf("%s\n", str.CString());
}

int main() {
	PeterTest();

	//const int size = 33;
	//char arr[size] = {'h','e', 'j', ' ','p', 'a', ' ', 'd', 'i', 'g', '\0'};
	//char arr2[size] = {'j', 'o', 'h', 'a', 'n', '\0'};
	//char arr3[size] = {};

	//char *target = "Hej och Johan";
	//char *source = "Peter ";

	//StrInsert(target, source, 4);
	//String string;

	////printf("%c\n", string.StringLastChar(arr));
	////printf("%i\n", string.StringSize(*arr));
	////printf("%c", string.StringFirstChar(arr));

	//string.StringAppend("hej", 'g');

	/*if (string.StringIsEmpty(*arr) == false) {
		printf("string is empty");
	}*/
	
	/*if (string.StringCompare(*arr, *arr2)) {
		printf("Comparison is true");
	}*/

	//string.StringCopy(arr, *arr2, 2, 8);
	//printf("%c", arr2);

	//printf(string.StringPop(arr));

	//printf(string.StringAppend(arr, *arr2));
	//printf(string.StringInsertElement(arr, *arr2, 0, 6));
	
	//printf(string.StringClear(arr));

	//string.StringShrink(arr);


	system("pause");
	return 0;
}

//_CrtDumpMemoryLeaks();


char *StrInsert(char *target, char *source, int index) {

	size_t sourceLen = strlen(source);
	size_t targetLen = strlen(target);

	//target  H | E | J | | J | O | H | A | N |
	// Index =              4   
 	//source | P | E | T | E | R

	char *buffer = new char[sourceLen + targetLen];

	memcpy(buffer, target, index);
	memcpy(buffer + index, source, sourceLen);
	memcpy(buffer + index + sourceLen, target + index, targetLen - index + 1);


	return buffer;
}