#ifndef LIST_H
#define LIST_H

template <class T>
class List {
	template <class T> friend class Node;
public:
	List();
	~List();

	inline bool IsNullptr(Node<T> *nodePtr) const;
	void PushFront(const T data);
	void PushBack(const T data);
	Node *PopFront() const;
	Node *PopBack() const;
	Node *Back() const;
	Node *Front() const;
	void ClearList();

private:
	Node *lastNode, *firstNode;
};

#endif //!LIST_H