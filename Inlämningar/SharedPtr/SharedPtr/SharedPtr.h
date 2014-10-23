//AB5785 Johan Fredriksson
#pragma once

#include "Defs.h"
#include <iostream>
#include <cassert>

template<typename T>
class SharedPtr {
public:
	SharedPtr<T>(void);
	//Copy constructor.
	SharedPtr<T>(const SharedPtr<T> &sharedPtr);
	SharedPtr<T>(T* ptr);

	~SharedPtr<T>();

	//Operators
	operator bool() const;

	bool operator==(const SharedPtr<T> &sharedPtr);

	const SharedPtr<T>& operator=(const SharedPtr<T> &sharedPtr);

	bool operator<(const SharedPtr<T> &sharedPtr);

	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;
	//End operators.

	void Reset();
	T* Get();
	bool Unique();

private:
	//Contains SharedPtr data.
	struct SharedPtrData {
<<<<<<< HEAD
		T *ptr;
		int count;
	};

	SharedPtrData *data;

	//T *ptr;
	//int count = 0;
=======
		T *ptr = nullptr;
		int count = 0;
	}*data;
>>>>>>> 04c1dace757d598424f6637c2c21a045e18dafeb
};

//No meaning to allocate memory for a nullptr.
template<typename T>
SharedPtr<T>::SharedPtr(void) {
	data = nullptr;
}

//Copy constructor.
template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &sharedPtr) {
	data = sharedPtr.data;
	if (data != nullptr) {
		data->count += 1;
	}
}

template<typename T>
SharedPtr<T>::SharedPtr(T* ptr) {
	if (ptr != nullptr) {
		data = DBG_NEW SharedPtrData;
		data->ptr = ptr;
		data->count = 1;
	}
	else {
		data = nullptr;
	}
}

template<typename T>
SharedPtr<T>::~SharedPtr() {
	Reset();
}

//if sharedPtr is an object return it.
template<typename T>
SharedPtr<T>::operator bool() const {
	//The () is for prioritating the evaluating by the statement.
	return data && (data->ptr != nullptr);
}

//If they are equal return true!
template<typename T>
inline bool SharedPtr<T>::operator== (const SharedPtr<T> &sharedPtr) {
	if (data != nullptr) {
		return sharedPtr.data && data->ptr == sharedPtr.data->ptr;
	}
	else {
		return !sharedPtr.data;
	}
}

template<typename T>
inline const SharedPtr<T>& SharedPtr<T>::operator= (const SharedPtr<T> &sharedPtr) {
	//If it is true dont do anything!
	if (sharedPtr.data != data) {
		Reset();
		if (sharedPtr.data != nullptr)
		{
			data = sharedPtr.data;
			data->count++;
		}
	}

	return *this;
}

//Operator< assumes that there is no negative pointers.
template<typename T>
inline bool SharedPtr<T>::operator< (const SharedPtr<T> &sharedPtr) {
	if (data != nullptr) {
		return sharedPtr.data && data->ptr < sharedPtr.data->ptr;
	}
	else {
		return sharedPtr.data != nullptr && sharedPtr.data->ptr != nullptr;
	}
}

//Return a reference to the value pointer points to.
template<typename T>
inline T& SharedPtr<T>::operator*() {
	return *(Get());  //*() dereferencing the pointer.
}

//Return a reference to the value pointer points to.
template<typename T>
inline const T& SharedPtr<T>::operator*() const {
	return *(Get()); //*() dereferencing the pointer.
}

template<typename T>
inline T* SharedPtr<T>::operator->() {
	return Get();
}

template<typename T>
inline const T* SharedPtr<T>::operator->() const {
	return Get();
}

template<typename T>
void SharedPtr<T>::Reset() {
	if (data == nullptr) {
		return;
	} else if (data->count == 1)  {
		delete data->ptr;
		delete data;
		data = nullptr;
	} else  {
		--data->count;
	}

	data = nullptr;
}

template<typename T>
inline T* SharedPtr<T>::Get() {
	return data->ptr;
}

template<typename T>
bool SharedPtr<T>::Unique() {
	return data->count == 1;
}
