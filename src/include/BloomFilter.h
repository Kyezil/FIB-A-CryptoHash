#ifndef __BLOOMFILTER_H__
#define __BLOOMFILTER_H__
#include <vector>
#include <string>
#include <functional>

using std::string;
using std::hash;
using std::vector;

class BloomFilter {

public:
  BloomFilter(int m_size, int k_hashes, bool crypto);
  virtual void insert(const string s);
  virtual bool contains(const string s) const;
  void clear();

protected:
  int m_size;
  int k_hashes;
  bool crypt;
  vector<bool> bits;
  // transform string if sha256 is active
  virtual string preHashKey(const string s) const;
};

#endif