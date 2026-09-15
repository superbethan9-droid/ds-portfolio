#include <iostream>
#include "LinkedList.h"

int main() {
  LinkedList<int> list;

  std::cout << "testing pushFront" << std::endl;
  list.pushFront(10);
  list.pushFront(20);
  list.pushFront(30);
  
  std::cout << "expected size:3" << std::endl;
  std::cout << "actual size:" << list.size() << std::endl;

  std::cout << std::endl;
  std::cout << "testing the pushBack" << std::endl;
  list.pushBack(40);
  list.pushBack(50);

  std::cout << "expected size:5" << std::endl;
  std::cout << "actual size:" << list.size() << std::endl;
  
  return 0;
}
