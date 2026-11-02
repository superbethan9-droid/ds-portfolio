#include <iostream>
#include <vector>
#include <stdexcept>
#include "MinHeap.h"
#include <string>
#include "HashTable.h"



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


  std::cout << "\n---- HashTable Tests ----\n";
  HashTable<std::string, int> table;
  int value=0;
  //test finding a key in a empty table
  std::cout << "Empty table loopup: "
	    << (!table.find("apple", value) ? "PASS" : "FAIL")
	    << '\n';
  //test inserting and finding key value pairs
  table.insert("apple", 10);
  table.insert("banana", 20);
  table.insert("orange", 30);

  bool insertPass = table.find("apple", value) && value==10;
  insertPass= insertPass &&
    table.find("banana", value) && value==20;
  std::cout << "insert and find: "
	    << (insertPass ? "PASS" : "FAIL") << '\n';
  //test the number of stored entries
  std::cout << "size after 3 inserts: "
	    << (table.size() ==3 ? "PASS" : "FAIL") << '\n';
  //test updating an existing key
  table.insert("apple", 50);
  bool updatePass = table.find("apple", value) &&
    value == 50 && table.size() == 3;
  std::cout << "Update existing key: "
	    << (updatePass ? "PASS" : "FAIL") << '\n';

  //test removing a key
  bool removePass= table.remove("banana") &&
    !table.find("banana", value) &&
    table.size() == 2;
  std::cout << "remove existing key: "
	    << (removePass ? "PASS" :"FAIL") << '\n';
  //test removing a key that doesnt exist
  std::cout << "remove missing key: "
	    << (!table.remove("grade") ? "PASS" : "FAIL")
	    << '\n';
  //test separate chaining with colliding string keys
  HashTable<std::string, int> collisions;
  collisions.insert("Aa", 100);
  collisions.insert("BB", 200);
  bool collisionPass= collisions.find("Aa", value) &&
    value==100;
  collisionPass= collisionPass &&
    collisions.find("BB", value) &&
    value == 200;
  std::cout << "handle hash collisions: "
	    << (collisionPass ? "PASS" : "FAIL") << '\n';

  //verify removing one colliding key keeps the order
  bool chainPass= collisions.remove("Aa") &&
				    !collisions.find("Aa", value) &&
				    collisions.find("BB", value) &&
				    value == 200;

  std::cout << "remove from collision chain: "
	    << (chainPass ? "PASS" : "FAIL") << '\n';
  //insert enough entries to trigger multiple rehashes
  HashTable<std::string, int> largeTable;
  for (int i= 0; i < 100; ++i) {
    largeTable.insert("key" + std::to_string(i), i);
  }
  bool rehashPass = largeTable.size() == 100;
  for (int i = 0; i < 100; ++i) {
    if (!largeTable.find("key" + std::to_string(i), value)
      || value != i) {
      rehashPass =false;
      break;
    }
  }
  std::cout << "Rehash and preserve entries: "
	    << (rehashPass ? "PASS" : "FAIL") << '\n';

  //test the template with integer keys
  HashTable<int, std::string> intTable;
  intTable.insert(5, "five");
  intTable.insert(-3, "negative three");
  std::string text;
  bool intPass= intTable.find(-3, text) &&
    text == "negative three";
  std::cout << "Integer key support: "
	    << (intPass ? "PASS" : "FAIL") << '\n';
  

  return 0;
}
