#ifndef NODE_H
#define NODE_H

typedef float T;

class Node {

public:
	Node();
	~Node();
	void InitializeNode();

	T value;

	Node* GetPrev();	
	Node* GetNext();
	Node* SetPrev(Node *node);
	Node* SetNext(Node *node);

private:
	Node *prev;
	Node *next;

};

#endif //!NODE_H