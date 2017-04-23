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
  virtual getKeys(istream &is);
  // get istream of i-th test
  virtual getTest(int i, istream &is);
  // get number of tests
  virtual int size() const;
};
#endif