#ifndef TASK_H
#define TASK_H
#include <string>

struct Task {
  std::string name;
  int priority;

  //lower numbers represent higher priority                                                           
  bool operator<(const Task& other) const {
    if (priority != other.priority) {
      return priority < other.priority;
    }
    //break ties alphabetically by task name                                                          
    return name < other.name;
  }
};

//comparator for a min priority STL priority_queue                                                    
struct TaskCompare {
  bool operator()(const Task& a, const Task& b) const {
    return b<a;
  }
};

#endif
