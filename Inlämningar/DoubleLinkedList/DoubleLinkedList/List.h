#ifndef LIST_H
#define LIST_H

class List {
	friend class Node;
public:
	List() :first(), last() {}
	~List();

	Node *PushFront(T data);
	Node *PushBack(T data);
	T PopFront();
	T PopBack();
	Node *First();
	Node *Last();
	bool Check(int count);

private:
	Node *last, *first;
};



#endif //!LIST_H