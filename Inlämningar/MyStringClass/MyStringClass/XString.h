#pragma once

class XString
{
public:
	XString();
	XString(const XString& rhs);
	XString(const char* cstr);
	~XString();
	
	//Operatos
	XString& operator=(const XString& rhs);
	XString& operator=(const char* cstr);
	XString& operator=(char ch);
	XString& operator+=(const XString& rhs);
	XString& operator+=(char* cstr);
	//operator+();
	//operator<<();
	char& operator[](int i);

	friend bool operator==(const XString& lhs, const XString& rhs);
	//End operators

	char& At(int i);
	const char* Data() const;
	int Lenght() const;
	void Reserve(int);
	int Capacity() const;
	//ShrinkToFit();
	void PushBack(char c);
	//Resize(int n);

private:
	char *string;
	char c;
};
