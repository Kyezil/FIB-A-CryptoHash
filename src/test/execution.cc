#include "Execution.h"
#include "BloomFilters.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {  
  string input = "this is an exemple of a beautiful bloom filter";
  istringstream keys(input);
  BF_fnv_murmur bf(20,2,false);
  Execution e1(&bf);
  e1.insertKeys(keys);
  
  string test_s = "this is an exemple of an input string long enough"
  "so that it must give some false positive";
  istringstream test(test_s);
  Execution::Result r = e1.execute(test);
  cout << "Input size : " << r.test_size
       << "\nFp ratio : " << r.fp_ratio
       << "\nTotal time (s) : " << r.test_time << endl;
}