#include "fnv1a.h"

uint32_t fnv1a_32(const string s) {
  uint32_t hash = OFFSET_32;
  for (int i = 0; i < s.size(); ++i) {
    hash ^= s[i];
    hash *= PRIME_32;
  }
  return hash;
}

uint64_t fnv1a_64(const string s) {
  uint64_t hash = OFFSET_64;
  for (int i = 0; i < s.size(); ++i) {
    hash ^= s[i];
    hash *= PRIME_64;
  }
  return hash;
}
