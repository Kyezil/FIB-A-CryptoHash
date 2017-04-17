#include <iostream>
#include <vector>
#include <memory>
#include "Experiment.h"
#include "ExpFullRandom.h"
using namespace std;

int main() {
  vector<shared_ptr<Experiment> > experiments;
  experiments.push_back(make_shared<ExpFullRandom>(10));
    
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
      experiments[expChoice - 1]->init();
      experiments[expChoice - 1]->execute();
    } else if (expChoice == 0) {
      for (shared_ptr<Experiment> exp : experiments) {
        exp->init();
        exp->execute();
      }
    }
  } while (expChoice != -1);  
}