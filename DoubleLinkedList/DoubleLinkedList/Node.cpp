#include "Node.h"

Node::Node() {
	InitializeNode();
}

void Node::InitializeNode() {
	prev = nullptr;
	next = nullptr;
}

Node::~Node() {
	
}

Node* Node::GetPrev() {
	return prev;
}

Node* Node::GetNext() {
	return next;
}

Node* Node::SetPrev(Node *node) {
	return prev = node;
}

Node* Node::SetNext(Node *node) {
	return next = node;
}