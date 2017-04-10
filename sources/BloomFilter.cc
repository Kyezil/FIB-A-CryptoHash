#include "BloomFilter.h"
using namespace std;

BloomFilter::BloomFilter(int m, int k)
  : m_size(m), k_hashes(k), bits(m,false) {}
  
void BloomFilter::insert(const string a) {
  size_t pos = hash<string>()(a) % m_size;
  bits[pos] = true;
}

bool BloomFilter::contains(const string a) const {
  size_t pos = hash<string>()(a) % m_size;
  return bits[pos];
}