#include <iostream>
#include "TextBuffer.h"
#include <sstream>
#include <string>

int main() {
  TextBuffer buffer;
  std::string command;
  std::cout << "Undo/Redo Text Buffer" << std::endl;
  std::cout << "commands: TYPE <text>, DELETE <n>, UNDO, REDO, PRINT, QUIT"
	    << std::endl;
  while (std::getline(std::cin, command)) {
    if(command.rfind("TYPE ", 0)==0) {
      buffer.typeText(command.substr(5));
    }
    else if (command.rfind("DELETE ", 0)==0) {
      std::istringstream input(command.substr(7));
      int n;

      if(input >> n) {
	buffer.deleteChars(n);
      }
      else {
	std::cout << "Invalid DELETE command" << std::endl;
      }
    }
    else if (command=="UNDO") {
      buffer.undo();
    }
    else if (command=="REDO") {
      buffer.redo();
    }
    else if(command=="PRINT") {
      buffer.print();
    }
    else if (command=="QUIT") {
      break;
    }
    else if(!command.empty()) {
      std::cout << "Unknown command" << std::endl;
    }
  }
  return 0;
}
      
