#ifndef __EXPEXAMPLE_H__
#define __EXPEXAMPLE_H__
#include "Experiment.h"

class ExpExample : public Experiment {
public:
  ExpExample(string ex);
  void execute() override;
  string getDescription() override;
private:
  string exampleParam;
};

#endif
