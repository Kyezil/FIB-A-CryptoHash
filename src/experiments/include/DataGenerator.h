#ifndef __DATA_GENERATOR_H__
#define __DATA_GENERATOR_H__
#include <istream>
#include <string>
using namespace std;

class DataGenerator {
public:
  static const string dataFolder;
  DataGenerator();
  // get istream of keys to insert
  virtual void getKeys(istream &is) = 0;
  // get istream of i-th test
  virtual void getTest(int i, istream &is) = 0;
  // get number of tests
  virtual int size() const = 0;
};
#endif