#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include "BST.h"


struct Contact {
  std::string firstName;
  std::string lastName;
  std::string phone;
  bool operator<(const Contact& other) const {
    if (lastName != other.lastName)
      return lastName < other.lastName;
    return firstName < other.firstName;
  }
  bool operator>(const Contact& other) const {
    return other < *this;
  }
  bool operator==(const Contact& other) const {
    return lastName == other.lastName &&
      firstName == other.firstName;
  }

};
class Directory {
private:
  BST<Contact> tree;
public:
  void add(const Contact& c) {
    tree.insert(c);
  }
  bool lookup(const std::string& lastName, Contact& out) const {
    for (const Contact& c :tree.inorder()) {
      if( c.lastName == lastName) {
	out = c;
	return true;
      }
    }
    return false;
  }
  bool remove(const std::string& lastName) {
    for (const Contact& c : tree.inorder()) {
      if (c.lastName == lastName) {
	tree.remove(c);
	return true;
      }
    }
    return false;
  }
  int count() const {
    return tree.size();
  }
  int height() const {
    return tree.height();
  }
  

  
};


#endif
