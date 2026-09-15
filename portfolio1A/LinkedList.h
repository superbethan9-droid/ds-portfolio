#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
private:  
  struct Node {
      T data;
      Node* next;

      Node(const T& value) : data(value), next(nullptr) {}
  };

  Node* head;
  int count;

public:
  LinkedList() : head(nullptr), count(0) {}

  int size() const {
      return count;
  }

  bool isEmpty() const {
      return count == 0;
  }
  
};

#endif
