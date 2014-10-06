//AB5785 Johan Fredriksson
#ifndef NODE_H
#define NODE_H

//Frammåt deklaration
template<class T>
class List;

template <class T>
class Node {
	friend class List<T>;
public:
	~Node();
	Node();
	void InitializeNode();

	T value;

	Node* GetPrev();	
	Node* GetNext();
	Node* SetPrev(Node *node);
	Node* SetNext(Node *node);

private:
	Node *prev;
	Node *next;
};

#endif //!NODE_H

// "Node.cpp"
#include "Defs.h"

template <class T>
Node<T>::Node() {
	InitializeNode();
}

template <class T>
Node<T>::~Node() {

}

template <class T>
void Node<T>::InitializeNode() {
	prev = nullptr;
	next = nullptr;
}

template <class T>
Node<T>* Node<T>::GetPrev() {
	return prev;
}

template <class T>
Node<T>* Node<T>::GetNext() {
	return next;
}

template <class T>
Node<T>* Node<T>::SetPrev(Node *node) {
	return prev = node;
}

template <class T>
Node<T>* Node<T>::SetNext(Node *node) {
	return next = node;
}