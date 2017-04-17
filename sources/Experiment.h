#ifndef __EXPERIMENT_H__
#define __EXPERIMENT_H__

class Experiment {
  class Result {
    int m, n, k;
    int num_hashes;
    int time_taken;
    double false_positive;
  }
  virtual void init() = 0;
  virtual void do() = 0;
  virtual Result getResult() = 0;
};

#endif
