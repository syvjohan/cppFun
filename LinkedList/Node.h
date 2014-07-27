#ifndef NODE_H
#define NODE_H

// Node class
template <typename T> 
class Node {
    T data;
    Node* next;

  public:
    Node() {};
    void SetData(T aData) { data = aData; };
    void SetNext(Node* aNext) { next = aNext; };
    T Data() { return data; };
    Node* Next() { return next; };

  private:
};

#endif //!NODE_H