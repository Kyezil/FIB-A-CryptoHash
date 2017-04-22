#include <string>
#include <iostream>
#include "ExpExample.h"
using std::string;

ExpExample::ExpExample(string ex) {
  exampleParam = ex;
}

void ExpExample::execute() {
  std::cout << "My param is " << exampleParam << std::endl;
}

// short description of the experiment
string ExpExample::getDescription() {
  return "Empty experiment to be used as structure";
}
