#include <iostream>
#include "BST.h"

int main() {
  
  BST<int> tree;

  std::cout << std::boolalpha;

  std::cout << "Testing BST Insertion and Search\n";
  tree.insert(50);
  tree.insert(30);
  tree.insert(70);
  tree.insert(20);
  tree.insert(40);

  std::cout << "\nSearch for 50:\n";
  std::cout << "Expected: true\n";
  std::cout << "Actual: " << tree.search(50) << "\n";
  std::cout << "\nSearch for 40:\n";
  std::cout << "Expected: true\n";
  std::cout << "Actual: " << tree.search(40) << "\n";
  std::cout << "\nSearch for 100:\n";
  std::cout << "Expected: false\n";
  std::cout << "Actual: " << tree.search(100) << "\n";

  return 0;
}
