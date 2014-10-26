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
		string = new char[capacity];
		memcpy(string + (lenSrc + 1), src, capacity);
		string[capacity] = '\0';
	}
	else {
		memcpy(string + (lenSrc + 1), src, capacity);
		string[capacity] = '\0';
	}

	return string;
}

inline int XString::ExpandStrstringLenght(int lenght) {

	int newstringLenght;
	return newstringLenght = ((lenght * 2) + stringLenght);
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
	memcpy(string, rhs.string, capacity);
	AddTerminator();
}

XString::XString(const char *cstr) {
	int len = StrLenght(cstr);
	stringLenght = len;
	capacity = len + 1;

	string = new char[capacity];
	memcpy(string, cstr, capacity);
	
	AddTerminator();
}

XString::~XString() {
	delete string;
}

//Operatos
XString& XString::operator=(const XString& rhs) {//Denna!
	delete[] string; //Erase information!

	stringLenght = rhs.stringLenght;

	if (capacity < stringLenght + 1) {
		capacity = stringLenght + 1;
		string = new char[capacity];
		memcpy(string, rhs.string, capacity);
	}
	else {
		memcpy(string, rhs.string, stringLenght);
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
		memcpy(string, cstr, capacity);
	}
	else {
		memcpy(string, cstr, capacity);
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
		stringLenght += rhs.stringLenght;
	}
	else {

		string = new char[capacity]
	}

	int len = StrLenght(rhs.string); //Get lenght of strlen
	rhs.string[len + 1] = '\0'; //add null terminal at end of cstr.
	
	return *this;
}

XString& XString::operator+=(char* cstr) {
	int len = StrLenght(cstr); //Get lenght of strlen
	cstr[len + 1] = '\0'; //add null terminal at end of cstr.
	strcat(string, cstr); //strcat, cstr overwrites the '\0' in string.
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
	int len = StrLenght(string);
	return len;
}

void XString::Reserve(const int numb) {
	if (string != nullptr) {
		if (numb < Capacity()) {
			return;
		}
		else {
			char *newstring = DBG_NEW char[ExpandStrstringLenght(numb)]; //Create a new string and increases the new strings stringLenght.
			memset(newstring, '\0', sizeof(newstring));
			memcpy(&newstring, &string, sizeof(string + 1)); //Copies to the beginning of the new char array.
			
			*string = *newstring;
			delete newstring;
		}
	}
}

//Returns the stringLenght of the array.
int XString::Capacity() const {
	return (sizeof(string) / sizeof(char));
}

void XString::ShrinkToFit() {
	int minstringLenght = capacity - (stringLenght + 1);
	char *newstring = DBG_NEW char[minstringLenght];
	memcpy(&newstring, &string, sizeof(newstring));

	*string = *newstring;
	delete newstring;
}

void XString::PushBack(const char c) {
	int i = StrLenght(string);
	string[i] = c;
	string[i + 1] = '\0';
}

void XString::RestringLenght(int n) {
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