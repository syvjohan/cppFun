#include "XString.h"
#include <stdlib.h>
//#include <stdio.h>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif

String::String() {
	size = 10;
	str = new char[size]; //Create an object.
}

String::~String() {

}

//Access first char in char[].
char *String::StringFirstChar() const {
	return &str[0]; //points to the first element.
}

//Access last char in char[].
char *String::StringLastChar() const {
	//number of elements.
	int s = sizeof(str) / sizeof(*str);
	//last element, -1 for '\0'.
	return &str[s - 1];
}

//Returns the sizeof char[] (bytes).
size_t String::StringSize(const char *arr) const {
	return sizeof(arr);
}