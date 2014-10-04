#include "List.h"
#include "Defs.h"

#include <iostream>

List::List() {
	InitializeList();
}

List::~List() {

}

void List::InitializeList() {
	firstNode = nullptr;
	lastNode = nullptr;
}

Node* List::GetFirstNode() {
	return firstNode;
}

Node* List::GetLastNode() {
	return lastNode;
}

Node* List::SetFirstNode(Node *node) {
	return firstNode = node;
}

Node* List::SetLastNode(Node *node) {
	return lastNode = node;
}

void List::PopBack() {
	if (GetFirstNode() != nullptr) {
		Node *tmp = GetLastNode();
		SetLastNode(GetLastNode()->GetPrev());
		GetLastNode()->SetNext(nullptr);
		delete tmp;
	}
	else {
		printf("\nList is empty!\n");
	}
}

void List::PopFront() {
	if (GetFirstNode() != nullptr) {
		Node *tmp = GetFirstNode();
		SetFirstNode(GetFirstNode()->GetNext());
		GetFirstNode()->SetPrev(nullptr);
		delete tmp;
	}
	else {
		printf("\nNo values in List to Pop!\n");
	}
}

void List::PushFront(T data) {
	Node *newNode = DBG_NEW Node;
	newNode->value = data;

	//If the list NOT is empty.
	if (GetFirstNode() != nullptr)
	{
		newNode->SetNext(GetFirstNode());
		newNode->SetPrev(GetLastNode());

		GetFirstNode()->SetPrev(newNode);
		SetFirstNode(newNode);
	}
	else {
		//If the list is empty.
		SetFirstNode(newNode);
		SetLastNode(newNode);
	}
}

void List::PushBack(T data) {
	Node *newNode = DBG_NEW Node;
	newNode->value = data;

	if (GetFirstNode() != nullptr) {
		//If the list is NOT empty.
		newNode->SetNext(GetFirstNode());
		newNode->SetPrev(GetLastNode());

		GetLastNode()->SetNext(newNode);
		SetLastNode(newNode);
		GetLastNode()->SetNext(nullptr);
	}
	else {
		//If the list is empty.
		SetFirstNode(newNode);
		SetLastNode(newNode);
	}
}

bool List::Check(T data) {
	Node *currentPtr = GetFirstNode();

	while (currentPtr != nullptr) {
		if (currentPtr->value == data) {
			return true;
		}
		currentPtr = currentPtr->GetNext();
	}
	return false;
}

int List::AmountOfNodes() {
	Node *currentPtr = GetFirstNode(); 
	int count = 0;

	while (currentPtr != nullptr) {
		count++;
		currentPtr = currentPtr->GetNext();
	}
	return count;
}

void List::PrintList() {
	Node *currentPtr = GetFirstNode();

	if (currentPtr == nullptr) {
		printf("\nList is empty!\n");
	}
	else {
		printf("\nThe element(s) in the list are: ");
		printf("nullptr --> ");
		while (currentPtr != nullptr) {
			printf("%.4f --> ", currentPtr->value);
			currentPtr = currentPtr->GetNext();
		}
		printf("nullptr.\n");
	}
}