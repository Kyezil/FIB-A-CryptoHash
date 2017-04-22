#include "ExpOptimalK.h"
#include "BloomFilters.h"
#include "Execution.h"

ExpOptimalK::ExpOptimalK(int m, int n, int kmin, int kmax)
: m(m), n(n), kmin(kmin), kmax(kmax) {}

void ExpOptimalK::execute() {
  vector<double> fp_ratios;
  fp_ratios.reserve(max(0, kmax-kmin));
  for (int k = kmin; k <= kmax; ++k) {
    Execution exec(BF_fnv_murmur(m,k,false));
    //exec.insertKeys();
    //fp_ratios.push_back(exec.execute().fp_ratio);
  }
}