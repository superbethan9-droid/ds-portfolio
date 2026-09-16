#include <iostream>
#include "LinkedList.h"
#include <string>

struct Student {
  std::string name;
  int id;
  bool operator==(const Student& other) const {
    return name ==  other.name && id == other.id;
  }
};
std::ostream& operator<<(std::ostream& os, const Student& student) {
  os << student.name << " "<< student.id;
  return os;
}

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

  std::cout << std::endl;
  std::cout << "testing iterator" << std::endl;
  std::cout << "expected values:20 10 50" << std::endl;
  std::cout << "actual values:";
  for (int value : list) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "testing print" << std::endl;
  std::cout << "expected values:20 10 50" << std::endl;
  std::cout << "actual values:";
  list.print();

  std::cout << std::endl;
  std::cout << "testing strng list" << std::endl;
  LinkedList<std::string> stringList;
  stringList.pushBack("apple");
  stringList.pushBack("banana");
  stringList.pushBack("cherry");
  std::cout << "expected values:apple banana cherry" << std::endl;
  std::cout << "actual values:";
  stringList.print();

  std::cout << std::endl;
  std::cout << "testing custom struct list" << std::endl;
  LinkedList<Student> studentList;
  studentList.pushBack({"Ben", 101});
  studentList.pushBack({"Johns", 102});
  studentList.pushBack({"Ethan", 103});
  std::cout << "expected values:Ben 101 Johns 102 Ethan 103" << std::endl;
  std::cout << "actual values:";
  studentList.print();
  
  return 0;
}
