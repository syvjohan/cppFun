#pragma once

//#include <string.h>
#include <cassert>
#define NULL 0

class XString;

bool operator==(const XString& lhs, const XString& rhs);

class XString
{
public:
	XString();
	XString(const XString& rhs); //Copy constructor.
	XString(const char* cstr);
	explicit XString(char c);
	~XString();
	
	//Operatos
	XString& operator=(const XString& rhs);
	XString& operator=(const char* cstr);
	XString& operator=(char ch);

	XString& operator+=(const XString& rhs);
	XString& operator+=(char* cstr);

	XString operator+(const XString& rhs);
	XString operator+(const char* cstr);

	//operator<<();

	char& operator[](int i);

	friend bool operator==(const XString &, const XString &);

	friend bool operator!=(const XString& lhs, const XString& rhs) {
		return !(lhs == rhs);
	}

	//End operators

	char& At(int i);
	const char* Data() const;
	int Length() const;
	void Reserve(const int numb);
	int Capacity() const;
	void ShrinkToFit();
	void PushBack(const char c);
	void Resize(int n);
	void Concat(const XString &);

private:
	size_t StrLength(const char *cstr) const;
	static bool StrCmp(char *str1, char *str2);
	char* AddTerminator();

	char *string;
	int stringLength;
	int capacity;
};

inline bool operator==(const XString& lhs, const XString& rhs) {
	return XString::StrCmp(lhs.string, rhs.string);
}