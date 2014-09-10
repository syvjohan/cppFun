#ifndef LIST_H
#define LIST_H

template <class T>
class List {
	template <class T> friend class Node;
public:
	List();
	~List();

	void PushFront(const T data);
	void PushBack(const T data);
	Node *PopFront();
	Node *PopBack();
	Node *Back();
	Node *Front();
	void ClearList();
	inline bool IsNullptr(Node *nodePtr);

private:
	Node *lastNode, *firstNode;
};

#endif //!LIST_H