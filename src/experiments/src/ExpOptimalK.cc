#include "ExpOptimalK.h"
#include "BloomFilters.h"
#include "Execution.h"

ExpOptimalK::ExpOptimalK(int m, int n, int kmin, int kmax)
: m(m), n(n), kmin(kmin), kmax(kmax), fp_ratios(max(0, kmax-kmin)) {}

void ExpOptimalK::execute() {
  for (int k = kmin; k <= kmax; ++k) {
    Execution exec(BF_fnv_murmur(m,k,false));
    //exec.insertKeys();
    //fp_ratios.push_back(exec.execute().fp_ratio);
  }  
}

void ExpOptimalK::displayResults() {
  cout << "fp ratios (k,fp)\n";
  for (int i = 0; i < fp_ratios.size(); ++i) {
    cout << kmin+i << ' ' << fp_ratios[i] << '\n';
  }
  cout << endl;
}