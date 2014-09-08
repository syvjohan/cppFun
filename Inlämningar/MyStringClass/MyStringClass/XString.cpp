#include "XString.h"
#include "Defs.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

String::String() {
	nextIndex = 0;
	size = 11;
	str = DBG_NEW char[size]; //Create an object.
}

String::~String() {
	delete[] str;
}

//Access first char in char[].
char String::StringFirstChar(const char *arr) const {
	if (StringIsEmpty(*arr) == false) {
		return arr[0];
	}
}

//Access last char in char[].
char String::StringLastChar(const char *arr) const {
	if (StringIsEmpty(*arr) == false) {
		int count = 0;
		char lastChar;

		while (arr[count] != '\0') {
			count++;
		}

		return lastChar = arr[count - 1];
	}
}

//Returns the sizeof char[] in bytes. 
size_t String::StringSize(const char &arr) const {
	size_t count = 0;
	while ((&arr)[count] != '\0') {
		count++;
	}

	return count;
}

//Erase all the elements in the char[].
char *String::StringClear(char *arr) {
	if (StringIsEmpty(*arr) == false) {
		for (int i = 0; arr[i] != '\0'; i++) {
			arr[i] = '\0';
		}
		return arr;
	}
}

//Check if char[] is empty.
bool String::StringIsEmpty(const char &arr) const {
	if ((&arr)[0] == '\0' || (&arr)[0] == 0) {
		return true;
	}
	return false;
}

//Shrink the char[] size
void String::StringShrink(char *arr) {
	printf("\nWrong class use the Vector class instead!\n");
}

// append element in the end of char[].
char *String::StringAppend(char *arr, const char &addChar) {
	if (StringIsEmpty(addChar) == false) {

		int sumCount = 0;
		//count elements to be added!
		for (int i = 0; (&addChar)[i] != '\0'; i++) {
			sumCount++;
		}
	
		int newSize = (size + sumCount) * 2;
		char *temp = DBG_NEW char[newSize];

		//copy char[] into temp char[]
		while ((arr)[nextIndex] != '\0') {
			temp[nextIndex] = arr[nextIndex];
			nextIndex++;
		}

		//copy the chars to be added and place them after the exisiting chars.
		for (int i = 0; (&addChar)[i] != '\0'; i++, nextIndex++) {
			temp[nextIndex] = (&addChar)[i];
		}

		//Fill the rest of the slots with '\0'.
		for (nextIndex + 1; nextIndex != newSize; nextIndex++) {
			temp[nextIndex] = '\0';
		}

		arr = temp;
		size = newSize;
		return arr;
	}
}

//Append element to char[] at a specific position and number of elements.
char *String::StringInsertElement(char *arrInsertInto, const char &arrCopyFrom, int pos, int number) {
/*	if (StringIsEmpty(arrCopyFrom) == false) {

		int sumCount = 0;
		//count elements to be added!
		for (int i = 0; (&addChar)[i] != '\0'; i++) {
			sumCount++;
		}

		int newSize = (size + sumCount) * 2;
		char *temp = DBG_NEW char[newSize];

		//copy char[] into temp char[]
		while ((arr)[nextIndex] != '\0') {
			temp[nextIndex] = arr[nextIndex];
			nextIndex++;
		}

	
		//copy the number of chars to be added and place them at position x.
		for (int i = 0; i != '\0' || pos != '\0' || pos != number; i++, pos++) {

			
		}

		//Fill the rest of the slots with '\0'.
		for (nextIndex + 1; nextIndex != newSize; nextIndex++) {
			temp[nextIndex] = '\0';
		}

		arr = temp;
		size = newSize;
		return arr;
	}*/
	return 0;
}

//Erase last element in char[] (string).
char *String::StringPop(char *arr) {
	if (StringIsEmpty(*arr) == false) {
		int count = 0;
		char lastChar = '\0';

		while (arr[count] != '\0') {
			count++;
		}

		arr[count - 1] = lastChar;
		return arr;
	}
}

//Compare the content of 2 different char[]
bool String::StringCompare(const char *str1, const char *str2) {
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);

	if (len1 != len2)
		return false;

	for (int i = 0; i != len1; ++i) {
		if (*str1 != *str2) 
			return false;
	}
	

	return true;
}

//Copy the char[] into another char[]. Set start (pos) and number of chars to be copied.
void String::StringCopy(const char *arrCopyFrom, char &arrCopyTo, int pos, int number) {
	if (StringIsEmpty(*arrCopyFrom) == false) {
		do {
			(&arrCopyTo)[pos] = arrCopyFrom[pos];
			pos++;
		} while (arrCopyFrom[pos] != '\0' && pos != number);
	}
}
