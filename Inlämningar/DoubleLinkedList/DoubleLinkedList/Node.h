#ifndef NODE_H
#define NODE_H

class Node {
	friend class List;
public:
	Node() :prev(), next() {}
	~Node();

	Node *Prev();
	Node *Next();
	Node *InsertAfter(List *list, T data);
	Node *InsertBefore(List *list, T data);
	
private:
	Node *prev, *next;
};

#endif //!NODE_H