This project implements a templated binary search tree (BST)

- created a BST class with a private node structure
- added recursive insertion and searching
- added node removal for all 3 cases leaf nodes, nodes w one child and nodes w two children
- added recursive height and size calcs
- Inorder, preorder, postorder, and level order traversals
- recursive detructor for memory cleanup
- implemented the rule of 3 with a destroctor, copy constructor, and a copy assignment operator using recursive deep copy
- compiled and passed all tests and valgrind

to compile and run

make
./main


Limitations -
	    the BST isn't self balancing so performance might go down for very unbalanced trees

