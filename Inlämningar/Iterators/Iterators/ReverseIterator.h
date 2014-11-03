#include "Defs.h"

template<typename T>
class ReverseIterator;

template<typename T>
bool operator==(const ReverseIterator<T> &lhs, const ReverseIterator<T> &rhs);

template<typename T>
bool operator!=(const ReverseIterator<T> &lhs, const ReverseIterator<T> &rhs);

template<typename T>
class ReverseIterator {
public:
	friend class XString;

	ReverseIterator<T>(T *first = NULL, T *last = NULL); // =NULL is for the default constructor.
	~ReverseIterator<T>();

	//Operators
	template<typename T>
	friend bool operator==(const ReverseIterator<T> &lhs, const ReverseIterator<T> &rhs);
	template<typename T>
	friend bool operator!=(const ReverseIterator<T> &lhs, const ReverseIterator<T> &rhs);

	ReverseIterator<T>& operator++(); //Prefix
	ReverseIterator<T> operator++(int); //Postfix

	ReverseIterator<T> operator+(const ReverseIterator<T> &it);
	ReverseIterator<T> operator+(int n);
	T& operator[](int i);
	T& operator*();
	const T& operator*() const;
	//End operators
private:
	int GetOffset() const;
	T* Get();

	T *first;
	T *last;
	T *current;
	int direction;
};

template<typename T>
ReverseIterator<T>::ReverseIterator(T *first, T *last) {
	//-1 is for reverse version!
	direction = -1;  
	this->first = last - 1; 
	this->last = first - 1; 
	this->current = this->first;
}

template<typename T>
ReverseIterator<T>::~ReverseIterator() {

}

template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator+(int n) {
	ReverseIterator<T> it = *this;
	it.current += n * direction;
	return it;
}

template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator+(const ReverseIterator<T> &rhs) {
	ReverseIterator<T> it(first, last);
	it.current = first + GetOffset() + rhs.GetOffset();
	return it;
}

//Prefix ++i.
template<typename T>
ReverseIterator<T>& ReverseIterator<T>::operator++() {
	//Increment object.
	current = current + direction;
	return *this;
}

//Postfix i++
template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator++(int) {
	ReverseIterator<T> it = *this;
	current = current + direction;
	return it;
}

template<typename T>
inline T& ReverseIterator<T>::operator[](int i) {
	return *((*this) + i).Get();
}

//Return a reference to the value current points to.
template<typename T>
T& ReverseIterator<T>::operator*() {
	return *current;
}

template<typename T>
const T& ReverseIterator<T>::operator*() const {
	return *current;
}

template<typename T>
inline int ReverseIterator<T>::GetOffset() const {
	return current - first;
}

template<typename T>
inline T* ReverseIterator<T>::Get() {
	return current;
}

//Global scope!
template<typename T>
inline bool operator==(const ReverseIterator<T> &lhs, const ReverseIterator<T> &rhs) {
	return lhs.current == rhs.current;
}

template<typename T>
inline bool operator!=(const ReverseIterator<T> &lhs, const ReverseIterator<T> &rhs) {
	return lhs.current != rhs.current;
}