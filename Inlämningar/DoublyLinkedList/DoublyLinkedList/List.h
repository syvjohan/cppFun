#include "Node.h"


class List {
	
friend class Node;

public:

	List();
	~List();

	
	Node First(Node *head);
	Node Last(Node *tail);
	void PushBack(Node *node);
	void PushFront(Node *node);


private:
	Node *head, *tail;




};