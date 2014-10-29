#pragma once

#include <string>

using namespace std;

class Iterator {
public:
	Iterator(const Iterator &it);
	~Iterator();

	bool operator==(const string &lhs, const string &rhs);
	bool operator!=(const string &lhs, const string &rhs);

	Iterator operator+(const Iterator &it);
	Iterator& operator++(); //Prefix
	Iterator operator++(Iterator); //Postfix
	char& operator[](int i);

	string& operator*();
	const string& operator*() const;

	void ForwardIterator(Iterator &begin, Iterator &end);
	void ReverseIterator(Iterator &rbegin, Iterator &rend);
	void ConstIterator(Iterator )

private:
	int *it;
};

//iterator,
//const_iterator,
//reverse_iteraor,
//const_reverse_iterator.