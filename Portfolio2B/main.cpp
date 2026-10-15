#include <iostream>
#include <sstream>
#include <string>
#include "Contact.h"

int main() {
  Directory directory;
  std::string line;
  std::cout << "contact directory\n";
  std::cout << "commands: ADD, LOOKUP, DELETE, LIST, COUNT, EXIT\n";

  while (std::getline(std::cin, line)) {
    std::istringstream input(line);
    std::string command;
    if (!(input >> command))
      continue;
    if (command == "ADD") {
      std::string first, last, phone;
      if (input >> first >> last >> phone) {
	directory.add({first, last, phone});
	std::cout << "Added: " << first
		  << " " << last << "\n";
      } else {
	std::cout << "usage: ADD <first> <last> <phone>\n";
      }
    }
    else if (command == "LOOKUP") {
      std::string last;
      Contact found;
      if (input >> last) {
	if (directory.lookup(last, found)) {
	  std::cout << found.firstName << " "
		    << found.lastName << " - "
		    << found.phone << "\n";
	} else{
	  std::cout << "not found\n";
	}  
      }else {
	std::cout << "usage: LOOKUP <last>\n";
      }
    }
      else if(command == "DELETE") {
	std::string last;
	if (input >> last) {
	  if (directory.remove(last))
	    std::cout << "contact deleted\n";
	  else
	    std::cout << "not found\n";
	} else {
	  std::cout << "usage: DELETE <last>\n";
	}
      }
      else if (command == "LIST") {
	directory.list();
      }
      else if (command == "COUNT") {
	std::cout << "contacts: " << directory.count() << "\n";
	std::cout << "tree height: " << directory.height() << "\n";
      }
      else if (command == "EXIT") {
	std::cout << "Bye !!!\n";
	break;
      }
      else {
	std::cout << "unknown command\n";
      }
  }
  return 0;
}             
