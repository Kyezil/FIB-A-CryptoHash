#include "ExpOptimalM.h"
#include "BloomFilters.h"
#include "Execution.h"

ExpOptimalM::ExpOptimalM(int mmin, int mmax, int n, int k)
: mmin(mmin), mmax(mmax), n(n), k(k), fp_ratios(max(0, mmax-mmin)) {}

void ExpOptimalM::execute() {
  for (int m = mmin; m <= mmax; ++m) {
    Execution exec(BF_fnv_murmur(m, k, false));
    //exec.insertKeys();
    //fp_ratios.push_back(exec.execute().fp_ratio);
  }
}

void ExpOptimalM::displayResults() {
  cout << "fp ratios (m,fp)\n";
  for (int i = 0; i < fp_ratios.size(); ++i) {
    cout << mmin+i << ' ' << fp_ratios[i] << '\n';
  }
  cout << endl;
}