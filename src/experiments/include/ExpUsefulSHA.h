#ifndef __EXPUSEFULSHA_H__
#define __EXPUSEFULSHA_H__
#include "Experiment.h"
#include "BloomFilter.h"
#include <iostream>
#include <memory>
using namespace std;

class ExpUsefulSha : public Experiment {
public:
  ExpUsefulSha(int m, int nmin, int nmax, int k, int t);
  void execute() override;
  void displayResults() override;
  string getDescription() override {
    return "Uses a bad hash functions and computes the improvement in false positive rate "
    "by using SHA256\n\tInserts numerical strings in order";
  }
private:
  int m,nmin,nmax,k,t;
  double fp_r;
  vector<double> fp_ratios;
  vector<double> fp_ratios_sha;
};

#endif
