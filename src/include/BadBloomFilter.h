#ifndef __BADBLOOMFILTER_H__
#define __BADBLOOMFILTER_H__
#include "BloomFilter.h"
class BadBloomFilter : public BloomFilter {

public:
  using BloomFilter::BloomFilter;
  virtual void insert(const string s) override;
  virtual bool contains(const string s) const override;
private:
  static uint32_t badHash(string s);
};

#endif
