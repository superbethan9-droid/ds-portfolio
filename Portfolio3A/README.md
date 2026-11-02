Portfolio 3A - Implements two data structures from scratch using an array based MinHeap and a hash Table using separate chaining.

The MinHeap<T> class uses an std::vector<T> to store the elemts and maintain the minheap property
Operations
	insert()
	extractMin()
	peek()
	size()
	isEmpty()
	heapifyUp()
	heapifyDown()

The HashTable<K, V> class uses a vector of linked lists to store key value pairs through separate chaining

    Operations
	insert()
	find()
	remove()
	size()
	rehash()
Existing keys are updated when inserted again

Hash Function and Rehashing
     The custom hash function for std::string uses a polynomial rolling hash with a 31 multiplier. Each character adds to the hash calue allowing strings to be converted into buckets. For other key types, std::hash is used. The hash table starts with 8 buckets and automatically doubles its bucket count when inserting a new entry would exceed a load factor of 0.75. During rehashing existing entries are redistributed into the new buckets

To compile and run
   compile - make
   run tests - make run
   remove compiled
   make clean

The test program contins 17 tests:
7 MinHeap tests and 10 HashTable tests
the rests cover insertion, extraction, searching, duplicate values, rehashing, collisions, and removal all 17 tests passed

Known Limitations are Minheap<T> requires values to support comparison using the < operator and that HashTable requires comparable keys.

