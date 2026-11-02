#ifndef	HASHTABLE_H
#define	HASHTABLE_H
#include <vector>
#include <list>
#include <string>
#include <finctional>
#include <type_traits>
#include <cstddef>

template <typename K, typename V>
class HashTable {
private:
  struct Entry {
    K key;
    V value;
  };
  std::vector<std::list<Entry>> buckets;
  std::size_t count;

  //custom polynomial rolling hash for strings
  std::size_t hash(const K& key) const {
    if constexpr (std::is_same_v<K, std::string>) {
      std::size_t result=0;
      for (unsigned char c : key) {
        result = result * 31+c;
      }
      return result;
    } else {
      return std::hash<K>{}(key);
    }
  }
  //double the number of buckets and redistribute the entries
  void rehash() {
    std::vector<std::list<Entry>> newBuckets(
      buckets.size()*2
    );				     
    for (const auto& bucket : buckets) {
      for (const auto& entry : bucket) {
	std::size_t index =
	  hash(entry.key) % newBuckets.size();
	newBuckets[index].push_back(entry);
      }
    }
    buckets.swap(newBuckets);
  }
public:
  HashTable() : buckets(8), count(0) {}
  //insert a key value pair or update an existing key
  void insert(const K& key, const V& value) {
    std::size_t index=hash(key) % buckets.size();
    for (auto& entry : buckets[index]) {
      if (entry.key == key) {
	entry.value=value;
	return;
      }
    }
    //rehash when the load factor would go past .75
    if (static_cast<double>(count +1)/
	buckets.size() > 0.75) {
      rehash();
    }
    index= hash(key) % buckets.size();
    buckets[index].push_back({key, value});
    ++count;
  }
  //find a key and copy its value into outValue
  bool find(const K& key, V& outValue) const {
    std::size_t index = hash(key) % buckets.size();
    for (const auto& entry : buckets[index]) {
      if (entry.key == key) {
	outValue=entry.value;
	return true;
      }
    }
    return false;
  }
  //remove a keyvalue pair if it exists
  bool remove(const K& key) {
    std::size_t index = hash(key) % buckets.size();
    auto& bucket = bucket[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
      if (it->key == key) {
	bucket.erase(it);
	--count;
	return true;
      }
    }
    return false;
  }
  //return the number of stored key value pairs
  std::size_t size() const {
    return count;
  }
};

#endif
  
  
      
  
