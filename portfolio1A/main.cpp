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

  std::cout << std::endl;
  std::cout << "testing popFront" << std::endl;
  list.popFront();

  std::cout << "expected size:4" << std::endl;
  std::cout << "actual size:" << list.size() << std::endl;

  std::cout << std::endl;
  std::cout << "testing contains" << std::endl;

  std::cout << "expected contains 20:1" << std::endl;
  std::cout << "actual contains 20:" << list.contains(20) << std::endl;

  std::cout << "expected contains 100:0" << std::endl;
  std::cout << "actual contains 100:" << list.contains(100) << std::endl;

  std::cout << std::endl;
  std::cout << "testing remove" << std::endl;

  std::cout << "expected remove 40:1" << std::endl;
  std::cout << "actual remove 40:" << list.remove(40) << std::endl;
  std::cout << "expected size:3" << std::endl;
  std::cout << "actual size:" << list.size() << std::endl;
  std::cout << "expected contains 40:0" << std::endl;
  std::cout << "actual contains 40:" << list.contains(40) << std::endl;

  std::cout << std::endl;
  std::cout << "testing copy constructor" << std::endl;
  LinkedList<int> copyList = list;
  std::cout << "expected copy size:3" << std::endl;
  std::cout << "actual copy size:" << copyList.size() << std::endl;
  copyList.pushFront(99);
  std::cout << "expected original size:3" << std::endl;
  std::cout << "actual original size:" << list.size() << std::endl;
  std::cout << "expected copy size after pushFront:4" << std::endl;
  std::cout << "actual copy size after pushFront:" << copyList.size() << std::endl;

  std::cout << std::endl;
  std::cout << "testing copy assignment" << std::endl;
  LinkedList<int> assignedList;
  assignedList.pushBack(500);
  assignedList=list;
  std::cout << "expected assigned size:3" << std::endl;
  std::cout << "actual assigned size:" << assignedList.size() << std::endl;
  assignedList.pushFront(99);
  std::cout << "expected original size:3" << std::endl;
  std::cout << "actual original size:" << list.size() << std::endl;
  std::cout << "expected assigned size after pushFront:4" << std::endl;
  std::cout << "actual assigned size after pushFront:" << assignedList.size() << std::endl;

  
  
  return 0;
}
