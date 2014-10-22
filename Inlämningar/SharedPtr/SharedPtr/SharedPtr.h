#pragma once

#include "Defs.h"
#include <iostream>
#include <cassert>

template<typename T>
class SharedPtr {
public:
	SharedPtr<T>(void);
	SharedPtr<T>(const SharedPtr<T> &sharedPtr);
	SharedPtr<T>(T* ptr);

	//Copy constructor.
	template<typename T2>
	SharedPtr<T>(SharedPtr<T2> &sharedPtr);

	~SharedPtr<T>();

	inline operator bool() const;

	inline bool operator==( const SharedPtr<T> &sharedPtr);

	inline SharedPtr<T> operator=( const SharedPtr<T> &sharedPtr);

	inline bool operator<( const SharedPtr<T> &sharedPtr);

	inline T& operator*();
	inline const T& operator*() const;

	inline T* operator->();
	inline const T* operator->() const;

	inline T* operator&() {
		return &data->ptr;
	}

	inline void Reset();
	inline T* Get();
	inline bool Unique();

private:
	struct SharedPtrData {
		T *ptr = nullptr;
		int count = 0;
	}*data;
};

template<typename T>
SharedPtr<T>::SharedPtr(void) {
	data = new SharedPtrData;
	data->ptr = nullptr;
	data->count += 1;
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &sharedPtr) {
	data = sharedPtr.data;
	data->count += 1;

	++sharedPtr.data->count;
	
	data->count = sharedPtr.data->count;
}

template<typename T>
SharedPtr<T>::SharedPtr(T* ptr) {
	data = new SharedPtrData;
	data->ptr = ptr;
	data->count += 1;
}

//Copy constructor.
template<typename T>
template<typename T2>
SharedPtr<T>::SharedPtr(SharedPtr<T2> &sharedPtr) {
	data = new SharedPtrData;
	sharedPtr.data->count += 1;
	data->ptr = sharedPtr.data->ptr; //Copy the value.
	data->count += sharedPtr.data->count; //copy the count.
}

template<typename T>
SharedPtr<T>::~SharedPtr() {
	delete data->ptr;
}

//if sharedPtr is an object return it.
template<typename T>
SharedPtr<T>::operator bool() const {
	return data->ptr != nullptr;
}

template<typename T>
bool SharedPtr<T>::operator== (const SharedPtr<T> &sharedPtr) {
	return data->ptr == sharedPtr.data->ptr;
}

template<typename T>
SharedPtr<T> SharedPtr<T>::operator= (const SharedPtr<T> &sharedPtr) {
	return data->ptr = sharedPtr.data->ptr;
}

template<typename T>
bool SharedPtr<T>::operator< (const SharedPtr<T> &sharedPtr) {
	return data->ptr < sharedPtr.data->ptr;
}

template<typename T>
T& SharedPtr<T>::operator*() {
	return data->ptr;
}

template<typename T>
const T& SharedPtr<T>::operator*() const {
	return data->ptr;
}

template<typename T>
T* SharedPtr<T>::operator->() {
	return  data->ptr;
}

template<typename T>
const T* SharedPtr<T>::operator->() const {
	return  data->ptr;
}

template<typename T>
void SharedPtr<T>::Reset() {
	data->count--;
	delete data->ptr;
}

template<typename T>
T* SharedPtr<T>::Get() {
	return data->ptr;
}

template<typename T>
bool SharedPtr<T>::Unique() {
	return data->count == 1;
}
