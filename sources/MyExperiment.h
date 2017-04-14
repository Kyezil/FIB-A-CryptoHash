#ifndef __MYEXPERIMENT_H__
#define __MYEXPERIMENT_H__
#include "MyResult.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class MyExperiment {

public:
  void exp_init();
  void exp_do();
  MyResult get_results();
private:
  vector<string> saved_data; // strings saved in the bloom filter
  vector<string> check_data; // strings we look for in the bloom filter
  int k_hashes;
  int m_size;
  MyResult result;
  
};

#endif
