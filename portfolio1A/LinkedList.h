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

  void pushFront(const T& value) {
    Node* newNode = new Node(value);
    newNode->next =head;
    head = newNode;
    count++;
  }

  void pushBack( const T& value) {
    Node* newNode =new Node(value);
    if(head==nullptr) {
      head=newNode;
    } else {
      Node* current = head;
      while (current->next != nullptr) {
	current = current->next;
      }
      current->next = newNode;
    }
    count++;
  }
  
  int size() const {
      return count;
  }

  bool isEmpty() const {
      return count == 0;
  }
  
};

#endif
