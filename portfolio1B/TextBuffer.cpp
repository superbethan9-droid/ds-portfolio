#include "TextBuffer.h"

void TextBuffer::typeText(const std::string& text) {
  if (text.empty()) {
    return;
  }

  UndoRecord record;
  record.action = "TYPE";
  record.text =text;
  record.position= static_cast<int>(document.size());

  undoStack.push(record);
  document += text;
  while (!redoStack.isEmpty()) {
    redoStack.pop();
  }
}

void TextBuffer::deleteChars(int n) {
  if (n <= 0 || document.empty()) {
    return;
  }
  if (n>static_cast<int>(document.size())) {
    n= static_cast<int>(document.size());
  }
  
  int position =static_cast<int> (document.size()) - n;
  std::string deletedText=document.substr(position, n);

  UndoRecord record;
  record.action="DELETE";
  record.text =deletedText;
  record.position =position;
  undoStack.push(record);
  document.erase(position, n);

  while(!redoStack.isEmpty()) {
    redoStack.pop();
  }
}


void TextBuffer::print() const {
  std::cout << document << std::endl;
}
