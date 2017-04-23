#ifndef __EXPOPTIMALM_H__
#define __EXPOPTIMALM_H__
#include "Experiment.h"
#include "BloomFilter.h"
#include <iostream>
using namespace std;

class ExpOptimalM : public Experiment {
public:
  ExpOptimalM(int mmin, int mmax, int n, int k);
  void execute() override;
  void displayResults() override;
  string getDescription() override {
    return "Try multiple values of m in the given range and compute "
    " false positive rate for each case\n\tInserts random strings of length 10";
  }
private:
  int mmin,mmax,n,k;
  vector<double> fp_ratios;
};

#endif
