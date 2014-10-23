#pragma once

#include "Defs.h"
#include <iostream>
#include <cassert>

template<typename T>
class SharedPtr {

public:
	SharedPtr<T>(void);
	SharedPtr<T>(SharedPtr<T> &sharedPtr);
	SharedPtr<T>(T* ptr);

	//Copy constructor.
	template<typename T2>
	SharedPtr<T>(SharedPtr<T2> r);

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
	struct SharedPtrData {
		T *ptr;
		int count;
	};

	SharedPtrData *data;

	//T *ptr;
	//int count = 0;
};

template<typename T>
SharedPtr<T>::SharedPtr(void) {
	data = NULL;

	//ptr = DBG_NEW T[sizeof(SharedPtr<T>)];
	//assert(ptr == nullptr && "ERROR, allocation of memory for ptr failed!");
	//count++;
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &sharedPtr) {


	data = sharedPtr.data;
	data->count += 1;

	++sharedPtr.count;

	count = sharedPtr.count;

}

template<typename T>
SharedPtr<T>::SharedPtr(T* ptr) {

	data = new SharedPtrData;
	data->ptr = ptr;
	data->count = 1;


	ptr = new T;
	count++;
}

//Copy constructor.
template<typename T>
template<typename T2>
SharedPtr<T>::SharedPtr(SharedPtr<T2> r) {
	ptr = new T;
	*this->ptr = *r.ptr; //Copy the value.
}

template<typename T>
SharedPtr<T>::~SharedPtr() {
	delete ptr;
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
