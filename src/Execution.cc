#include "Execution.h"

Execution::Execution(BloomFilter &bloomfilter, istream &input)
  : BF(bloomfilter)
{
  string s;
  while (input >> s) {
    BF.insert(s);
    keys.insert(s); // add element in set (for FP count)
  }
}

Execution::Result Execution::execute(istream &test) {
  Result r;
  return r;
}