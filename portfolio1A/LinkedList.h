#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

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

  ~LinkedList() {
    Node* current=head;
    while (current != nullptr) {
      Node* temp = current;
      current=current->next;
      delete temp;
    }
    head=nullptr;
    count=0;
  }

  LinkedList(const LinkedList& other) : head(nullptr), count(0) {
    Node* current =other.head;
    while( current != nullptr) {
      pushBack(current->data);
      current = current->next;
    }
  }

  LinkedList& operator=(const LinkedList& other) {
    if(this==&other) {
      return *this;
    }
    while (head != nullptr){
      popFront();
    }
    Node* current = other.head;
    while(current != nullptr) {
      pushBack(current->data);
      current=current->next;
    }
    return *this;
  }

  class Iterator {
  private:
    Node* current;
  public:
    Iterator(Node* node) : current(node) {}
    T& operator*() {
      return current->data;
    }
    Iterator& operator++() {
      current = current->next;
      return *this;
    }
    bool operator!=(const Iterator& other) const {
      return current != other.current;
    }
  };
  Iterator begin() {
    return Iterator(head);
  }
  Iterator end() {
    return Iterator(nullptr);
  }

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

  bool popFront() {
    if (head == nullptr) {
      return false;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    count--;
    return true;
  }

  bool contains(const T& value) const {
    Node* current =head;
    while (current != nullptr) {
      if (current->data == value) {
	return true;
      }
      current = current->next;
    }
    return false;
  }

  bool remove(const T& value) {
    if (head ==nullptr) {
      return false;
    }
    if (head->data == value) {
      return popFront();
    }
    Node* current =head;
    
    while (current->next != nullptr) {
      if(current->next->data==value) {
	Node* temp =current->next;
	current->next = temp->next;
	delete temp;
	count--;
	return true;
      }
      current = current->next;
    }
    return false;
  }

  void print() const {
    Node* current = head;
    while(current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
  
  int size() const {
      return count;
  }

  bool isEmpty() const {
      return count == 0;
  }
  
};

#endif
