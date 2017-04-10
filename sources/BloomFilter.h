#ifndef __BLOOMFILTER_H__
#define __BLOOMFILTER_H__
#include <vector>
#include <functional>  
using namespace std;

class BloomFilter {
public:
  BloomFilter(int m_size, int k_hashes);
  void insert(const string a);
  bool contains(const string a) const;
private:
  int m_size;
  int k_hashes;
  vector<bool> bits;
};
#endif