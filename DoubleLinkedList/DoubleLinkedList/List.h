//AB5785 Johan Fredriksson
#ifndef LIST_H
#define LIST_H

#include <cassert>
#include "Node.h"


template <class T>
class List {
	friend class Node<T>;
public:
	List();
	~List();
	void InitializeList();

	Node<T>* GetFirstNode();
	Node<T>* GetLastNode();
	Node<T>* SetFirstNode(Node<T> *node);
	Node<T>* SetLastNode(Node<T> *node);

	void PopBack();
	void PopFront();

	void PushFront(const T& data);
	void PushBack(const T& data);

	bool SearchForNode(T data);
	bool Check(int count);
	void PrintList();
	int AmountOfNodes();
	void Clear();

private:
	int count;
	Node<T> *firstNode;
	Node<T> *lastNode;
};

#endif //!LIST_H

// "List.cpp"
#include "Defs.h"

#include <iostream>

template <class T>
List<T>::List() {
	InitializeList();
}

template <class T>
List<T>::~List() {
	Clear();
}

template <class T>
void List<T>::Clear() {
	Node<T> *currentPtr = GetFirstNode();

	Node<T> *tmp;
	while (currentPtr != nullptr) {
		tmp = currentPtr;
		currentPtr = currentPtr->GetNext();
		delete tmp;
	}
}

template <class T>
void List<T>::InitializeList() {
	firstNode = nullptr;
	lastNode = nullptr;
	count = 0;
}

template <class T>
Node<T>* List<T>::GetFirstNode() {
	return firstNode;
}

template <class T>
Node<T>* List<T>::GetLastNode() {
	return lastNode;
}

template <class T>
Node<T>* List<T>::SetFirstNode(Node<T> *node) {
	return firstNode = node;
}

template <class T>
Node<T>* List<T>::SetLastNode(Node<T> *node) {
	return lastNode = node;
}

template <class T>
void List<T>::PopBack() {
	if (GetFirstNode() == GetLastNode() && GetFirstNode() != NULL) {
		assert(count == 1);

		delete firstNode;
		firstNode = lastNode = NULL;
		count = 0;
	} else if (GetFirstNode() != nullptr) {
		assert(count > 1);
		Node<T> *tmp = GetLastNode();
		SetLastNode(GetLastNode()->GetPrev());
		GetLastNode()->SetNext(nullptr);
		delete tmp;
		--count;
	} else {
		assert(count == 0);
		printf("\nList is empty!\n");
	}
}

template <class T>
void List<T>::PopFront() {
	if (GetFirstNode() != nullptr) {
		Node<T> *tmp = GetFirstNode();
		SetFirstNode(GetFirstNode()->GetNext());
		GetFirstNode()->SetPrev(nullptr);
		delete tmp;
		--count;
	} else {
		printf("\nNo values in List to Pop!\n");
	}
}

template <class T>
void List<T>::PushFront(const T& data) {
	Node<T> *newNode = DBG_NEW Node<T>;
	newNode->value = data;

	//If the list NOT is empty.
	if (GetFirstNode() != nullptr) {
		newNode->SetNext(GetFirstNode());
		newNode->SetPrev(GetLastNode());

		GetFirstNode()->SetPrev(newNode);
		SetFirstNode(newNode);
	} else {
		//If the list is empty.
		SetFirstNode(newNode);
		SetLastNode(newNode);
	}

	++count;
}

template <class T>
void List<T>::PushBack(const T& data) {
	Node<T> *newNode = DBG_NEW Node<T>;
	newNode->value = data;

	if (GetFirstNode() != nullptr) {
		//If the list is NOT empty.
		newNode->SetNext(GetFirstNode());
		newNode->SetPrev(GetLastNode());

		GetLastNode()->SetNext(newNode);
		SetLastNode(newNode);
		GetLastNode()->SetNext(nullptr);
	} else {
		//If the list is empty.
		SetFirstNode(newNode);
		SetLastNode(newNode);
	}

	++count;
}


//Check if a specified value exist in the list.
template <class T>
bool List<T>::SearchForNode(T data) {
	Node<T> *currentPtr = GetFirstNode();

	while (currentPtr != nullptr) {
		if (currentPtr->value == data) {
			return true;
		}
		currentPtr = currentPtr->GetNext();
	}
	return false;
}

//Counts the number of nodes in the list.
template <class T>
int List<T>::AmountOfNodes() {
	Node<T> *currentPtr = GetFirstNode();
	int count = 0;

	while (currentPtr != nullptr) {
		count++;
		currentPtr = currentPtr->GetNext();
	}
	return count;
}

template <class T>
bool List<T>::Check(int count) {
	if (count != this->count) // Se till att vi räknat noderna rätt.
		return false;

	//count anger hur många noder som förväntas i strukturen.
	//true betyder att allt var ok
	if ((count == 0) ^ (firstNode == nullptr))
		return false; //tom lista ska ha first=null och tvärtom.
	if (firstNode == nullptr)
		return (lastNode == nullptr && count == 0);
	if ((lastNode == nullptr) || count == 0)
		return false;
	//nu är first och last != null och count!=0)
	Node<T> *tmpNode = firstNode;
	Node<T> *tail = nullptr;
	while (tmpNode != nullptr && count > 0) {
		if (tail != tmpNode->prev)
			return false;
		count--;
		tail = tmpNode;
		tmpNode = tmpNode->next;
	}
	return (tail == lastNode) && count == 0;
}

template <class T>
void List<T>::PrintList() {
	Node<T> *currentPtr = GetFirstNode();

	if (currentPtr == nullptr) {
		printf("\nList is empty!\n");
	} else {
		printf("\nThe element(s) in the list are: ");
		printf("nullptr --> ");
		while (currentPtr != nullptr) {
			printf("%.4f --> ", currentPtr->value);
			currentPtr = currentPtr->GetNext();
		}
		printf("nullptr.\n");
	}
}

