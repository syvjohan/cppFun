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

#endif //!NODE_H