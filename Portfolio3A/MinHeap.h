#ifndef MINHEAP_H
#define MINHEAP_H
#include <vector>
#include <stdexcept>
#include <utility>

template <typename T>
class MinHeap {
private:
  std::vector<T> data;

  //move an element upward to keep the minheap property
  void heapifyUp(int index) {
    while (index>0) {
      int parent = (index-1)/2;
      if (!(data[index] < data[parent])) {
	break;
      }
      std::swap(data[index], data[parent]);
      index=parent;
    }
  }

  //move element downward to maintait the himheap property
  void heapifyDownI (int index) {
    int n=static_cast<int>(data.size());
    while (true) {
      int left = 2*index +1;
      int right=2* index+2;
      int smallest=index;
      if (left <n && data[left] < data{smallest]) {
	smallest = left;
      }
      if (right < n && data[right]< data[smallest]) {
	smallest =right;
      }
      if (smallest == index) {
	break;
      }
      std::swap(data[index], data[smallest]);
      index=smallest;
    }
  }
public:
  //insert a new element into the heap
  void insert(const T& value) {
    data.push_back(value);
    heapifyUp(static_cast<int>(data.size())-1);
  }
  //remove and return and smallest element
  T extractMin() {
    if (isEmpty()) {
      throw std::out_of_range("Heap is empty");
    }
    T minValue=data[0];
    data[0] = data.back();
    data.pop_back();
    if (!isEmpty()) {
      heapifyDown(0);
    }
    return minValue;
  }

  //return the smallest element without removing it
  const T& peek() const {
    if (isEmpty()) {
      throw std::out_of_range("Heap is empty");
    }
    return data[0];
  }

  //returns the number of elements
  int size() const {
    return static_cast<int>(data.size());
  }

  //check if heap is empty
  bool isEmpty() const {
    return data.empty();
  }
};

#endif
