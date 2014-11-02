#pragma once

template<typename T>
class Iterator;

template<typename T>
bool operator==(Iterator<T> lhs, Iterator<T> rhs);

template<typename T>
bool operator!=(Iterator<T> lhs, Iterator<T> rhs);

template<typename T>
class Iterator {
public:
	Iterator<T>(T *first, T *last, T *current);
	Iterator<T>(const int);
	~Iterator<T>();

	Iterator<T> SelectIterator(int select);

	typedef Iterator<T> ForwardIterator;
	typedef Iterator<T> ReverseIterator;
	typedef Iterator<const T> ConstIterator;
	typedef Iterator<const T> ConstReverseIterator;

	//Operators
	friend bool operator==(Iterator<T> lhs, Iterator<T> rhs);
	friend bool operator!=(Iterator<T> lhs, Iterator<T> rhs);

	Iterator<T>& operator++(); //Prefix
	Iterator<T> operator++(int); //Postfix

	Iterator<T>& operator--(); //Prefix
	Iterator<T> operator--(int); //Postfix

	//Iterator<T> operator+(const Iterator<T> &it);
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
	int NumbOfElement();
	int GetOffset();

	T *first;
	T *last;
	T *current;
};

template<typename T>
Iterator<T>::Iterator(T *first, T *last, T *current) {
	this->first = first;
	this->last = last;
	current = NULL;
}

template<typename T>
Iterator<T>::Iterator(const int index) {
	
}

template<typename T>
Iterator<T>::~Iterator() {

}

template<typename T>
Iterator<T> Iterator<T>::SelectIterator(int select) {
	if (select == 1) {
		//ForwardIterator.

	} 
	else if (select == 2) {
		//ReverseIterator.

	} 
	else if (select == 3) {
		//Const Iterator.

	} 
	else if (select == 4) {
		//Const Reverse Iterator.

	}
	else {

	}
}

//template<typename T>
//Iterator<T> Iterator<T>::operator+(const Iterator<T> &it, const int index) {
//
//	//int offset = iterData->current - iterData->first;
//	////offset + it. skapa en operator för att plussa int och klassen iterator.
//	//return iterData->current + it;
//}

//Prefix ++i.
template<typename T>
Iterator<T>& Iterator<T>::operator++() {
	//Increment object.
	++iterData->current;
	return *this;
}

//Postfix i++
template<typename T>
Iterator<T> Iterator<T>::operator++(int) {
	Iterator<T> *tmp = IterData->current;
	++iterdata->current;
	return tmp;
	
}

//Prefix --i.
template<typename T>
Iterator<T>& Iterator<T>::operator--() {
	//Increment object.
	--iterData->current;
	return *this;
}

//Postfix i--.
template<typename T>
Iterator<T> Iterator<T>::operator--(int) {
	Iterator<T> *tmp = IterData->current;
	--iterdata->current;
	return tmp;
}

template<typename T>
T& Iterator<T>::operator[](int i) {
	return *((*this) + i).get();
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
inline int Iterator<T>::NumbOfElement() {
	return last - first;
}

template<typename T>
inline int Iterator<T>::GetOffset() {
	return current - first;
}

//Global scope!
template<typename T>
inline bool operator==(Iterator<T> lhs, Iterator<T> rhs) {
	return lhs == rhs;
}

template<typename T>
inline bool operator!=(Iterator<T> lhs, Iterator<T> rhs) {
	return !(lhs == rhs);
}