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
XString& XString::operator=(const XString& rhs) {

}

XString& XString::operator=(const char* cstr) {

}

XString& XString::operator=(char ch) {

}

XString& XString::operator+=(const XString& rhs) {

}

XString& XString::operator+=(char* cstr) {

}

//operator+();
//operator<<();

char& XString::operator[](int i) {

}

bool operator==(const XString& lhs, const XString& rhs) {

}

char& XString::At(int i) {

}

const char* XString::Data() const {

}

int XString::Lenght() const {

}

void XString::Reserve(int) {

}

int XString::Capacity() const {

}

//ShrinkToFit();

void XString::PushBack(char c) {

}

//Resize(int n);