#include "Execution.h"
#include "BloomFilters.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  int m = 20;
  int k = 2;
  string input = "this is an exemple of a beautiful bloom filter";
  BF_fnv_murmur BF(20, 2, false);
  istringstream keys(input);
  Execution e1(BF, keys);
  string test_s = "this is an exemple of an input string long enough"
  "so that it must give some false positive";
  istringstream test(test_s);
  Execution::Result r = e1.execute(test);
  cout << "Input size : " << r.test_size
       << "\nFp ratio : " << r.fp_ratio
       << "\nTotal time (s) : " << r.total_time << endl;
}