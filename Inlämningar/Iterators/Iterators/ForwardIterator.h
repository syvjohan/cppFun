#include "Defs.h"

template<typename T>
class ForwardIterator;

template<typename T>
bool operator==(const ForwardIterator<T> &lhs, const ForwardIterator<T> &rhs);

template<typename T>
bool operator!=(const ForwardIterator<T> &lhs, const ForwardIterator<T> &rhs);

template<typename T>
class ForwardIterator {
public:
	friend class XString;

	ForwardIterator<T>(T *ptr = NULL); // =NULL is for the default constructor.
	~ForwardIterator<T>();

	//Operators
	template<typename T>
	friend bool operator==(const ForwardIterator<T> &lhs, const ForwardIterator<T> &rhs);
	template<typename T>
	friend bool operator!=(const ForwardIterator<T> &lhs, const ForwardIterator<T> &rhs);
	
	ForwardIterator<T>& operator++(); //Prefix
	ForwardIterator<T> operator++(int); //Postfix
	
	ForwardIterator<T> operator+(const ForwardIterator<T> &it);
	ForwardIterator<T> operator+(int n);
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
ForwardIterator<T>::ForwardIterator(T *ptr) {
	direction = 1; //1 is for forward version.
	current = ptr;
}

template<typename T>
ForwardIterator<T>::~ForwardIterator() {

}

template<typename T>
ForwardIterator<T> ForwardIterator<T>::operator+(int n) {
	ForwardIterator<T> it = *this;
	it.current += n * direction;
	return it;
}

template<typename T>
ForwardIterator<T> ForwardIterator<T>::operator+(const ForwardIterator<T> &rhs) {
	ForwardIterator<T> it(ptr);
	it.current = ptr + GetOffset() + rhs.GetOffset();
	return it;
}

//Prefix ++i.
template<typename T>
ForwardIterator<T>& ForwardIterator<T>::operator++() {
	//Increment object.
	current = current + direction;
	return *this;
}

//Postfix i++
template<typename T>
ForwardIterator<T> ForwardIterator<T>::operator++(int) {
	ForwardIterator<T> it = *this;
	current = current + direction;
	return it;
	
}

template<typename T>
inline T& ForwardIterator<T>::operator[](int i) {
	//*((*this) + i).Get();
	return current[i*direction];
}

//Return a reference to the value current points to.
template<typename T>
T& ForwardIterator<T>::operator*() {
	return *current;
}

template<typename T>
const T& ForwardIterator<T>::operator*() const {
	return *current;
}

template<typename T>
inline int ForwardIterator<T>::GetOffset() const {
	return current - first;
}

template<typename T>
inline T* ForwardIterator<T>::Get() {
	return current;
}

//Global scope!
template<typename T>
inline bool operator==(const ForwardIterator<T> &lhs, const ForwardIterator<T> &rhs) {
	return lhs.current == rhs.current;
}

template<typename T>
inline bool operator!=(const ForwardIterator<T> &lhs, const ForwardIterator<T> &rhs) {
	return lhs.current != rhs.current;
}