#include "XString.h"
#include "Defs.h"

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
	return string; //Erase
}

int XString::Lenght() const {
	int count = 0;
	for (int i = 0; i != '\0'; i++) {
		count++;
	}

	return count;
}

void XString::Reserve(const int numb) {
	if (numb < Capacity()) {
		return;
	}
	else {
		char *temp = string;
		char *newstring = DBG_NEW XString[numb + 10]; //Create a new string and increases the new strings size.
		string = newstring;
		delete newstring;
	}
}

//Returns the number of allocated elements in array.
int XString::Capacity() const {
	return (sizeof(string) / sizeof(char));
}

//ShrinkToFit();

void XString::PushBack(const char c) {
	int i = Lenght();
	string[i] = c;
	string[i + 1] = '\0';
}

//Resize(int n);

//In C++ 'a' is an char, 1 byte in size.
//In C 'a' is an int, 4 bytes in size.