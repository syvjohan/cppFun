#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {
	friend class Node;
public:
	List();
	~List();
	void InitializeList();

	Node* GetFirstNode();
	Node* GetLastNode();
	Node* SetFirstNode(Node *node);
	Node* SetLastNode(Node *node);

	void PopBack(T data);
	void PopFront(T data);

	void PushFront(T data);
	void PushBack(T data);

	void DeleteNode(T data);
	void PrintList();

private:
	Node *firstNode;
	Node *lastNode;
};

#endif //!LIST_H