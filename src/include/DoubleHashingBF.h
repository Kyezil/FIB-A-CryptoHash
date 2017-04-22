#ifndef __DOUBLEHASHINGBF_H__
#define __DOUBLEHASHINGBF_H__
#include "BloomFilter.h"

// Uses double hashing to create a Bloom filter from 2 hash functions
class DoubleHashingBF : public BloomFilter {

public:
  using BloomFilter::BloomFilter;
  void insert(const string s);
  bool contains(const string s) const;
  
  virtual uint32_t hash1(const string s) const = 0;
  virtual uint32_t hash2(const string s) const = 0;
};

#endif
