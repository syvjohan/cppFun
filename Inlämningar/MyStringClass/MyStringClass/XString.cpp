#include "XString.h"
#include "Defs.h"
#include <stdio.h>
#include <string.h>

XString::XString() {
	
}

XString::XString(const XString& rhs) {

}

XString::XString(const char* cstr) {
	
}

XString::~XString() {

}

//Operatos
inline XString& XString::operator=(const XString& rhs) {

}

inline XString& XString::operator=(const char* cstr) {

}

inline XString& XString::operator=(char ch) {

}

inline XString& XString::operator+=(const XString& rhs) {

}

inline XString& XString::operator+=(char* cstr) {

}

//operator+();
//operator<<();

inline char& XString::operator[](int i) {

}

inline bool operator==(const XString& lhs, const XString& rhs) {
	
}

char& XString::At(int i) {
	return string[i];
}

const char* XString::Data() const {
	return string;
}

//The Lenght excludes the '\0'.
int XString::Lenght() const {
	int count = 0;
	for (int i = 0; i != '\0'; i++) {
		count++;
	}

	return count;
}

void XString::Reserve(const int numb) {
	if (string != nullptr) {
		if (numb < Capacity()) {
			return;
		}
		else {
			int newSize = ((numb * 2) + 10);
			char *newstring = DBG_NEW char[newSize]; //Create a new string and increases the new strings size.
			newstring = { 0 };
			memcpy(&newstring, &string, sizeof(string)); //Copies to the beginning of the new char array.
			
			*string = *newstring;
			delete newstring;
		}
	}
	return;
}

//Returns the size of the array.
int XString::Capacity() const {
	return (sizeof(string) / sizeof(char));
}

void XString::ShrinkToFit() {
	int minSize = Capacity() - (Lenght() + 1);
	char *newstring = DBG_NEW char[minSize];
	memcpy(&newstring, &string, sizeof(newstring));

	*string = *newstring;
	delete newstring;
}

void XString::PushBack(const char c) {
	int i = Lenght();
	string[i] = c;
	string[i + 1] = '\0';
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

//In C++ 'a' is an char, 1 byte in size. Char a is 1 byte.
//In C 'a' is an int, 4 bytes in size. Char a is 1 byte