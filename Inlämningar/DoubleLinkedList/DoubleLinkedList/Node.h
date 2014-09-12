#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
	template <class T> friend class List;
public:
	Node();
	~Node();

	Node *InsertAfter(List<T> *list, T data);
	Node *InsertBefore(List<T> *list, T data);

	T data;
	
private:
	Node *nextNode, *previousNode;
};

template <class T>
Node<T>::Node() {
	nextNode = nullptr;
	previousNode = nullptr;
}

template <class T>
Node<T>::~Node() {}

template <class T>
Node<T>* Node<T>::InsertAfter( List<T> *list, T data) {

}

template <class T>
Node<T>* Node<T>::InsertBefore(List<T> *list, T data) {
	
}



#endif //!NODE_H