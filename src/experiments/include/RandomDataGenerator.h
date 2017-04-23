#ifndef __RANDOM_DATA_GENERATOR_H__
#define __RANDOM_DATA_GENERATOR_H__
#include <istream>
#include <string>
using namespace std;

class DataGenerator {
public:
  static const string dataFolder;
  RandomDataGenerator(string experimentFolder, unsigned int n, vector<unsigned int> &t);
  // get istream of keys to insert
  virtual istream & getKeys();
  // get istream of i-th test
  virtual istream & getTest(int i);
  // get number of tests
  virtual int size() const;
};
#endif