#include <iostream>
#include "LinkedList.h"

int main() {
  LinkedList<int> list;

  std::cout << "Initial list test" << std::endl;
  std::cout << "Size: " << list.size() << std::endl;
  std::cout << "Empty: " << list.isEmpty() << std::endl;

  return 0;
}
