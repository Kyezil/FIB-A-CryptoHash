#include "BadBloomFilter.h"
#include <iostream>
using namespace std;

void BadBloomFilter::insert(const string s) {
  string s2 = preHashKey(s);
  size_t ha = badHash(preHashKey(s));
  size_t h1 = ha & ((1 << 15) - 1); // first 15 bits
  size_t h2 = ha >> 15; // other bits
  for (int i = 0; i < k_hashes; ++i) {
    size_t hi = (h1 + i*h2) % m_size;
    bits[hi] = true;
  }
}

bool BadBloomFilter::contains(const string s) const {
  bool present = true;
  size_t ha = badHash(preHashKey(s));
  size_t h1 = ha & ((1 << 15) - 1); // first 15 bits
  size_t h2 = ha >> 15; // other bits
  for (int i = 0; present and i < k_hashes; ++i) {
    size_t hi = (h1 + i*h2) % m_size;
    present = bits[hi];
  }
  return present;
}

uint32_t BadBloomFilter::badHash(string s) {
  uint32_t hash = 0;
  for (int i = 0; i < s.size(); ++i) {
    hash += s[i];
  }
  return hash;
}
