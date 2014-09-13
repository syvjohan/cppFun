#include <iostream>

typedef float T;

struct Node {
	T data;
	Node *prev;
	Node *next;
};

struct List {
	List() {
		head = tail = NULL;
	}
	Node *head;
	Node *tail;
}list;


void PrintForward(Node *head);
void PrintReverse(Node *tail);
void Add(T data);

int main() {

	/*Node *newNode1 = new Node;
	Node *newNode2 = new Node;
	Node *newNode3 = new Node; 


	newNode1->next = NULL;
	newNode1->prev = NULL;
	newNode1->data = 8;
	list.head = NULL;
	list.tail = NULL;

	
	newNode2->data = 16;
	newNode2->prev = newNode1->next;
	newNode2->next = newNode3->prev;
	list.head = newNode1;
	list.tail = newNode2;

	
	newNode3->data = 24;
	newNode3->next = list.tail;
	newNode3->prev = newNode2->next;
	list.head = newNode1;*/

				// [head = NULL] [tail = NULL]
	Add(2);		// [head = 2]->[tail = 2]
	Add(1);		// [head = 1]->[tail = 2]
	PrintForward(list.head);
	//PrintReverse(list.tail);

	Node *myNode;
	while (myNode)  {
		myNode = myNode->next;
	}

	/*
	 firstNode = list.First();

	 while ( firstNode )
	 {
	   if  (firstNode->Data() == 3)
	   {
	    firstNode->InsertAfter(myNewAwesomeNode);
		break;
	   }
	 }
	
	
	*/

	system("pause");
	return 0;
}

void InsertBefore(Node* target, Node* data) {
	if (target->prev)  {
		// Byta rätt..
	}
	else  {
		target->prev = data;
		data->next = target;
	}
}

void InsertAfter(Node* target, Node* data) {
	
}

void PushBack(Node* node) {
	InsertAfter(list.tail, node);
	list.tail = node;
}

void PushFront(Node *node) {
	InsertBefore(list.head, node);
	list.head = node;
}

void Add(T data) {

	Node *newNode = new Node;
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = data;

	if (list.head == nullptr) {
		list.head = list.tail = newNode;
	} else if (newNode->data > list.head->data) {


	} else if (newNode < list.head) {
		Node *tmp = list.head;
		list.head = newNode;
		newNode->prev = tmp;
		
	}
}

void PrintForward(Node *head) {
	Node *temp = head;

	while (temp != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

void PrintReverse(Node *tail) {
	Node *temp = tail;

	while (temp != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->prev;
	}
	std::cout << std:: endl;
}