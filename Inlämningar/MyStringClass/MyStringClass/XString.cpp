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

inline int XString::ExpandStrSize(int lenght) {

	int newSize;
	return newSize = ((lenght * 2) + size);
}

//Adding '\0' at end of string.
char* XString::AddTerminator() {
	string[capacity] = '\0';

	return string;
}

//End help functions

XString::XString() {
	string = NULL;
	
	string = new char[capacity];
	memset(string, '\0', sizeof(string));
}

//Copy constructor.
XString::XString(const XString& rhs) {
	capacity = rhs.capacity;
	size = rhs.size;
	
	string = new char[capacity];
	memcpy(string, rhs.string, rhs.size );
	AddTerminator();
}

XString::XString(const char *cstr) {
	/*string = new char[capacity];

	m*/emcpy(string, cstr, len + 1);
	AddTerminator();
}

XString::~XString() {
	delete string;
}

//Operatos
XString& XString::operator=(const XString& rhs) {//Denna!
	delete[] string; //Erase information!

	int len = StrLenght(rhs.string);
	string = new char[ExpandStrSize(len)];
	memcpy(string, rhs.string, len + 1);
	AddTerminator();

	return *this;
}

XString& XString::operator=(const char* cstr) {
	delete string; //Erase information!

	int len = StrLenght(cstr);
	string = new char[ExpandStrSize(len)];
	memcpy(string, cstr, len + 1);
	AddTerminator();

	return *this;
}

//Insert 1 character.
XString& XString::operator=(char ch) {
	delete string; //Erase information!

	string = new char[ExpandStrSize(1)];
	string[0] = ch;
	string[1] = '\0';

	return *this;
}

XString& XString::operator+=(const XString& rhs) {
	int len = StrLenght(rhs.string); //Get lenght of strlen
	rhs.string[len + 1] = '\0'; //add null terminal at end of cstr.
	strcat(string, rhs.string); //strcat, rhs overwrites the '\0' in string.
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
			char *newstring = DBG_NEW char[ExpandStrSize(numb)]; //Create a new string and increases the new strings size.
			memset(newstring, '\0', sizeof(newstring));
			memcpy(&newstring, &string, sizeof(string + 1)); //Copies to the beginning of the new char array.
			
			*string = *newstring;
			delete newstring;
		}
	}
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
	int i = StrLenght(string);
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