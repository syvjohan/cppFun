#ifndef XSTRING_H
#define XSTRING_H

class String {
public:
	String();
	~String();

	char *StringFirstChar() const; //Access first char in char[].
	char *StringLastChar() const; //Access last char in char[].
	size_t StringSize(const char *arr) const; //Returns the sizeof char[] (bytes).
	void StringLenght(const int &lenght); //Gets the number of elements in the char[].
	void StringClear(const int &clear); //Erase all the elements in the char[].
	bool StringIsEmpty(const char &isEmpty); //Check if char[] is empty.
	void StringShrink(const int &shrink); //Shrink the char[] size
	void StringPosition(const int &position); //Returns a specific position in char[].
	void StringPush(const char &push); // append element to char[].
	void StringPop(const char &pop); //Erase last element in char[] (string).
	void StringCompare(const char &str1, const char &str2); //Compare 2 different char[]
	void StringCopy(const char &copy); //Copy the hole char[].

private:
	char *str;
	int size;
	int nextIndex;
};

#endif //!XSTRING