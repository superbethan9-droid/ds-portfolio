Portfolio2B Contact Directory
Project uses a contact directory in c++ using the binary search tree (BST). Contacts are organized alphabetically by last name and first name to break ties


- created a contact structure containing first last name and phone number
- comparison operators for organizing contacts in the BST
- implemented ADD, LOOKUP, DELETE, and COUNT
- added height reporting using BST
- created list using BST inorder
- made sure that cntacts are sorted by last name then first name
- if last names are the same than sort by first name
- created command loop that takes user commands
- added test cases for all of the above, more tests verified the alphabetical sorting when contacts have the same last name

Compile and run
	make
	./main
when in use, ADD, LOOKUP, DELETE, LIST, COUNT, EXIT


Known limitations
      BST isn't self balancing so it might take a little longer if very unbalanced
      If contacts have the same first and last name they are treated as duplicates
      Names with characters in them are not supported