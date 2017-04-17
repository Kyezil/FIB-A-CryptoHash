#include <string>
#include <iostream>
#include "ExpFullRandom.h"
using std::string;

ExpFullRandom::ExpFullRandom(int nb) {
  n = nb;
}
void ExpFullRandom::execute() {
// do nothing
  std::cout << "I'm doing nothing" << std::endl;
}

Experiment::Result ExpFullRandom::getResult() {
  Result res;
  res.n = this->n;
  return res;
}

// short description of the experiment
string ExpFullRandom::getDescription() {
  return "Store n random keys and make random queries (strings of length 10)";
}
