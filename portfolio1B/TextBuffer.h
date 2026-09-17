#ifndef TEXTBUFFER_H
#define TEXTBUFFER_H
#include <iostream>
#include <string>
#include "LinkedStack.h"

struct UndoRecord {
  std::string action;
  std::string text;
  int position;
};

class TextBuffer {
private:
  std::string document;
  LinkedStack<UndoRecord> undoStack;
  LinkedStack<UndoRecord> redoStack;

public:
  void typeText(const std::string& text);
  void deleteChars(int n);
  void undo();
  void redo();
  void print() const;
};

#endif
