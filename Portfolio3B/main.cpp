#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include "Task.h"
#include "../Portfolio3A/MinHeap.h"


//check if two tasks have the same name and priority
bool sameTask(const Task& a, const Task& b) {
  return a.name == b.name && a.priority ==b.priority;
}

int main() {
  MinHeap<Task> scheduler;
  std::priority_queue<
    Task,
    std::vector<Task>,
    TaskCompare
  > stlQueue;
  bool allMatch= true;
  int comparisons=0;
  std::cout << "----Priority Task Scheduler----\n";
  std::cout << "Lower priority numbers run first\n";
  std::cout << "Commands: ADD <name> <priority>, "
            << "NEXT, LIST, QUIT\n";
  std::string line;
  while (std::getline(std::cin, line)) {
    std::istringstream input(line);
    std::string command;
    input >> command;
    if (command == "ADD") {
      std::string name;
      int priority;
      std::string extra;
      if (!(input >> name >> priority) ||
        (input >> extra)) {
        std::cout << "usage: ADD <name> <priority>\n";
        continue;
      }
      Task task{name, priority};

      scheduler.insert(task);
      stlQueue.push(task);
      std::cout << "added: " << name
                << " (priority " << priority << ")\n";
    }
    else if (command == "NEXT") {
      if (scheduler.isEmpty()) {
        std::cout << "no pending tasks.\n";
        continue;
      }

      Task next=scheduler.extractMin();
      Task expected=stlQueue.top();
      stlQueue.pop();
      ++comparisons;
      if (!sameTask(next, expected)) {
        allMatch = false;
      }
      std::cout << "next: " << next.name
                << " (priority " << next.priority << ")\n";
    }
    else if (command =="LIST") {
      if (scheduler.isEmpty()) {
        std::cout << "No more pending tasks\n";
        continue;
      }
      //copy the heap so listing doesn't remove tasks
      MinHeap<Task> copy = scheduler;
      std::cout << "pending tasks: \n";
      while (!copy.isEmpty()) {
	Task task = copy.extractMin();
	std::cout << " " << task.name
		  << " (priority " << task.priority
		  << ")\n";
      }
    }
    else if (command =="QUIT") {
      break;
    }
    else if (!command.empty()) {
      std::cout << "unknown command\n";
    }
  }

  //compare all remaining tasks against the STL queue
  while (!scheduler.isEmpty() && !stlQueue.empty()) {
    Task custom =scheduler.extractMin();
    Task expected=stlQueue.top();
    stlQueue.pop();
    ++comparisons;
    if (!sameTask(custom, expected)) {
      allMatch = false;
    }
  }
  if (!scheduler.isEmpty() || !stlQueue.empty()) {
    allMatch=false;
  }
  std::cout << "\n---- STL cross check ----\n";
  if (comparisons == 0) {
    std::cout << "no tasks to compare\n";
  } else {
    std::cout << "task compared: "
	      << comparisons << '\n';
    std::cout << "extraction order: "
	      << (allMatch ? "PASS" : "FAIL") << '\n';
  }
  return allMatch ? 0:1;
}
