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

  std::cout << "\nTesting BST removal\n";
  tree.insert(60);
  tree.insert(80);
  tree.insert(65);
  tree.remove(20);
  std::cout << "\nRemove leaf node (20):\n";
  std::cout << "expected: false\n";
  std::cout << "actual: " << tree.search(20) << "\n";

  tree.remove(60);
  std::cout << "\nremove node with one child (60):\n";
  std::cout << "expected: false\n";
  std::cout << "actual: " << tree.search(60) << "\n";
  std::cout << "\nCheck child remains (65):\n";
  std::cout << "expected: true\n";
  std::cout << "actual: " << tree.search(65) << "\n";

  tree.remove(50);
  std::cout << "\nremove node with two children (50):\n";
  std::cout << "expected: false\n";
  std::cout << "actual: " << tree.search(50) << "\n";
  std::cout << "\ncheck remaining nodes:\n";
  std::cout << "expected: true\n";
  std::cout << "actual (30): " << tree.search(30) << "\n";
  std::cout << "actual (40): " << tree.search(40) << "\n";
  std::cout << "actual (65): " << tree.search(65) << "\n";
  std::cout << "actual (70): " << tree.search(70) << "\n";
  std::cout << "actual (80): " << tree.search(80) << "\n";

  std::cout << "\ntesting BST height and size\n";
  std::cout << "\ntree size:\n";
  std::cout << "expected: 5\n";
  std::cout << "actual: " << tree.size() << "\n";
  std::cout << "\ntree height:\n";
  std::cout << "expected: 2\n";
  std::cout << "actual: " << tree.height() << "\n";

  BST<int> emptyTree;
  std::cout << "\nempty tree size:\n";
  std::cout << "expected: 0\n";
  std::cout << "actual: " << emptyTree.size() << "\n";
  std::cout << "\nempty tree height:\n";
  std::cout << "expected: -1\n";
  std::cout << "actual: " << emptyTree.height() << "\n";

  std::cout << "\ntesting BST traversals\n";
  std::cout << "\ninorder traversal:\n";
  std::cout << "expected: 30 40 65 70 80\n";
  std::cout << "actual: ";
  for (int value : tree.inorder())
    std::cout << value << " ";
  std::cout << "\n";

  std::cout << "\npreorder traversal:\n";
  std::cout << "expected: 65 30 40 70 80:\n";
  std::cout << "actual: ";
  for (int value : tree.preorder())
    std::cout << value << " ";
  std::cout << "\n";

  std::cout << "\npreorder traversal:\n";
  std::cout << "expected: 65 30 40 70 90\n";
  std::cout << "actual: ";
  for (int value : tree.preorder())
    std::cout << value << " ";
  std::cout << "\n";

  std::cout << "\npostorder traversal:\n";
  std::cout << "expected: 40 30 80 70 65\n";
  std::cout << "actual: ";
  for (int value : tree.postorder())
    std::cout << value << " ";
  std::cout << "\n";

  std::cout << "\nlevel order traversal:\n";
  std::cout << "expected: 65 30 70 40 80\n";
  std::cout << "actual: ";
  for (int value : tree.levelorder())
    std::cout << value <<" ";
  std::cout << "\n";

  std::cout << "\ntesting BST copy constructor\n";
  BST<int> copiedTree(tree);
  std::cout << "\ncopied tree size:\n";
  std::cout << "expected: 5\n";
  std::cout << "actual: " << copiedTree.size() << "\n";
  copiedTree.remove(30);
  std::cout << "\noriginal tree still contains 30:\n";
  std::cout << "expected: true\n";
  std::cout << "actual:" << tree.search(30) << "\n";
  std::cout << "\ncopied tree contains 30:\n";
  std::cout << "expected: false\n";
  std::cout << "actual: " << copiedTree.search(30) << "\n";



  return 0;
}
