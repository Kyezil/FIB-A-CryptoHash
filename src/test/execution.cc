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
  istringstream stream(input);
  BF_fnv_murmur BF(20, 2, false);
  Execution e1(BF, stream);
}