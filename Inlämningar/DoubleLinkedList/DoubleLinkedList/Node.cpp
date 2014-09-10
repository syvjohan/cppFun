#include "Defs.h"
#include "Node.h"

template <class T>
Node<T>::Node() {
	nextNode = nullptr;
	previousNode = nullptr;
}

template <class T>
Node<T>::~Node() {}


