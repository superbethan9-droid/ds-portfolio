# ds-portfolio
Data structures portfolio

1A, Templated Singly Linked List
the list stores data in allocated nodes with each node containing a value and a pointer to the next node in the list, the class also keeps track of the head of the list and the current number of values
portfolio 1A uses a singly linked list with
	  pushFront - adds a value to the beginning og the list
	  pushBack - adds a value to the end of the list
	  popFront - removes the first element
	  remove - removes the first occurence of a value
	  contains - checks wether a value exists in the list
	  size - returns the number of values
	  isEmpty - checks if the list is empty
	  print - prints all values in the list

i also implemented the rule of three: these functions make deep copies so that copied lists have their own separate nodes and memory
destructor
copy constructor
cop assignment operator

forward iterator is also added and allows the linked list to be sed in a range based for loop

it was tested multiple times with int, std::string, and a custom student struct and verifies that the templated class works with both built in and custom date types
