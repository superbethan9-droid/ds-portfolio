#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <utility>
#include "../Portfolio3A/HashTable.h"

//read a file and process each lowercase word
template <typename Func>
void processWords(const std::string& filename, Func process) {
  std::ifstream file(filename);
  if (!file) {
    throw std::runtime_error("Can't open file: " +filename);
  }
  std::string word;
  char ch;
  while (file.get(ch)) {
    unsigned char c=static_cast<unsigned char>(ch);
    if (std::isalpha(c)) {
      word += static_cast<char>(std::tolower(c));
    } else if (!word.empty()) {
      process(word);
      word.clear();
    }
  }
  if (!word.empty()) {
    process(word);
  }
}

//count words using the custom hash table
inline HashTable<std::string, int> countWordsCustom(
						    const std::string& filename,
						    std::vector<std::string>& uniqueWords) {
  HashTable<std::string, int> counts;
  uniqueWords.clear();
  processWords(filename, [&](const std::string& word) {
      int count=0;
      if (counts.find(word, count)) {
	counts.insert(word, count+1);
      } else{
	counts.insert(word, 1);
	uniqueWords.push_back(word);
      }
  });
  return counts;
}

//give the function from the starter skeleton
inline HashTable<std::string, int> countWordsCustom(
						    const std::string& filename) {
  std::vector<std::string> uniqueWords;
  return countWordsCustom(filename, uniqueWords);
}
//counts words using the STL unordered_map
inline std::unordered_map<std::string, int> countWordsSTL(
							  const std::string& filename) {
  std::unordered_map<std::string, int> counts;
  processWords(filename, [&](const std::string& word) {
      ++counts[word];
  });
  return counts;
}

//compare cusom HashTable counts against STL counts
inline bool compareWordCounts(
			      const std::unordered_map<std::string, int>& stl,
			      const HashTable<std::string, int>& custom) {
  bool match = (stl.size() == custom.size());
  if (!match) {
    std::cout << "Unique word counts differ.\n";
  }
  for (const auto& entry : stl) {
    int customCount=0;
    if (!custom.find(entry.first, customCount)) {
      std::cout << "Missing word: "
                << entry.first << '\n';
      match= false;
    } else if (customCount !=entry.second) {
      std::cout << "Count mismatch for: "
                << entry.first << '\n';
      match= false;
    }
  }
  std::cout << "Word count comparison: "
            << (match ? "PASS" : "FAIL") << '\n';

  return match;
}

//print the 10 most frequent words from the cudtom table
inline void printTopTen(
			const HashTable<std::string, int>& counts,
			const std::vector<std::string>& uniqueWords) {
  std::vector<std::pair<std::string, int>> results;
  for (const auto& word : uniqueWords) {
    int count=0;
    if (counts.find(word, count)) {
      results.push_back({word, count});
    }
  }
//sort by frequency than alphabetically for the ties
  std::sort(results.begin(), results.end(),
	  [](const auto& a, const auto& b) {
	    if (a.second !=b.second) {
	      return a.second>b.second;
	    }
	    return a.first < b.first;
	  });
  std::cout << "\n----Top 10 words----\n";
  std::size_t limit = std::min(
			     results.size(), std::size_t{10}
			     );
  for (std::size_t i=0; i<limit; ++i) {
    std::cout << i+1 << ". "
	      << results[i].first << ": "
	      << results[i].second << '\n';
  }
}

#endif

