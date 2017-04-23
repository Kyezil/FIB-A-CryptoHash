#include "ExpTime.h"
#include "BloomFilters.h"
#include "RandomDataGenerator.h"
#include "Execution.h"
#include <fstream>
#define BFS_N 8

ExpTime::ExpTime(int m, int kmin, int kmax, shared_ptr<RandomDataGenerator> dg)
: m(m), kmin(kmin), kmax(kmax), times(BFS_N, vector<expTime> (max(0, kmax-kmin+1))), dg(dg) {}

void ExpTime::execute() {
  for (int k = kmin; k <= kmax; ++k) {
    Execution execs[BFS_N];
    BloomFilter bf(m,k,false);
    BF_fnv_murmur bf1(m,k,false);
    BF_fnv_jenkins bf2(m,k,false);
    BF_jenkins_murmur bf3(m,k,false);
    BloomFilter bf4(m,k,true);
    BF_fnv_murmur bf5(m,k,true);
    BF_fnv_jenkins bf6(m,k,true);
    BF_jenkins_murmur bf7(m,k,true);
    execs[0] = Execution(&bf);
    execs[1] = Execution(&bf1);
    execs[2] = Execution(&bf2);
    execs[3] = Execution(&bf3);
    execs[4] = Execution(&bf4);
    execs[5] = Execution(&bf5);
    execs[6] = Execution(&bf6);
    execs[7] = Execution(&bf7);
    for (int i = 0; i < BFS_N; ++i) {
      string s;
      ifstream keys;
      ifstream test;
      dg->getKeys(keys);
      double insertTime = execs[i].insertKeys(keys);
      double containsTime = 0;
      unsigned int totalSize = 0;
      for (int j = 0; j < dg->size(); ++j) {
        dg->getTest(j, test);
        Execution::Result res = execs[i].execute(test);
        totalSize += res.test_size;
        containsTime += res.test_time;        
      }
      times[i][k-kmin] = {insertTime/700, containsTime/totalSize};
    }
  }
}

void ExpTime::displayResults() {
  cout << "Experiment Time results\n"
       << "insertion time\n"
       << "k default fnv-murmur fnv-jenkins jenkins-murmur defaultSHA"
       " fnv-murmur-SHA fnv-jenkins-SHA jenkins-murmur-SHA\n";
  for (int i = 0; i < times[0].size(); ++i) {
    cout << kmin+i;
    for (int j = 0; j < times.size(); ++j) {
      cout << '\t' << times[j][i].insertTime;
    }
    cout << '\n';
  }
  cout << endl;
  cout << "contains time\n"
       << "k default fnv-murmur fnv-jenkins jenkins-murmur defaultSHA"
       " fnv-murmur-SHA fnv-jenkins-SHA jenkins-murmur-SHA\n";
  for (int i = 0; i < times[0].size(); ++i) {
    cout << kmin+i;
    for (int j = 0; j < times.size(); ++j) {
      cout << '\t' << times[j][i].containsTime;
    }
    cout << '\n';
  }
  cout << endl;
}