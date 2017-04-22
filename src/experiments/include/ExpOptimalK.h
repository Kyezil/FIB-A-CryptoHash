#ifndef __EXPOPTIMALK_H__
#define __EXPOPTIMALK_H__
#include "Experiment.h"
#include "BloomFilter.h"

class ExpOptimalK : public Experiment {
public:
  ExpOptimalK(int m, int n, int kmin, int kmax);
  void execute() override;
  string getDescription() override {
    return "Try multiple values of k in the given range and compute "
    " false positive rate for each case\n\tInserts random strings of length 10";
  }
private:
  int m,n,kmin,kmax;
};

#endif
