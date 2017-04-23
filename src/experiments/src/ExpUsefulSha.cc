#include "ExpUsefulSHA.h"
#include "BadBloomFilter.h"
#include "Execution.h"
#include <sstream>

ExpUsefulSha::ExpUsefulSha(int m, int nmin, int nmax, int k, int t)
: m(m), nmin(nmin), nmax(nmax), k(k), t(t) {
}

void ExpUsefulSha::execute() {
  BadBloomFilter bf(m, k, false);
  BadBloomFilter bfSHA(m, k, true);
  Execution ex(&bf);
  Execution exSHA(&bfSHA);
  for (int n = nmin; n <= nmax; n += 100) {
    // insert keys
    stringstream ss1, ss2;
    for (int i = 1000; i <= 1000+n; ++i) {
      ss1 << i << ' ';
      ss2 << i << ' ';
    }
    ex.insertKeys(ss1);
    exSHA.insertKeys(ss2);
    
    stringstream st1,st2;
    for (int i = 0; i <= t; ++i) {
      st1 << i << ' ';
      st2 << i << ' ';
    }
    fp_ratios.push_back(ex.execute(st1).fp_ratio);
    fp_ratios_sha.push_back(exSHA.execute(st2).fp_ratio);
  }  
}

void ExpUsefulSha::displayResults() {
  cout << "Experiment usefull sha result results" << endl;
  cout << "n fp fpSHA\n";
  int n = nmin;
  for (int i = 0; i < fp_ratios.size(); ++i) {
    cout << n << ' ' << fp_ratios[i] << ' ' << fp_ratios_sha[i] << '\n';
    n += 100;
  }
  cout << endl;
}