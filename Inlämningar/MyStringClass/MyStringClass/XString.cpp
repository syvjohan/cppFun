#include "XString.h"
#include "Defs.h"
#include <stdlib.h>
#include <stdio.h>

String::String() {
	nextIndex = 0;
	sizes = 10;
	str = DBG_NEW char[sizes]; //Create an object.
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
void String::StringClear(const int &arr) {

}

//Check if char[] is empty.
bool String::StringIsEmpty(const char &arr) const {
	if ((&arr)[0] == '\0' || (&arr)[0] == 0) {
		return true;
	}
	return false;
}

//Shrink the char[] size
void String::StringShrink(const int &shrink) {

}

//Returns a specific position in char[].
void String::StringPosition(const int &position) {

}

// append element to char[].
void String::StringPush(const char &push) {

}

//Erase last element in char[] (string).
void String::StringPop(const char &pop) {

}

//Compare the content of 2 different char[]
bool String::StringCompare(const char &str1, const char &str2) {
	if (str1 == str2) {
		return true;
	}
	return false;
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
