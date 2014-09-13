

class Node {

	friend class List

public:
	Node();
	~Node();

	Node *InsertAfter(List *list, T data); //fel
	Node *InserBefore(); //fel

	T data;

private:







};