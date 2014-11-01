#pragma once

template<typename T>
class Iterator;

template<typename T>
bool operator==(const T &lhs, const T &rhs);

template<typename T>
bool operator!=(const T &lhs, const T &rhs);

template<typename T>
class Iterator {
public:
	Iterator<T>(T *obj);
	~Iterator<T>();

	typedef Iterator<T> ForwardIterator;
	typedef Iterator<T> ReverseIterator;
	typedef Iterator<const T> ConstIterator;
	typedef Iterator<const T> ConstReverseIterator;

	//Operators
	friend bool operator==(const T &lhs, const T &rhs);
	friend bool operator!=(const T &lhs, const T &rhs);

	Iterator<T>& operator++(); //Prefix
	Iterator<T> operator++(int); //Postfix

	Iterator<T>& operator--(); //Prefix
	Iterator<T> operator--(int); //Postfix

	Iterator<T> operator+(const Iterator<T> &it);
	T& operator[](int i);
	T& operator*();
	const T& operator*() const;
	//End operators

	//Forward iterators
	T* ForwardBegin();
	T* ForwardEnd();

	//Reverse iterator
	T* ReverseBegin();
	T* ReverseEnd();

	//Const iterator
	T* ConstBegin();
	T* ConstEnd();

	//Const reverse iterator
	T* ConstReverseBegin();
	T* ConstReverseEnd();

private:
	T Size(const T *container) const;
	int LastElement(const T *container);
	bool CompareValues(const T *obj1, const T *obj2);

	struct Container {
		T *container;
	}*con;
	
	struct IteratorData {
		Container *first;
		Container *last;
		Container *current;
	}*iterData;
};

template<typename T>
Iterator<T>::Iterator(T *obj) {
	con->container = obj;

	iterData->last = nullptr;
	iterdat->first = nullptr;
	iterData->current = nullptr;
}

template<typename T>
Iterator<T>::~Iterator() {

}

template<typename T>
Iterator<T> Iterator<T>::operator+(const Iterator<T> &it) {
	return iterData->current + it;
}

//Prefix ++i.
template<typename T>
Iterator<T>& Iterator<T>::operator++() {
	//Increment object.
	if (iterData->current == iterData->last) {
		return *this;
	}
	else {
		++iterData->current;
		return *this;
	}
}

//Postfix i++
template<typename T>
Iterator<T> Iterator<T>::operator++(int) {
	if (iterData->current != iterData->last) {
		T *tmp = IterData->current;
		++iterdata->current;
	}
	else {
		return *this;
	}
	
	return tmp;
}

//Prefix --i.
template<typename T>
Iterator<T>& Iterator<T>::operator--() {
	//Increment object.
	if (iterData->current == iterData->first) {
		return *this;
	}
	else {
		--iterData->current;
		return *this;
	}
}

//Postfix i--.
template<typename T>
Iterator<T> Iterator<T>::operator--(int) {
	if (iterData->current != iterData->first) {
		T *tmp = IterData->current;
		--iterdata->current;
	}
	else {
		return *this;
	}

	return tmp;
}

template<typename T>
T& Iterator<T>::operator[](int i) {
	return con->container[i];
}

//Return a reference to the value current points to.
template<typename T>
T& Iterator<T>::operator*() {
	return *iterData->current;
}

template<typename T>
const T& Iterator<T>::operator*() const {
	return *iterData->current;
}

//Forward iterators
template<typename T>
T* Iterator<T>::ForwardBegin() {
	iterData->first = con->container[0];
	&iterData->current = iterData->first;

	return ForwardIterator(&iterData->first);
}

template<typename T>
T* Iterator<T>::ForwardEnd() {
	iterData->last = Size(con->container);
	&iterData->current = iterData->last;

	return ForwardIterator(&iterData->last);
}
//END, Forward iterators

//Reverse iterator
template<typename T>
T* Iterator<T>::ReverseBegin() {
	iterData->last = Size(con->container);
	&iterData->current = iterData->last;

	return ReverseIterator(&iterData->last);
}

template<typename T>
T* Iterator<T>::ReverseEnd() {
	iterData->first = con->container[0];
	&iterData->current = iterData->first;

	return ReverseIterator(&iterData->first);
}
//END, Reverse iterator

//Const iterator
template<typename T>
T* Iterator<T>::ConstBegin() {
	return ConstIterator(ForwardBegin());
}

template<typename T>
T* Iterator<T>::ConstEnd() {
	return ConstIterator(ForwardEnd());
}
//END, Const iterator

//Const reverse iterator
template<typename T>
T* Iterator<T>::ConstReverseBegin() {
	return ConstReverseIterator(ReverseBegin());
}

template<typename T>
T* Iterator<T>::ConstReverseEnd() {
	return ConstReverseIterator(ReverseEnd());
}
//END, Const reverse iterator

template<typename T>
inline int Iterator<T>::LastElement(const T *container) {
	int last = (sizeof(container) / sizeof(container[0]) - 1);
	return last;
}

template<typename T>
inline T Iterator<T>::Size(const T *container) const {
	int last = LastElement(container);
	size_t length = 0;
	while (*container != last) {
		container++;
		length++;
	}

	return length;
}

template<typename T>
inline bool Iterator<T>::CompareValues(const T *obj1, const T *obj2) {
	int last1 = LastElement(obj1);
	int last2 = LastElement(obj2);
	do {
		if (*obj1 != *obj2) {
			return false;
		}
	} while (++obj1 != last1 && ++obj2 != last2);

	return true;
}

//Global scope!
template<typename T>
inline bool operator==(const T &lhs, const T &rhs) {
	return Iterator<T>::CompareValues(lhs, rhs);
}

template<typename T>
inline bool operator!=(const T &lhs, const T &rhs) {
	return !(lhs == rhs);
}