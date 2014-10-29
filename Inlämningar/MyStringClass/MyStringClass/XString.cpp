#include "XString.h"
#include "Defs.h"
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <algorithm>

XString::XString()
{
	string = NULL;
	capacity = 0;
	stringLength = 0;
	Concat("");
}

//Copy constructor.
XString::XString(const XString& rhs) {

	string = NULL;
	capacity = 0;
	stringLength = 0;
	Concat(rhs);
}

XString::XString(const char *cstr) {
	stringLength = StrLength(cstr);
	capacity = stringLength + 1;
	string = DBG_NEW char[capacity];
	// Will include '\0' since cstr must be null-terminated, or StrLen would already have crashed.
	memcpy(string, cstr, stringLength + 1); 
}

XString::XString(char c) : XString() {
	Reserve(2);
	string[0] = c;
	string[1] = '\0';
}

XString::~XString() {
	if (string != NULL) {
		delete[] string;
	}
}

//Operators
XString& XString::operator=(const XString& rhs) {

	// CRUEL UNIT TESTS, I DO NOT APPROVE
	if (rhs.string == string)
		return *this;

	delete[] string;
	string = NULL;
	stringLength = 0;
	capacity = 0;
	Concat(rhs);

	return *this;
}

XString& XString::operator=(const char* cstr) {
	return (*this = XString(cstr));
}

//Insert 1 character.
XString& XString::operator=(char ch) {
	if (capacity <= 2) {
		Reserve(2);
	}

	// ???
	string[0] = ch;
	string[1] = '\0'; 

	return *this;
}

XString& XString::operator+=(const XString& rhs) {
	Concat(rhs);
	return *this;
}

XString& XString::operator+=(char* cstr) {
	Concat(cstr);
	return *this;
}

char& XString::operator[](int i) {
	return string[i];
}

XString XString::operator+(const XString& rhs) {
	XString s = *this;
	s.Concat(rhs);
	return s;
}

XString XString::operator+(const char* cstr) {
	XString s = *this;
	s.Concat(cstr);
	return s;
}

//End operators

char& XString::At(int i) {
	return string[i];
}

const char* XString::Data() const {
	return string;
}

//The Length excludes the '\0'.
int XString::Length() const {
	return stringLength;
}

void XString::Reserve(const int numb) {
	if (numb < capacity || numb == capacity) {
		return;
	}

	capacity = numb;
	char *temp = DBG_NEW char[capacity];
	memcpy(temp, string, capacity);

	delete[] string;
	string = temp;
}

//Returns the stringLength of the array.
int XString::Capacity() const {
	return capacity;
}

void XString::ShrinkToFit() {
	capacity = capacity - (stringLength + 1);
	char *temp = DBG_NEW char[capacity];
	memcpy(temp, string, capacity);

	delete[] string;
	string = temp;
}

void XString::PushBack(const char c) {
	Concat(XString(c));
}

void XString::Resize(int n) {
	if (n < Capacity()) {
		for (int i = n; i != '\0'; i++) {
			string[i] = '\0';
		}
	}
	//If n is bigger or equal to Capacity expand the char array.
	else {
		Reserve(n);
	}
}

//Help functions

inline size_t XString::StrLength(const char *cstr) const {
	size_t Length = 0;
	while (*cstr != '\0') {
		cstr++;
		Length++;
	}

	return Length;
}

// One method to rule them all.
void XString::Concat(const XString &r) {
	int newLen = stringLength + r.stringLength;

	if (string == NULL) {
		assert(stringLength == 0 && capacity == 0);
		capacity = newLen + 1;
		string = DBG_NEW char[capacity];
	} else if (newLen + 1 >= capacity) {
		int newCapacity = std::max(newLen + 1, capacity * 2);

		char* tmp = string;
		string = DBG_NEW char[newCapacity];
		memcpy(string, tmp, stringLength);
	}

	memcpy(string + stringLength, r.string, r.stringLength);
	stringLength = newLen;
	string[stringLength] = '\0';
}

bool XString::StrCmp(char *str1, char *str2) {
	do
	{
		if (*str1 != *str2)
			return false;

	} while (*str1++ != '\0' && *str2++ != '\0');

	return true;
}

//Adding '\0' at end of string.
char* XString::AddTerminator() {
	string[stringLength] = '\0';

	return string;
}

//End help functions

//In C++ 'a' is an char, 1 byte. Char a is 1 byte.
//In C 'a' is an int, 4 bytes. Char a is 1 byte