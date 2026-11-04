Portfolio 3B - Implements two applications using the MinHeap and the HashTable developed in portfolio3A. The applications are a priority task scheduler and a word frequency counter, both are compared to STL containers to verify if correct or not

Priority task scheduler
	 The task scheduler uses MinHeap<Task> to manage tasks based on their priorities, each task contains a name and an integer priority, the lower priority nubers represent higher priority tasks. When priorities are equal tasks are ordered by name
	     The commands are
	     	 ADD <name> <priority>;
		 NEXT: remove and display the highest priority task
		 LIST: display the pending tasks in priority order
		 QUIT
The scheduler uses std::priority_queue to verify the order of the MinHeap and a pass or fail result is displayed after comparing tasks

Word frequency counter
     The word frequency counter reads a text file and counts how many times a word is used with HashTable<std::string, int>
     The program reads words from a text file, converts uppercase letters to lowercase, uses non letters as word seperators, counts the occurrences using the HashTable, displays the 10 most frequent words and compares count with std::unordered_map
     The words are sorted by decreasing frequency while words with equal frequencies are sorted alphabetically

To compile and run
   Compile - make
   Run - make run
   Remove the excecutable - make clean

Example commands
	ADD homework 3
	ADD exam 1
	ADD laundry 5
    	LIST
	NEXT
	WORDS sample.txt
	QUIT

The task scheduler was tested with tasks hacing different priorities. The custom MinHeap order matched std::priority_queue, the word frequency counter was tested with words form sample.txt, custom HashTable word counts match std::unordered_map and both STL checks passed

Limitations
	the task names can't have spaces