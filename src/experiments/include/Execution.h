#ifndef __EXECUTION_H__
#define __EXECUTION_H__
#include "BloomFilter.h"
#include <istream>
#include <string>
#include <unordered_set>
using namespace std;

class Execution {
public:
  // common result class
  struct Result {
    int m, n, k;
    int num_hashes;
    double false_positive_ratio;
    double time_insert;
    double time_contains;
  };
  
  // init given bloomfilter with keys in stream
  Execution(BloomFilter &BF, istream &keys);
  // 
  Result execute(istream &test);
  
private:
  BloomFilter BF;
  unordered_set<string> keys;
};

#endif