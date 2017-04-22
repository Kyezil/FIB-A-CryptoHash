#ifndef __BLOOMFILTERS_H__
#define __BLOOMFILTERS_H__
#include "DoubleHashingBF.h"
#include "fnv1a.h"
#include "murmur3.h"

// Double Hashing Bloom filter with fnv1a and murmur3 as hash functions
class BF_fnv_murmur : public DoubleHashingBF {
  using DoubleHashingBF::DoubleHashingBF;
  inline uint32_t hash1(const string s) const override {
    return fnv1a(s);
  }
  inline uint32_t hash2(const string s) const override {
    return murmur3(s);
  }
};

#endif
