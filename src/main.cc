#include <iostream>
#include <cstdio>
#include <vector>
#include <memory>
#include <algorithm>

#include "Experiment.h"
#include "ExpExample.h"
#include "ExpOptimalK.h"
#include "ExpOptimalM.h"

#include "RandomDataGenerator.h"
using namespace std;

void runExperiment(shared_ptr<Experiment> exp) {
  exp->init();
  exp->execute();
  exp->displayResults();
}

int main() {
  vector<shared_ptr<Experiment> > experiments;
  
  vector<unsigned int> vk = { 2000 };
  shared_ptr<RandomDataGenerator> rdg = make_shared<RandomDataGenerator>("random", 500, vk);
  // list of experiments
  experiments.push_back(make_shared<ExpExample>("exemple"));
  experiments.push_back(make_shared<ExpOptimalK>(1000, 1, 20, rdg));
  experiments.push_back(make_shared<ExpOptimalM>(500, 10000, 50, 10));
    
  cout << "----- Bloom filter experiments -----" << endl;
  int expNum = 1;
  for (shared_ptr<Experiment> exp : experiments) {
    cout << "Experiment " << expNum++ << '\n'
         << '\t' << exp->getDescription() << endl;
  }
  cout << endl;

  int expChoice = 0;
  
  // user interface
  do {
    cout << "Which experiment ? (0 for all, -1 to quit)" << endl;
    cin >> expChoice;
    if (expChoice > 0 and expChoice <= experiments.size()) {
      runExperiment(experiments[expChoice-1]);
    } else if (expChoice == 0) {
      for_each(experiments.begin(), experiments.end(), runExperiment);
    }
  } while (expChoice != -1);  
}