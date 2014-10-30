#pragma once

template<typename T>
class Iterator;

template<typename T>
bool operator==(const T &lhs, const T &rhs);

template<typename T>
bool operator!=(const T &lhs, const T &rhs);

using namespace std;

template<typename T>
class Iterator {
public:
	Iterator(char *str);
	~Iterator();

	//Operators
	friend bool operator==(const T &lhs, const T &rhs);
	friend bool operator!=(const T &lhs, const T &rhs);

	Iterator<T> operator+(const Iterator<T> &it);
	Iterator<T>& operator++(); //Prefix
	Iterator<T> operator++(int); //Postfix
	T& operator[](int i);
	T& operator*();
	const T& operator*() const;
	//End operators

	T* Begin();
	T* End();
	T* Prev();
	T* Next();

private:
	struct Container {
		T *container;
	}*con;
	
	struct IteratorData {
		Container *first;
		Container *last;
		Container *next;
		Container *prev;
	}*iterData;
};

//iterator,
//const_iterator,
//reverse_iteraor,
//const_reverse_iterator.


template<typename T>
Iterator<T>::Iterator(char *str) {
	con->container = str;

	con->container->next = nullptr;
	con->container->prev = nullptr;
	con->container->last = nullptr;
	con->container->first = nullptr;
	
}

template<typename T>
Iterator<T>::~Iterator() {

}

template<typename T>
Iterator<T> Iterator<T>::operator+(const Iterator<T> &it) {

}

//Prefix 
template<typename T>
Iterator<T>& Iterator<T>::operator++() {

}

//Postfix
template<typename T>
Iterator<T> Iterator<T>::operator++(int) {

}

template<typename T>
T& Iterator<T>::operator[](int i) {
	
}

template<typename T>
T& Iterator<T>::operator*() {

}

template<typename T>
const T& Iterator<T>::operator*() const {

}

template<typename T>
T* Iterator<T>::Begin() {
	con->container->first = con->container[0];
	return iterData->first;
}

template<typename T>
T* Iterator<T>::End() {
	int len = strlen(con->container);
	con->container->last = con->container[len];

	return iterData->last;
}

template<typename T>
T* Iterator<T>::Next() {
	return ++con->container->next;
}

template<typename T>
T* Iterator<T>::Prev() {
	return --con->container->prev;
}

//Global scope!
template<typename T>
inline bool operator==(const T &lhs, const T &rhs);

template<typename T>
inline bool operator!=(const T &lhs, const T &rhs);