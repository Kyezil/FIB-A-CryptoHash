#include "ExpOptimalM.h"
#include "BloomFilters.h"
#include "RandomDataGenerator.h"
#include "Execution.h"
#include <fstream>
#define BFS_N 5

ExpOptimalM::ExpOptimalM(int mmin, int mmax, int k, shared_ptr<RandomDataGenerator> dg)
: mmin(mmin), mmax(mmax), k(k), fp_ratios(BFS_N, vector<double> (max(0, (mmax-mmin)/113 + 1))), dg(dg) {}

void ExpOptimalM::execute() {
  unsigned int range = (mmax - mmin)/113;
  for (unsigned int i = 0; i <= range; ++i) {
    int m = mmin + 113*i;
    Execution execs[BFS_N];
    BloomFilter bf(m, k, false);
    BF_fnv_murmur bf1(m, k, false);
    BF_fnv_jenkins bf2(m, k, false);
    BF_jenkins_murmur bf3(m, k, false);
    BloomFilter bf4(m, k, true);
    execs[0] = Execution(&bf);
    execs[1] = Execution(&bf1);
    execs[2] = Execution(&bf2);
    execs[3] = Execution(&bf3);
    execs[4] = Execution(&bf4);
    for (int j = 0; j < BFS_N; ++j) {
      ifstream keys;
      ifstream test;
      dg->getKeys(keys);
      execs[j].insertKeys(keys);
      dg->getTest(0, test);
      fp_ratios[j][i] = execs[j].execute(test).fp_ratio;
    }
  }
}

void ExpOptimalM::displayResults() {
  cout << "Experiment Optimal M results" << endl
       << "M default fnv-murmur fnv-jenkins jenkins-murmur defaultSHA" << endl;
  for (int i = 0; i < fp_ratios[0].size(); ++i) {
    cout << mmin + i*113;
    for (int j = 0; j < fp_ratios.size(); ++j) {
      cout << '\t' << fp_ratios[j][i];
    } cout << endl;
  } cout << endl;
}