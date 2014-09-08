#ifndef XSTRING_H
#define XSTRING_H

class String {
public:
	//Member functions
	String();
	~String();

	//Iterators

	//Capacity
	size_t String::StringSize(const char &arr) const; //Returns the sizeof char[] in bytes.
	char *StringClear(char *arr); //Erase all the elements in the char[].
	bool StringIsEmpty(const char &arr) const; //Check if char[] is empty.
	void StringShrink(char *arr); //Shrink the char[] size

	//Element access
	char String::StringFirstChar(const char *arr) const; //Access first char in char[].
	char String::StringLastChar(const char *arr) const; //Access last char in char[].

	//String operations
	bool StringCompare(const char *str1, const char *str2); //Compare 2 different char[]
	void StringCopy(const char *arrCopyFrom, char &arrCopyTo, int pos, int number); //Copy the hole char[].

	//Modifiers
	char *StringAppend(char *arr, const char &addChar); // append element to char[].
	char *StringInsertElement(char *arrInsertInto, const char &arrCopyFrom, int pos, int number); //Append element to char[] at a specific position and number of elements.
	char *StringPop(char *arr); //Erase last element in char[] (string).

	//Non-member functions overloads
	
private:
	char *str;
	int size;
	int nextIndex;
};

#endif //!XSTRING