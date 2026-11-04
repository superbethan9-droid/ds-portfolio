CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

all: main

main: main.cpp Task.h WordCounter.h ../Portfolio3A/MinHeap.h ../Portfolio3A/HashTable.h
	$(CXX) $(CXXFLAGS) main.cpp -o main

run: main
	./main

clean:
	rm -f main

.PHONY: all run clean
