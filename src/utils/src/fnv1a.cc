#include "fnv1a.h"

uint32_t fnv1a(const string s) {
  uint32_t hash = OFFSET_32;
  for (int i = 0; i < s.size(); ++i) {
    hash ^= s[i];
    hash *= PRIME_32;
  }
  return hash;
}
