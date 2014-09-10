#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

template <class T>
class List {
	template <class T> friend class Node;
public:
	List();
	~List();

	bool IsNullptr(Node<T> *nodePtr) const;
	void PushFront(const T data);
	void PushBack(const T data);
	Node<T> *PopFront();
	Node<T> *PopBack();
	Node<T> *Back() const;
	Node<T> *Front() const;
	void ClearList();
	void List<T>::PrintList();


private:
	Node<T> *lastNode, *firstNode;
};

template <class T>
List<T>::List() {
	firstNode = nullptr;
}

template <class T>
List<T>::~List() {}

// Check either or not the pointer is a nullptr.
template <class T>
inline bool List<T>::IsNullptr(Node<T> *nodePtr) const {
	return nodePtr == nullptr;
}

// Push a node to the first position in the list.
template <class T>
void List<T>::PushFront(T data) {
	Node<T> *newNode = new Node<T>; //Allocate memory for a new node.
	newNode->data = data;
	Node<T> *tempNode = firstNode; //Creating a temporary Node with the value of firstNode.
	firstNode = newNode;
	firstNode->nextNode = tempNode; //Points forward.
	firstNode->previousNode = nullptr; //Points backwards.
}

//Pushes a node at the end of the list.
template <class T>
void List<T>::PushBack(T data) {
	Node<T> *newNode = new Node<T>; //Allocate memory for a new node.
	newNode->data = data;
	Node<T> *tempNode = firstNode; //Creating a temporary Node with the value of firstNode.
	if (firstNode != nullptr) {
		//loop until tempNode don't have a value.
		while (tempNode->nextNode) {
			tempNode = tempNode->nextNode;
		}
		//When tempNode  don't have a value set it equal to newNode.
		tempNode->nextNode = newNode; //Points forward.
		newNode->previousNode = tempNode; //Points backward.
	} else {
		firstNode = newNode;
		firstNode->previousNode = nullptr;
	}
}

// Erase the first element in the list.
template <class T>
Node<T>* List<T>::PopFront() {
	if (IsNullptr(firstNode)) {
		return nullptr;
	}

	Node<T> *tempNode = firstNode;
	firstNode = firstNode->nextNode;

	return tempNode;
}

// Returns the last element in the list.
template <class T>
Node<T>* List<T>::PopBack() {
	if (IsNullptr(firstNode)) {
		return nullptr;
	}

	Node<T> *tempNode = firstNode;
	Node<T> *previous = nullptr;
	while (!(IsNullptr(tempNode->nextNode))) {
		previous = tempNode;
		tempNode = tempNode->nextNode; //Move one step forward in the list.
	}
	previous->nextNode = nullptr; //erase link to last element.

	return tempNode;
}

// Returns the last element in the list.
template <class T>
Node<T>* List<T>::Back() const {
	if (IsNullptr(firstNode)) {
		return nullptr;
	}

	Node<T> *tempNode = firstNode;
	Node<T> *previous = nullptr;
	while (!(IsNullptr(tempNode->nextNode))) {
		previous = tempNode;
		tempNode = tempNode->nextNode; //Move one step forward in the list.
	}

	return tempNode;
}

// Returns the first element in the list.
template <class T>
Node<T>* List<T>::Front() const {
	if (IsNullptr(firstNode)) {
		return nullptr;
	}

	return firstNode;
}

//Clear all elements in the list.
template <class T>
void List<T>::ClearList() {
	while (!(IsNullptr(firstNode))) {
		Node<T> *tempNode = firstNode;
		firstNode = firstNode->nextNode; // Move the pointer one step forward.
		delete tempNode; // Delete previous node.
	}
	firstNode = nullptr;
}

template <class T>
void List<T>::PrintList() {
	std::cout << "The values in the list are: \n" << std::endl;
	while (firstNode != nullptr) {
		std::cout << " --> " << firstNode->data;
		firstNode = firstNode->nextNode;
	}

	std::cout << "\n" << endl;
}

#endif //!LIST_H

