#include "Defs.h"
#include "List.h"
#include "Node.h"

template <class T>
List<T>::List() {
	firstNode = nullptr;
}

template <class T>
List<T>::~List() {}

// Push a node to the first position in the list.
template <class T>
void List<T>::PushFront(T data) {
	Node *newNode = new Node; //Allocate memory for a new node.
	newNode->data = data;
	Node *tempNode = firstNode; //Creating a temporary Node with the value of firstNode.
	firstNode = newNode;
	firstNode->nextNode = tempNode;
}

//Pushes a node at the end of the list.
template <class T>
void List<T>::PushBack(T data) {
	Node *newNode = new Node; //Allocate memory for a new node.
	newNode->data = data;
	Node *tempNode = firstNode; //Creating a temporary Node with the value of firstNode.
	if (firstNode != nullptr) {
		//loop until tempNode don't have a value.
		while (tempNode->nextNode) {
			tempNode = tempNode->nextNode;
		}
		//When tempNode  don't have a value set it equal to newNode.
		tempNode->nextNode = newNode;
	} else {
		firstNode = newNode;
	}
}

// Erase the first element in the list.
template <class T>
Node* List<T>::PopFront() {
	if (IsNullptr(firstNode)) {
		return nullptr;
	}

	Node *tempNode = firstNode;
	firstNode = firstNode->nextNode;
	
	return tempNode;
}

// Returns the last element in the list.
template <class T>
Node* List<T>::PopBack() {
	if (IsNullptr(firstNode)) {
		return nullptr;
	}

	Node *tempNode = firstNode;
	Node *previous = nullptr;
	while (!(IsNullptr(tempNode->nextNode))) {
		previous = tempNode;
		tempNode = tempNode->nextNode; //Move one step forward in the list.
	}
	previous->nextNode = nullptr; //erase link to last element.

	return tempNode;
}

// Returns the last element in the list.
template <class T>
Node* List<T>::Back() {
	if (IsNullptr(firstNode)) {
		return nullptr;
	}

	Node *tempNode = firstNode;
	Node *previous = nullptr;
	while (!(IsNullptr(tempNode->nextNode))) {
		previous = tempNode;
		tempNode = tempNode->nextNode; //Move one step forward in the list.
	}

	return tempNode;
}

// Returns the first element in the list.
template <class T>
Node* List<T>::Front() {
	if (IsNullptr(firstNode)) {
		return nullptr;
	}

	return firstNode;
}

//Clear all elements in the list.
template <class T>
void List<T>::ClearList() {
	while (IsNullptr(firstNode)) {
		Node *tempNode = firstNode;
		firstNode = firstNode->nextNode; // Move the pointer one step forward.
		delete tempNode; // Delete previous node.
	}
	firstNode = nullptr;
}

// Check either or not the pointer is a nullptr.
template <class T>
bool List<T>::IsNullptr(Node *nodePtr) {
	return nodePtr == nullptr;
}
