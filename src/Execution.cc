#include "Execution.h"
#include "Timer.h"

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
  Result result;
  Timer timer;
  int fps = 0; // false positives
  int count = 0; // total count
  string s;
  timer.start();
  while (test >> s) {
    ++count;
    if (BF.contains(s) and keys.find(s) == keys.end())
      ++fps;
  }  
  result.total_time = timer.step();
  result.test_size = count;
  result.fp_ratio = double(fps)/count;
  return result;
}