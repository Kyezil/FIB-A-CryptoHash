#ifndef __EXPFULLRANDOM_H__
#define __EXPFULLRANDOM_H__
#include "Experiment.h"

class ExpFullRandom : public Experiment {
public:
  ExpFullRandom(int n);
  void execute() override;
  Result getResult() override;
  string getDescription() override;
private:
  int n;
};

#endif
