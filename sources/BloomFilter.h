#ifndef __BLOOMFILTER_H__
#define __BLOOMFILTER_H__
#include <vector>
#include <string>
#include <functional>

using std::string;
using std::vector;

class BloomFilter {

public:
  BloomFilter(int m_size, int k_hashes);
  void insert(const string s);
  bool contains(const string s) const;

private:
  int m_size;
  int k_hashes;
  vector<bool> bits;
};

#endif