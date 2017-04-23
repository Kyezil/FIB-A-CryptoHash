#ifndef __EXPTIME_H__
#define __EXPTIME_H__
#include "Experiment.h"
#include "BloomFilter.h"
#include "RandomDataGenerator.h"
#include <iostream>
#include <memory>
using namespace std;

class ExpTime : public Experiment {
public:
  struct expTime {
    double insertTime;
    double containsTime;
  };
  ExpTime(int m, int kmin, int kmax, shared_ptr<RandomDataGenerator> dg);
  void execute() override;
  void displayResults() override;
  string getDescription() override {
    return "Try multiple values of k in the given range and compute "
    " mean of insert/contains time for each case\n\tInserts random strings of length 10";
  }
private:
  int m,kmin,kmax;
  vector<vector<expTime> > times;
  shared_ptr<RandomDataGenerator> dg;
};

#endif
