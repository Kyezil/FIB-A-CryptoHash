#include "Execution.h"
#include "Timer.h"

Execution::Execution() {}

Execution::Execution(BloomFilter *bloomfilter)
  : BF(bloomfilter) {}
  
#include <iostream>
double Execution::insertKeys(istream &input) {
  string s;
  Timer timer;
  BF->clear(); keys.clear();
  while (input >> s) keys.insert(s); // add element in set (for FP count)
  timer.start();
  for (string s2 : keys) BF->insert(s2);
  return timer.step();
}

Execution::Result Execution::execute(istream &test) {
  Result result;
  Timer timer;
  int fps = 0; // false positives
  int count = 0; // total count
  string s;
  timer.start();
  while (test >> s) {
    ++count;
    if (BF->contains(s) and keys.find(s) == keys.end())
      ++fps;
  }  
  result.test_time = timer.step();
  result.test_size = count;
  result.fp_ratio = double(fps)/count;
  return result;
}