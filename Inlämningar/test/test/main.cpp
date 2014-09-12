#include <iostream>

struct Node {
	int data;
	Node *prev;
	Node *next;
};

void PrintForward(Node *head);
void PrintReverse(Node *tail);

int main() {

	Node *head;
	Node *tail;
	Node *n;


	n = new Node;
	n->data = 1;
	n->prev = NULL;
	head = n;
	tail = n;


	n = new Node;
	n->data = 2;
	n->prev = tail;
	tail->next = n;
	tail = n;

	n = new Node;
	n->data = 3;
	n->prev = tail;
	tail->next = n;
	tail = n;

	n = new Node;
	n->data = 4;
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = NULL;

	PrintForward(head);
	PrintReverse(tail);

	system("pause");
	return 0;
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