#include "RandomString.h"
#include <random>
#include <algorithm>
#include <string>
using namespace std;

const char RandomString::charset[] =
  "abcdefghijklmnopqrstuvwxyz"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "0123456789";

const size_t RandomString::max_index = sizeof(RandomString::charset) - 1;

RandomString::RandomString(int seed) :
    rand(seed), dis(0, max_index) {}

string RandomString::generate(size_t length) {
  string str(length,0);
  generate_n(str.begin(),length, [this]() -> char {
    return randomChar();
  });
  return str;
}
