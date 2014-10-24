#pragma once

#include <string.h>

class XString
{
public:
	XString();
	XString(const XString& rhs); //Copy constructor.
	XString(const char* cstr);
	~XString();
	
	//Operatos
	XString& operator=(const XString& rhs);
	XString& operator=(const char* cstr);
	XString& operator=(char ch);

	XString& operator+=(const XString& rhs);
	XString& operator+=(char* cstr);

	XString& operator+(const XString& lhs);
	XString& operator+(char* cstr);

	//operator<<();

	char& operator[](int i);

	friend bool operator==(const XString& lhs, const XString& rhs) {
		return strcmp(lhs.string, rhs.string) == 0;
	}

	//End operators

	char& At(int i);
	const char* Data() const;
	int Lenght() const;
	void Reserve(const int numb);
	int Capacity() const;
	void ShrinkToFit();
	void PushBack(const char c);
	void Resize(int n);

private:
	int ExpandStrSize(int lenght);
	size_t GetLenght(const char *cstr) const;
	char* Add_0();

	char *string;
};
