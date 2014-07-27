#ifndef LIST_H
#define LIST_H

// List class
template <typename T> 
class List {

    Node *root;

  public:
    List() { root = NULL; };
    void Print();
    void Append(T data);
    void Delete(T data);

  private:
};

#endif //!LIST_H

