#ifndef __RANDOM_DATA_GENERATOR_H__
#define __RANDOM_DATA_GENERATOR_H__
#include "DataGenerator.h"
#include <istream>
#include <string>
#include <vector>
using namespace std;

class RandomDataGenerator : public DataGenerator {
public:
  RandomDataGenerator(string experimentFolder, unsigned int n, const vector<unsigned int> &t);
  // get istream of keys to insert
  void getKeys(ifstream &is);
  // get istream of i-th test
  void getTest(unsigned int t, ifstream &is);
  // get number of tests
  unsigned int size() const;
private:
  string folder;
  unsigned int t_tests;
};
#endif