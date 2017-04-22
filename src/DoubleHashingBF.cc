#include "DoubleHashingBF.h"

void DoubleHashingBF::insert(const string s) {
  string s2 = preHashKey(s);
  uint32_t h1 = hash1(s2);
  uint32_t h2 = hash2(s2);
  for (int i = 0; i < k_hashes; ++i) {
    size_t hi = (h1 + i*h2) % m_size;
    bits[hi] = true;
  }
}

bool DoubleHashingBF::contains(const string s) const {
  bool present = true;
  string s2 = preHashKey(s);
  uint32_t h1 = hash1(s2);
  uint32_t h2 = hash2(s2);
  for (int i = 0; present and i < k_hashes; ++i) {
    size_t hi = (h1 + i*h2) % m_size;
    present = bits[hi];
  }
  return present;
}