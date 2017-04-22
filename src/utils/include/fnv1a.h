#ifndef __FNV1A_H__
#define __FNV1A_H__
#include <cstdint>
#include <string>
using std::string;
// Fowler-Noll-Vo Hash FNV1a

// 32 bytes version
static const uint32_t PRIME_32 = 0x01000193; //   16777619
static const uint32_t OFFSET_32  = 0x811C9DC5; // 2166136261

// fnv1a hash to 32 bits
uint32_t fnv1a(const string s);

#endif