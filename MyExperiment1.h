#ifndef __MYEXPERIMENT1_H__
#define __MYEXPERIMENT1_H__
#include MyResult.h

using std::string;
using std::vector;

class my_experiment_1 {

public:
  void exp_init();
  void exp_do();
  MyResult get_results();
private:
  vector<string> saved_data; // strings saved in the bloom filter
  vector<string> chacked_data; // strings we look for in the bloom filter
  int k_hash_functions;
  int m_blom_size;
  MyResult result;
  
};

#endif
