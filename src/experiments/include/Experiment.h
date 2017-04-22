#ifndef __EXPERIMENT_H__
#define __EXPERIMENT_H__
#include <string>
using std::string;

class Experiment {
public:
  // prepare data or any precomputation
  virtual void init() {};
  // do the experiment
  virtual void execute() = 0;
  // short description of the experiment
  virtual string getDescription() {
    return "Empty experiment";
  }
};

#endif
