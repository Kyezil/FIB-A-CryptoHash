#include "jenkins1.h"

uint32_t jenkins1(string s) {
  uint32_t hash = 0;
  for (int i = 0; i < s.size(); ++i) {
      hash += s[i];
      hash += hash << 10;
      hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  return hash;
}
