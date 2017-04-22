#ifndef __FNV1A_H__
#define __FNV1A_H__
#include <cstdint>
#include <string>
using std::string;
// Fowler-Noll-Vo Hash FNV1a

// 32 bytes version
static const uint32_t PRIME_32 = 0x01000193; //   16777619
static const uint32_t OFFSET_32  = 0x811C9DC5; // 2166136261
static const uint64_t PRIME_64 = 0x100000001b3; //   1099511628211
static const uint64_t OFFSET_64  = 0xcbf29ce484222325; // 14695981039346656037

// fnv1a hash to 32 bits
uint32_t fnv1a_32(const string s);
// fnv1a hash to 64 bits
uint64_t fnv1a_64(const string s);

#endif