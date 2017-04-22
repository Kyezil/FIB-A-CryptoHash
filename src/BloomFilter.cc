#include "BloomFilter.h"
using std::hash;

BloomFilter::BloomFilter(int m, int k)
  : m_size(m), k_hashes(k), bits(m,false) {}
  
void BloomFilter::insert(const string s) {
  size_t ha = hash<string>()(s);
  size_t h1 = ha & ((1 << 15) - 1); // first 15 bits
  size_t h2 = ha >> 15; // other bits
  for (int i = 0; i < k_hashes; ++i) {
    size_t hi = (h1 + i*h2) % m_size;
    bits[hi] = true;
  }
}

bool BloomFilter::contains(const string s) const {
  bool present = true;
  size_t ha = hash<string>()(s);
  size_t h1 = ha & ((1 << 15) - 1); // first 15 bits
  size_t h2 = ha >> 15; // other bits
  for (int i = 0; present and i < k_hashes; ++i) {
    size_t hi = (h1 + i*h2) % m_size;
    present = bits[hi];
  }
  return present;
}