#include "ExpOptimalK.h"
#include "BloomFilters.h"
#include "RandomDataGenerator.h"
#include "Execution.h"
#include <fstream>

ExpOptimalK::ExpOptimalK(int m, int kmin, int kmax, shared_ptr<RandomDataGenerator> dg)
: m(m), kmin(kmin), kmax(kmax), fp_ratios(max(0, kmax-kmin+1)), dg(dg) {
}

void ExpOptimalK::execute() {
  for (int k = kmin; k <= kmax; ++k) {
    Execution exec(BF_fnv_murmur(m,k,false));
    ifstream keys;
    string s;
    dg->getKeys(keys);
    exec.insertKeys(keys);
    ifstream test;
    dg->getTest(0, test);
    fp_ratios[k-kmin] = exec.execute(test).fp_ratio;
  }
}

void ExpOptimalK::displayResults() {
  cout << "Experiment Optimal K results\n"
       << "\tfp ratios (k,fp)\n";
  for (int i = 0; i < fp_ratios.size(); ++i) {
      cout << kmin+i << ' ' << fp_ratios[i] << '\n';
  }
  cout << endl;
}