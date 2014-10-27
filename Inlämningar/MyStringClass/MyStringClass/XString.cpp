#include "XString.h"
#include "Defs.h"
#include <stdio.h>
#include <string.h>

//Help functions

inline size_t XString::StrLenght(const char *cstr) const {
	size_t lenght = 0;
	while (*cstr != '\0') {
		cstr++;
		lenght++;
	}

	return lenght;
}

char* XString::StrCat(char *dest, char *src) {

	int lenDest = StrLenght(dest);
	int lenSrc = StrLenght(src);
	int lenNew = lenDest + lenSrc + 1;

	if (lenNew > capacity) {
		capacity = lenNew;

		delete[] string;

		string = new char[capacity];
		memcpy(string, dest, sizeof(lenDest));
		memcpy(string + (lenDest + 1), src, sizeof(capacity));
		string[capacity] = '\0';
	}
	else {
		memcpy(string, dest, sizeof(lenDest));
		memcpy(string + (lenDest + 1), src, sizeof(capacity));
		string[capacity] = '\0';
	}

	return string;
}

//Adding '\0' at end of string.
char* XString::AddTerminator() {
	string[capacity] = '\0';

	return string;
}

//End help functions

XString::XString() {
	string = NULL;
	stringLenght = 1;
	capacity = stringLenght;
	string = new char[capacity];
	memset(string, '\0', sizeof(capacity));
}

//Copy constructor.
XString::XString(const XString& rhs) {
	capacity = rhs.capacity;
	stringLenght = rhs.stringLenght;

	string = new char[capacity];
	memcpy(string, rhs.string, sizeof(capacity));
	AddTerminator();
}

XString::XString(const char *cstr) {
	int len = StrLenght(cstr);
	stringLenght = len;
	capacity = len + 1;

	string = new char[capacity];
	memcpy(string, cstr, sizeof(capacity));

	AddTerminator();
}

XString::~XString() {
	delete string;
}

//Operatos
XString& XString::operator=(const XString& rhs) {
	delete[] string; //Erase information!

	stringLenght = rhs.stringLenght;

	if (capacity < stringLenght + 1) {
		capacity = stringLenght + 1;
		string = new char[capacity];
		memcpy(string, rhs.string, sizeof(capacity));
	}
	else {
		memcpy(string, rhs.string, sizeof(capacity));
	}

	AddTerminator();

	return *this;
}

XString& XString::operator=(const char* cstr) {
	delete[] string; //Erase information!

	int len = StrLenght(cstr);

	if (capacity < len + 1) {
		capacity = len + 1;
		string = new char[capacity];
		memcpy(string, cstr, sizeof(capacity));
	}
	else {
		memcpy(string, cstr, sizeof(capacity));
	}

	AddTerminator();

	return *this;
}

//Insert 1 character.
XString& XString::operator=(char ch) {
	delete[] string; //Erase information!

	if (capacity < stringLenght + 1) {
		stringLenght = stringLenght + ch;
		capacity = stringLenght + 1;

		string = new char[capacity];
		string[capacity - 1] = ch;
		AddTerminator();
	}

	string[capacity - 1] = ch;
	AddTerminator();

	return *this;
}

XString& XString::operator+=(const XString& rhs) {
	if ((stringLenght + rhs.stringLenght + 1) < capacity) {
		StrCat(string, rhs.string); //strcat, rhs overwrites the '\0' in string.
		stringLenght = stringLenght + rhs.stringLenght;
	}
	else {
		capacity = 2 * (stringLenght + rhs.stringLenght + 1);
		stringLenght = stringLenght + rhs.stringLenght;
		StrCat(string, rhs.string); //strcat, rhs overwrites the '\0' in string.
	}

	return *this;
}

XString& XString::operator+=(char* cstr) {
	int len = StrLenght(cstr);

	if ((stringLenght + len + 1) < capacity) {
		StrCat(string, cstr); //strcat, rhs overwrites the '\0' in string.
		stringLenght = stringLenght + len;
	}
	else {
		capacity = 2 * (stringLenght + len + 1);
		stringLenght = stringLenght + len;
		StrCat(string, cstr); //strcat, rhs overwrites the '\0' in string.
	}

	return *this;
}

char& XString::operator[](int i) {
	return string[i];
}

XString& XString::operator+(const XString& lhs) {
	*lhs.string += *string;
	return *this;
}

XString& XString::operator+(char* cstr) {
	cstr += *string;
	return *this;
}

//End operators

char& XString::At(int i) {
	return string[i];
}

const char* XString::Data() const {
	return string;
}

//The Lenght excludes the '\0'.
int XString::Lenght() const {
	return stringLenght;
}

void XString::Reserve(const int numb) {
	if (numb < capacity || numb == capacity) {
		return;
	}
	else {
		capacity = numb * 2;
		char *temp = DBG_NEW char[capacity];
		memset(temp, '\0', sizeof(temp));
		memcpy(temp, string, sizeof(capacity));

		delete[] string;
		string = temp;
	}
}

//Returns the stringLenght of the array.
int XString::Capacity() const {
	return capacity;
}

void XString::ShrinkToFit() {
	capacity = capacity - (stringLenght + 1);
	char *temp = DBG_NEW char[capacity];
	memcpy(temp, string, sizeof(capacity));

	delete[] string;
	string = temp;
}

void XString::PushBack(const char c) {
	int i = StrLenght(string);
	
	if ((stringLenght + 2) < capacity) {
		string[i] = c;
		string[i + 1] = '\0';
	}
	else {
		Reserve(i);
	}
	
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

//In C++ 'a' is an char, 1 byte. Char a is 1 byte.
//In C 'a' is an int, 4 bytes. Char a is 1 byte