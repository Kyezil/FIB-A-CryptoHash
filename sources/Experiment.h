#ifndef __EXPERIMENT_H__
#define __EXPERIMENT_H__
#include <string>
using std::string;

class Experiment {
public:
  // common result class
  struct Result {
    int m, n, k;    
    int num_hashes;
    double false_positive_ratio;
  };
  // prepare data or any precomputation
  virtual void init() {};
  // do the experiment
  virtual void execute() = 0;
  // get the results of the experiment
  virtual Result getResult() = 0;
  
  // short description of the experiment
  virtual string getDescription() {
    return "Empty experiment";
  }
};

#endif
