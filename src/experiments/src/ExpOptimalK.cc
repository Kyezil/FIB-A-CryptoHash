#include "ExpOptimalK.h"
#include "BloomFilters.h"
#include "RandomDataGenerator.h"
#include "Execution.h"
#include <fstream>

ExpOptimalK::ExpOptimalK(int m, int kmin, int kmax, shared_ptr<RandomDataGenerator> dg)
: m(m), kmin(kmin), kmax(kmax), fp_ratios(3, vector<double> (max(0, kmax-kmin+1))), dg(dg) {
}

void ExpOptimalK::execute() {
  for (int k = kmin; k <= kmax; ++k) {
    Execution execs[3];
    BF_fnv_murmur bf1(m,k,false);
    BF_fnv_jenkins bf2(m,k,false);
    BF_jenkins_murmur bf3(m,k,false);
    execs[0] = Execution(&bf1);
    execs[1] = Execution(&bf2);
    execs[2] = Execution(&bf3);
    for (int i = 0; i < 3; ++i) {
      string s;
      ifstream keys;
      ifstream test;
      dg->getKeys(keys);
      execs[i].insertKeys(keys);
      dg->getTest(0, test);
      fp_ratios[i][k-kmin] = execs[i].execute(test).fp_ratio;
    }
  }
}

void ExpOptimalK::displayResults() {
  cout << "Experiment Optimal K results\n"
       << "\tk fnv_murmur fnv_jenkins jenkins_murmur\n";
  for (int i = 0; i < fp_ratios[0].size(); ++i) {
    cout << kmin+i;
    for (int j = 0; j < fp_ratios.size(); ++j) {
      cout << '\t' << fp_ratios[j][i];
    }
    cout << '\n';
  }
  cout << endl;
}