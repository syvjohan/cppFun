#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
	template <class T> friend class List;
public:
	Node();
	~Node();

	T data;
	
private:
	Node *nextNode, *previousNode;
};

template <class T>
Node<T>::Node() {
	nextNode = nullptr;
	previousNode = nullptr;
}

template <class T>
Node<T>::~Node() {}




#endif //!NODE_H