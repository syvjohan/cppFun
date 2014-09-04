#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <class T> class BinaryTree {
	
struct Node
{
	T keyValue;
	Node *parent;
	Node *left;
	Node *right;
};

public:
	BinaryTree();
	~BinaryTree();
	void Insert(T value);
	void DeleteNode(T value);
	void PreOrderTraversal();
	void InorderTraversal();
	void DeleteTree();
	Node *Search(T value);

private:
	Node *InnerSearch(T value);
	void InnerDeleteNode(T value);
	void InnerDeleteTree();
	void InnerInser(T value);
	void InnerPreOrderTraversal(Node *node);
	void InnerInorderTraversal(Node *node);

	Node *root;

};

#endif // !BINARYSEARCHTREE_H