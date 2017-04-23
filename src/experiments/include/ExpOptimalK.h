#ifndef __EXPOPTIMALK_H__
#define __EXPOPTIMALK_H__
#include "Experiment.h"
#include "BloomFilter.h"
#include "RandomDataGenerator.h"
#include <iostream>
#include <memory>
using namespace std;

class ExpOptimalK : public Experiment {
public:
  ExpOptimalK(int m, int kmin, int kmax, shared_ptr<RandomDataGenerator> dg);
  void execute() override;
  void displayResults() override;
  string getDescription() override {
    return "Try multiple values of k in the given range and compute "
    " false positive rate for each case\n\tInserts random strings of length 10";
  }
private:
  int m,n,kmin,kmax;
  vector<double> fp_ratios;
  shared_ptr<RandomDataGenerator> dg;
};

#endif
