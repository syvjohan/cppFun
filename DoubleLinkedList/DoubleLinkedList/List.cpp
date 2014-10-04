//#include "List.h"
//#include "Defs.h"
//
//#include <iostream>
//
//template <class T>
//List<T>::List() {
//	InitializeList();
//}
//
//template <class T>
//List<T>::~List() {
//
//}
//
//template <class T>
//void List<T>::InitializeList() {
//	firstNode = nullptr;
//	lastNode = nullptr;
//}
//
//template <class T>
//Node<T>* List<T>::GetFirstNode() {
//	return firstNode;
//}
//
//template <class T>
//Node<T>* List<T>::GetLastNode() {
//	return lastNode;
//}
//
//template <class T>
//Node<T>* List<T>::SetFirstNode(Node<T> *node) {
//	return firstNode = node;
//}
//
//template <class T>
//Node<T>* List<T>::SetLastNode(Node<T> *node) {
//	return lastNode = node;
//}
//
//template <class T>
//void List<T>::PopBack() {
//	if (GetFirstNode() != nullptr) {
//		Node *tmp = GetLastNode();
//		SetLastNode(GetLastNode()->GetPrev());
//		GetLastNode()->SetNext(nullptr);
//		delete tmp;
//	}
//	else {
//		printf("\nList is empty!\n");
//	}
//}
//
//template <class T>
//void List<T>::PopFront() {
//	if (GetFirstNode() != nullptr) {
//		Node *tmp = GetFirstNode();
//		SetFirstNode(GetFirstNode()->GetNext());
//		GetFirstNode()->SetPrev(nullptr);
//		delete tmp;
//	}
//	else {
//		printf("\nNo values in List to Pop!\n");
//	}
//}
//
//template <class T>
//void List<T>::PushFront(T data) {
//	Node<T> *newNode = DBG_NEW Node<T>;
//	newNode->value = data;
//
//	//If the list NOT is empty.
//	if (GetFirstNode() != nullptr)
//	{
//		newNode->SetNext(GetFirstNode());
//		newNode->SetPrev(GetLastNode());
//
//		GetFirstNode()->SetPrev(newNode);
//		SetFirstNode(newNode);
//	}
//	else {
//		//If the list is empty.
//		SetFirstNode(newNode);
//		SetLastNode(newNode);
//	}
//}
//
//template <class T>
//void List<T>::PushBack(T data) {
//	Node<T> *newNode = DBG_NEW Node<T>;
//	newNode->value = data;
//
//	if (GetFirstNode() != nullptr) {
//		//If the list is NOT empty.
//		newNode->SetNext(GetFirstNode());
//		newNode->SetPrev(GetLastNode());
//
//		GetLastNode()->SetNext(newNode);
//		SetLastNode(newNode);
//		GetLastNode()->SetNext(nullptr);
//	}
//	else {
//		//If the list is empty.
//		SetFirstNode(newNode);
//		SetLastNode(newNode);
//	}
//}
//
////Check if a specified value exist in the list.
//template <class T>
//bool List<T>::Check(T data) {
//	Node<T> *currentPtr = GetFirstNode();
//
//	while (currentPtr != nullptr) {
//		if (currentPtr->value == data) {
//			return true;
//		}
//		currentPtr = currentPtr->GetNext();
//	}
//	return false;
//}
//
////Counts the number of nodes in the list.
//template <class T>
//int List<T>::AmountOfNodes() {
//	Node<T> *currentPtr = GetFirstNode(); 
//	int count = 0;
//
//	while (currentPtr != nullptr) {
//		count++;
//		currentPtr = currentPtr->GetNext();
//	}
//	return count;
//}
//
//template <class T>
//void List<T>::PrintList() {
//	Node<T> *currentPtr = GetFirstNode();
//
//	if (currentPtr == nullptr) {
//		printf("\nList is empty!\n");
//	}
//	else {
//		printf("\nThe element(s) in the list are: ");
//		printf("nullptr --> ");
//		while (currentPtr != nullptr) {
//			printf("%.4f --> ", currentPtr->value);
//			currentPtr = currentPtr->GetNext();
//		}
//		printf("nullptr.\n");
//	}
//}