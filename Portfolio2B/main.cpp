#include <iostream>
#include "Contact.h"

int main() {
  Directory directory;
  std::cout << std::boolalpha;
  std::cout << "testing contact directory\n";
  directory.add({"Ben", "Johns", "555-0101"});
  directory.add({"Alice", "Brown", "555-0202"});
  directory.add({"Mary", "Smith", "555-0303"});
  directory.add({"Zoe", "Wilson", "555-0404"});

  std::cout << "\ntesting ADD and COUNT\n";
  std::cout << "expected count: 4\n";
  std::cout << "actual count: " << directory.count() << "\n";

  Contact found;
  std::cout << "\ntesting LOOKUP (Smith)\n";
  bool result = directory.lookup("Smith", found);
  std::cout << "expected: true\n";
  std::cout << "actual: " << result << "\n";
  if (result) {
    std::cout << "expected contact: Mary Smith\n";
    std::cout << "actual contact: "
	      << found.firstName << " "
	      << found.lastName << "\n";
  }

  std::cout << "\ntesting LOOKUP (Brown)\n";
  result = directory.lookup("Brown", found);
  std::cout << "expected: true\n";
  std::cout << "actual: " << result << "\n";

  std::cout << "\ntesting LOOKUP (Not Found)\n";
  result = directory.lookup("Johnson", found);
  std::cout << "expected: false\n";
  std::cout << "actual: " << result << "\n";
  std::cout << "\ntesting tree height\n";
  std::cout << "expected: 2\n";
  std::cout << "actual: " << directory.height() << "\n";

  std::cout << "\ntesting list of sorted contacts\n";
  std::cout << "\nexpected order:\n";
  std::cout << "Brown, Alice - 555-0202\n";
  std::cout << "Johns, Ben - 555-0101\n";
  std::cout << "Smith, Mary - 555-0303\n";
  std::cout << "Wilson, Zoe - 555-0404\n";
  std::cout << "\nactual order:\n";
  directory.list();

  result = directory.remove("Johns");
  std::cout << "Expected: true\n";
  std::cout << "actual: " << result << "\n";
  std::cout << "\ncheck Johns was removed\n";
  result = directory.lookup("Johns", found);
  std::cout << "expected: false\n";
  std::cout << "actual: " << result<< "\n";

  std::cout << "\ncount after deletion\n";
  std::cout << "expected: 3\n";
  std::cout << "actual: " << directory.count() << "\n";
  std::cout << "\ndelete nonexistent contact\n";
  result = directory.remove("Johnson");
  std::cout << "expected: false\n";
  std::cout << "actual: " << result << "\n";


  std::cout << "\ntesting LIST with same last name\n";
  Directory tieDirectory;
  tieDirectory.add({"Mary", "Smith", "555-0303"});
  tieDirectory.add({"Adam", "Smith", "555-0505"});
  tieDirectory.add({"Zoe", "Smith", "555-0606"});
  std::cout << "\nexpected order:\n";
  std::cout << "Smith, Adam - 555-0505\n";
  std::cout << "Smith, Mary - 555-0303\n";
  std::cout << "Smith, Zoe - 555-0606\n";
  std::cout << "\nactual order:\n";
  tieDirectory.list();
  


  return 0;
}
