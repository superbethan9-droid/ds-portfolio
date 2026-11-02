#include <iostream>
#include <vector>
#include <stdexcept>
#include "MinHeap.h"

int main() {
  MinHeap<int> heap;
  std::cout << "----MinHeap Tests----\n";
  //testing an empty heap
  std::cout << "initially empty: "
	    << (heap.isEmpty() ? "PASS" : "FAIL") << '\n';

  //insert elements unsorted
  heap.insert(20);
  heap.insert(5);
  heap.insert(15);
  heap.insert(3);
  heap.insert(8);

  //test size and peek
  std::cout << "Size after 5 inserts: "
	    << (heap.size() == 5 ? "PASS" : "FAIL") << '\n';
  std::cout << "peek minimum (expected 3): "
	    << (heap.peek() ==3 ? "PASS" : "FAIL") << '\n';

  //make sure elements are extracted in ascending order
  std::vector<int> expected ={3, 5, 8, 15, 20};
  std::vector<int> actual;
  while (!heap.isEmpty()) {
    actual.push_back(heap.extractMin());
  }
  std::cout << "Extract in ascending order: "
	    << (actual == expected ? "PASS" : "FAIL") << '\n';
  std::cout << "Empty after extraction: "
	    << (heap.isEmpty() ? "PASS" : "FAIL") << '\n';

  //test duplicates and negative values
  heap.insert(4);
  heap.insert(-2);
  heap.insert(4);
  bool correctOrder=
    heap.extractMin() == -2 &&
    heap.extractMin() == 4 &&
    heap.extractMin() == 4;
  std::cout << "negative and duploicate values: "
	    << (correctOrder ? "PASS" : "FAIL") << '\n';

  //test extraction from a empty heap
  bool caughtException=false;
  try {
    heap.extractMin();
  } catch (const std::out_of_range&) {
    caughtException =true;
  }
  std::cout << "Empty heap extraction: "
	    << (caughtException ? "PASS" : "FAIL") << '\n';
  return 0;
}
