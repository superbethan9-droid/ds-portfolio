#include <iostream>
#include "TextBuffer.h"

int main() {
  TextBuffer buffer;
  std::cout << "testing TYPE and PRInt" << std::endl;

  buffer.typeText("hello");
  buffer.typeText(" world");

  std::cout << "expected document: hello world" << std::endl;
  std::cout << "actual document: ";
  buffer.print();

  std::cout << std::endl;
  std::cout << "testing DELETE" << std::endl;
  buffer.deleteChars(6);
  std::cout << "expected document: hello" << std::endl;
  std::cout << "actual document: ";
  buffer.print();
  
  return 0;
}
