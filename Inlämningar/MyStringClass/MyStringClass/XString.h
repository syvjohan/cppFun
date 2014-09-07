#ifndef XSTRING_H
#define XSTRING_H

class String {
public:
	String();
	~String();

	char String::StringFirstChar(const char *arr) const; //Access first char in char[].
	char String::StringLastChar(const char *arr) const; //Access last char in char[].
	size_t String::StringSize(const char &arr) const; //Returns the sizeof char[] in bytes.
	void StringClear(const int &arr); //Erase all the elements in the char[].
	bool StringIsEmpty(const char &arr) const; //Check if char[] is empty.
	void StringShrink(const int &shrink); //Shrink the char[] size
	void StringPosition(const int &position); //Returns a specific position in char[].
	void StringPush(const char &push); // append element to char[].
	void StringPop(const char &pop); //Erase last element in char[] (string).
	bool StringCompare(const char &str1, const char &str2); //Compare 2 different char[]
	void StringCopy(const char &copy); //Copy the hole char[].

private:
	char *str;
	int sizes;
	int nextIndex;
};

#endif //!XSTRING