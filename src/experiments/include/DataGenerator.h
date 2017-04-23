#ifndef __DATA_GENERATOR_H__
#define __DATA_GENERATOR_H__
#include <istream>
#include <iostream>
#include <string>
using namespace std;

class DataGenerator {
public:
  static const string dataFolder;
  DataGenerator();
  // get istream of keys to insert
  virtual void getKeys(istream &is) {};
  // get istream of i-th test
  virtual void getTest(unsigned int i, istream &is) {};
  // get number of tests
  virtual unsigned int size() const {
    return 0;
  };
};

#endif