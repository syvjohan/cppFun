#include "List.h"

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

void List::PopBack(T data) {
	if (GetLastNode() != nullptr) {
		if (GetLastNode()->value == data) {
			if (GetLastNode() != GetFirstNode()) {
				SetLastNode(GetLastNode()->GetPrev());
				GetFirstNode()->SetPrev(GetLastNode()->GetPrev());
			} else /*if GetLastNode() == GetFirstNode()*/ {
				InitializeList();
			}
		}
		else {
			printf("\nValue doesn't exist!\n");
		}
	} else {
		printf("\nList is empty!\n");
	}
}

void List::PopFront(T data) {
	if (GetFirstNode() != nullptr) {
		if (GetFirstNode()->value == data) {
			if (GetFirstNode() != GetLastNode() && GetLastNode() != nullptr) {
				SetFirstNode(GetFirstNode()->GetNext());
				GetLastNode()->SetNext(GetFirstNode()->GetPrev());
			}
			//Finns det några fler scenarion?
			else /*(GetFirstNode() == GetLastNode())*/ {
				InitializeList(); //Set the first and last node to nullptr.
			}
		} else {
			printf("\nValue does not exist in List!\n");
		}
	}
	else {
		printf("\nList is empty!\n");
	}
}

void List::PushFront(T data) {
	Node *newNode = new Node;
	newNode->value = data;

	//If the list NOT is empty.
	if (GetFirstNode() != nullptr) 
	{
		newNode->SetNext(GetFirstNode());
		newNode->SetPrev(GetLastNode());

	} else {
	//If the list is empty.
		SetFirstNode(newNode);
		GetFirstNode()->SetNext(nullptr);
		GetFirstNode()->SetPrev(nullptr);
	}
}

void List::PushBack(T data) {
	Node *newNode = new Node;
	newNode->value = data;

	if (GetFirstNode() != nullptr) {
		newNode->SetPrev(GetLastNode());
		newNode->SetNext(GetFirstNode());

	} else {
		//If the list is empty.
		SetFirstNode(newNode);
		GetFirstNode()->SetNext(nullptr);
		GetFirstNode()->SetPrev(nullptr);
	}
}

void List::DeleteNode(T data) {
	Node *currentPtr = new Node;

	if (GetFirstNode != nullptr) {
		while (currentPtr->value != data) {
			if (currentPtr->value == data) {
				currentPtr->SetPrev(currentPtr->GetNext());
			}
			else {
				currentPtr = currentPtr->GetNext();
			}
		}
	}
	else {
		printf("List is empty!");
	}
	

	printf("Node could't be found in list!");
}

void List::PrintList() {
	Node *currentPtr = new Node;
	currentPtr = GetFirstNode();

	if (currentPtr == nullptr) {
		printf("\nList is empty!\n");
	} else {
		printf("\nThe element(s) in the list are: ");
		while (currentPtr != nullptr) {
			printf("%i --> ", currentPtr);
			currentPtr = currentPtr->GetNext();
		}
	}
}