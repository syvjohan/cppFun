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

	ReverseIterator<T>(T *ptr = NULL); // =NULL is for the default constructor.
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
ReverseIterator<T>::ReverseIterator(T *ptr) {
	//-1 is for reverse version!
	direction = -1;  
	current = ptr - 1;
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
	ReverseIterator<T> it(ptr);
	it.current = ptr + GetOffset() + rhs.GetOffset();
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
	//*((*this) + i).Get();
	return current[i*direction];
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