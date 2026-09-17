#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

// CSC2180 - Lab 7: Linked-List-Based Stack
//
// Same public interface as Lab 6's ArrayStack, backed by singly linked nodes
// instead of an array.

template <typename T>
class LinkedStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value, Node* n) : data(value), next(n) {}
    };
    Node* topNode;
    int count;

public:
    LinkedStack() : topNode(nullptr), count(0) {}

    ~LinkedStack() {
      while (topNode != nullptr) {
	Node* oldTop = topNode;
	topNode = topNode -> next;
	delete oldTop;
      }
      
        // TODO
    }

    LinkedStack(const LinkedStack& other) : topNode(nullptr), count(0) {
      if (other.topNode ==nullptr) {
	return;
      }
      topNode=new Node (other.topNode->data, nullptr);

      Node* currentNew =topNode;
      Node* currentOther = other.topNode ->next;
      while (currentOther != nullptr){
	currentNew->next = new Node(currentOther->data, nullptr);
        currentNew = currentNew->next;
        currentOther = currentOther->next;
      }
      count = other.count;
      
        // TODO — deep copy, preserving order
    }

    LinkedStack& operator=(const LinkedStack& other) {
      if (this == &other) {
	return *this;
      }

      while (topNode != nullptr) {
	Node* oldTop = topNode;
	topNode = topNode->next;
	delete oldTop;
      }

      count = 0;

      if (other.topNode == nullptr) {
	return *this;
      }

      topNode = new Node(other.topNode->data, nullptr);

      Node* currentNew = topNode;
      Node* currentOther = other.topNode->next;

      while (currentOther != nullptr) {
	currentNew->next = new Node(currentOther->data, nullptr);
	currentNew = currentNew->next;
	currentOther = currentOther->next;
      }

      count = other.count;
        // TODO — deep copy, with self-assignment guard
        return *this;
    }

    void push(const T& value) {
      topNode=new Node(value, topNode);
      count++;
      
        // TODO
    }

    T pop() {
      Node* oldTop = topNode;
      T value = oldTop->data;
      topNode = topNode->next;
      delete oldTop;
      count--;
      return value;
        // TODO — precondition: !isEmpty()
    }

    T top() const {
      return topNode ->data;
      
       // TODO
      
    }

    bool isEmpty() const { return topNode == nullptr; }
    int size() const { return count; }
};

#endif
