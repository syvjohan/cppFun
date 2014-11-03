
//
//template<typename T>
//class Iterator;
//
//template<typename T>
//bool operator==(Iterator<T> lhs, Iterator<T> rhs);
//
//template<typename T>
//bool operator!=(Iterator<T> lhs, Iterator<T> rhs);
//
//template<typename T>
//class Iterator {
//public:
//	Iterator<T>(T *first, T *last, T *current);
//	Iterator<T>(const int);
//	~Iterator<T>();
//
//	Iterator<T> SelectIterator(int select);
//
//	typedef Iterator<T> ForwardIterator;
//	typedef Iterator<T> ReverseIterator;
//	typedef Iterator<const T> ConstIterator;
//	typedef Iterator<const T> ConstReverseIterator;
//
//	//Operators
//	friend bool operator==(Iterator<T> lhs, Iterator<T> rhs);
//	friend bool operator!=(Iterator<T> lhs, Iterator<T> rhs);
//
//	Iterator<T>& operator++(); //Prefix
//	Iterator<T> operator++(int); //Postfix
//
//	Iterator<T>& operator--(); //Prefix
//	Iterator<T> operator--(int); //Postfix
//
//	Iterator<T> operator+(const Iterator<T> &it);
//	T& operator[](int i);
//	T& operator*();
//	const T& operator*() const;
//	//End operators
//
//	//Forward iterators
//	Iterator<T> ForwardBegin();
//	T* ForwardEnd();
//
//	//Reverse iterator
//	T* ReverseBegin();
//	T* ReverseEnd();
//
//	//Const iterator
//	T* ConstBegin();
//	T* ConstEnd();
//
//	//Const reverse iterator
//	T* ConstReverseBegin();
//	T* ConstReverseEnd();
//
//private:
//	int NumbOfElement();
//	int GetOffset();
//	T* Get();
//
//	T *first;
//	T *last;
//	T *current;
//};
//
//template<typename T>
//Iterator<T>::Iterator(T *first, T *last, T *current) {
//	this->first = first;
//	this->last = last;
//	current = NULL;
//}
//
//template<typename T>
//Iterator<T>::~Iterator() {
//
//}
//
//template<typename T>
//Iterator<T> Iterator<T>::SelectIterator(int select) {
//	if (select == 1) {
//		//ForwardIterator.
//
//	} 
//	else if (select == 2) {
//		//ReverseIterator.
//
//	} 
//	else if (select == 3) {
//		//Const Iterator.
//
//	} 
//	else if (select == 4) {
//		//Const Reverse Iterator.
//
//	}
//	else {
//
//	}
//}
//
//template<typename T>
//Iterator<T> Iterator<T>::operator+(const Iterator<T> &it) {
//	return GetOffset() + it;
//}
//
////Prefix ++i.
//template<typename T>
//Iterator<T>& Iterator<T>::operator++() {
//	//Increment object.
//	++current;
//	return *this;
//}
//
////Postfix i++
//template<typename T>
//Iterator<T> Iterator<T>::operator++(int) {
//	Iterator<T> *tmp = current;
//	++current;
//	return tmp;
//	
//}
//
////Prefix --i.
//template<typename T>
//Iterator<T>& Iterator<T>::operator--() {
//	//Increment object.
//	--current;
//	return *this;
//}
//
////Postfix i--.
//template<typename T>
//Iterator<T> Iterator<T>::operator--(int) {
//	Iterator<T> *tmp = current;
//	--current;
//	return tmp;
//}
//
//template<typename T>
//T& Iterator<T>::operator[](int i) {
//	return *((*this) + i).Get();
//}
//
////Return a reference to the value current points to.
//template<typename T>
//T& Iterator<T>::operator*() {
//	return *current;
//}
//
//template<typename T>
//const T& Iterator<T>::operator*() const {
//	return *current;
//}
//
////Forward iterators
//template<typename T>
//T* Iterator<T>::ForwardBegin() {
//	return ForwardIterator(&first);
//}
//
//template<typename T>
//T* Iterator<T>::ForwardEnd() {
//	return ForwardIterator(&last);
//}
////END, Forward iterators
//
////Reverse iterator
//template<typename T>
//T* Iterator<T>::ReverseBegin() {
//	&current = last;
//	return ReverseIterator(&last);
//}
//
//template<typename T>
//T* Iterator<T>::ReverseEnd() {
//	&current = first;
//	return ReverseIterator(&first);
//}
////END, Reverse iterator
//
////Const iterator
//template<typename T>
//T* Iterator<T>::ConstBegin() {
//	return ConstIterator(ForwardBegin());
//}
//
//template<typename T>
//T* Iterator<T>::ConstEnd() {
//	return ConstIterator(ForwardEnd());
//}
////END, Const iterator
//
////Const reverse iterator
//template<typename T>
//T* Iterator<T>::ConstReverseBegin() {
//	return ConstReverseIterator(ReverseBegin());
//}
//
//template<typename T>
//T* Iterator<T>::ConstReverseEnd() {
//	return ConstReverseIterator(ReverseEnd());
//}
////END, Const reverse iterator
//
//template<typename T>
//inline int Iterator<T>::NumbOfElement() {
//	return last - first;
//}
//
//template<typename T>
//inline int Iterator<T>::GetOffset() {
//	return current - first;
//}
//
//template<typename T>
//T* Iterator<T>::Get() {
//	return current;
//}
//
////Global scope!
//template<typename T>
//inline bool operator==(Iterator<T> lhs, Iterator<T> rhs) {
//	return lhs == rhs;
//}
//
//template<typename T>
//inline bool operator!=(Iterator<T> lhs, Iterator<T> rhs) {
//	return !(lhs == rhs);
//}