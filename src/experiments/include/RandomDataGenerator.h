#ifndef __RANDOM_DATA_GENERATOR_H__
#define __RANDOM_DATA_GENERATOR_H__
#include <istream>
#include <string>
#include <vector>
using namespace std;

class RandomDataGenerator {
public:
  string dataFolder = "data/";
  unsigned int t_tests;
  RandomDataGenerator(string experimentFolder, unsigned int n, const vector<unsigned int> &t);
  // get istream of keys to insert
  virtual void getKeys(ifstream &is);
  // get istream of i-th test
  virtual void getTest(unsigned int t, ifstream &is);
  // get number of tests
  virtual unsigned int size() const;
};
#endif