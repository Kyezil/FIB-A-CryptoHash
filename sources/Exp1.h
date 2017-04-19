#ifndef __EXP1_H__
#define __EXP1_H__
#include "Experiment.h"

class Exp1 : public Experiment {
public:
  Exp1(string ex);
  void execute() override;
  Result getResult() override;
  string getDescription() override;
private:
  string exampleParam;
  Result res;
};

#endif
