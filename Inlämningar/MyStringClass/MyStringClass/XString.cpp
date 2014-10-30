#include "XString.h"
#include "Defs.h"
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <algorithm>
#include <stdexcept>

XString::XString() {
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
	// Will include '\0' since cstr must be null-terminated, or StrLength would already have crashed.
	memcpy(string, cstr, stringLength + 1); 
	string[stringLength] = '\0';
}

XString::~XString() {
	if (string != NULL) {
		delete[] string;
	}
	else std::cout << "what";
}

//Operators
XString& XString::operator=(const XString& rhs) {
	if (rhs.string == string) {
		return *this;
	}

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

XString& XString::operator=(char ch) {
	if (capacity <= 2) {
		Reserve(2);
	}

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
	if (i >= stringLength || i < 0) {
		throw std::out_of_range("Index of array(string) out of bound!");
	}
	return string[i];
}

const char& XString::At(int i) const {
	if (i >= stringLength || i < 0) {
		throw std::out_of_range("Index of array(string) out of bound!");
	}
	return string[i];
}

const char* XString::Data() const {
	return string;
}

//The Length excludes the '\0'.
int XString::Length() const {
	return stringLength;
}

void XString::Reserve(const int num) {
	if (num < capacity || num == capacity) {
		return;
	}
	
	capacity = num;
	char* temp = string;

	string = DBG_NEW char[capacity];
	memcpy(string, temp, capacity);
}

//Returns the stringLength of the array.
int XString::Capacity() const {
	return capacity;
}

void XString::ShrinkToFit() {
	if (capacity != stringLength) {
		capacity = stringLength;
		char *temp = string;
		string = DBG_NEW char[capacity + 1];
		string[capacity] = '\0';
		memcpy(string, temp, capacity);
		//delete[] string;
	}
}

void XString::Resize(int n) {
	if (n < capacity) {
		memset(string + n, '\0', capacity);
		stringLength = n;
	}
	//If n is bigger or equal to Capacity expand the char array.
	else {
		Reserve(n);
	}
}

inline size_t XString::StrLength(const char *cstr) const {
	size_t Length = 0;
	while (*cstr != '\0') {
		cstr++;
		Length++;
	}

	return Length;
}

void XString::PushBack(const char c) {
	Concat(&c);
}

// One method to rule them all.
void XString::Concat(const XString &r) {
	int newLen = stringLength + r.stringLength;

	if (string == NULL) {
		assert(stringLength == 0 && capacity == 0);

		capacity = newLen + 1;
		string = DBG_NEW char[capacity];
		memcpy(string, r.string, capacity);

		memcpy(string + stringLength, r.string, r.stringLength);
		stringLength = newLen;
		string[stringLength] = '\0';
	} else if (newLen + 1 >= capacity) {

		//Returns the largest of argument 1 and 2. If they are equivalent argument 1 is returned.
		int newCapacity = std::max(newLen + 1, capacity * 2);

		char *tmp = DBG_NEW char[newCapacity];
		memcpy(tmp, string, stringLength);

		memcpy(tmp + stringLength, r.string, r.stringLength);
		stringLength = stringLength + r.stringLength;
		tmp[stringLength] = '\0';
		delete[] string;
		string = tmp;
		capacity = newCapacity;

	}
	else
	{
		memcpy(string + stringLength, r.string, r.stringLength);
		stringLength = newLen;
		string[stringLength] = '\0';
	}
}

bool XString::StrCmp(char *str1, char *str2) {
	do
	{
		if (*str1 != *str2) {
			return false;
		}

	} while (*str1++ != '\0' && *str2++ != '\0');

	return true;
}

//In C++ 'a' is an char, 1 byte. Char a is 1 byte.
//In C 'a' is an int, 4 bytes. Char a is 1 byte