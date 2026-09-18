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
Tested program with valgrind
I don't see any known limitations
  	cd ds-portfolio
	cd portfolio1A
	g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o run
	./run
___________________________________________________________

1B) undo/redo text buffers
    Portfolio 1B uses two custom linked list stacks to undo and redo through text
The text buffer supports
    TYPE - adds text to the document you are on
    DELETE - deletes characters from the end of the document
    UNDO - reverses the last change you did
    REDO - changes the most recent undo command back
    PRINT - prints the document
    QUIT - exits
the undo and redo history are using two custom LinkedStack<T> objects, the stack uses the rule of three with a destructor, copy constructor, and copy operator. Since the nodes are stored dynamically, we have to make deep copies so copied stacks can manage their own seperate memory.
Tested program with valgrind
I dont see any limitations besides the DELETE command only removing stuff from the end.
       cd ds-portfolio
       cd portfolio1B
       g++ -std=c++17 -Wall -Wextra -pedantic main.cpp TextBuffer.cpp -o run
       ./run