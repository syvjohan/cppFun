#pragma once

#include <iostream>
#include <cassert>

template<typename T>
class SharedPtr {

public:
	SharedPtr<T>();
	SharedPtr<T>(SharedPtr<T> &sharedPtr);
	SharedPtr<T>(T* ptr);
	~SharedPtr<T>();

	operator bool () const;
	bool operator== (const SharedPtr<T> *sharedPtr);
	bool operator< (const SharedPtr<T> *sharedPtr);
	T& operator* ();

	template<typename T>
	T* SharedPtr<T>::*operator-> () {
		return ptr;
	} 

	SharedPtr<T> Reset();
	T* Get();
	bool Unique();

private:
	T *ptr;
	int count = 0;
};


template<typename T>
SharedPtr<T>::SharedPtr() {
	ptr = new T;
	ptr* = nullptr;
	count++;
}

template<typename T>
SharedPtr<T>::SharedPtr<T>(SharedPtr<T> &sharedPtr) {

}

template<typename T>
SharedPtr<T>::SharedPtr<T>(T* ptr) {
	ptr = new T;
	count++;
}

template<typename T>
SharedPtr<T>::~SharedPtr() {
	delete ptr;
	count--;
}

//if sharedPtr is an object return it.
template<typename T>
SharedPtr<T>::operator bool() const {
	return T* != nullptr;
}

template<typename T>
bool SharedPtr<T>::operator== (const SharedPtr<T> *sharedPtr) {
	return *ptr == *sharedPtr->ptr;
}

template<typename T>
bool SharedPtr<T>::operator< (const SharedPtr<T> *sharedPtr) {
	return *ptr < *sharedPtr->ptr;
}

template<typename T>
T& SharedPtr<T>::operator* () {
	return *ptr;
}

template<typename T>
SharedPtr<T> SharedPtr<T>::Reset() {
	ptr* = nullptr;
	count--;
}

template<typename T>
T* SharedPtr<T>::Get() {
	return *ptr;
}

template<typename T>
bool SharedPtr<T>::Unique() {
	return count == 1;
}
