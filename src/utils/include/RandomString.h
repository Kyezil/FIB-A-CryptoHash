#ifndef __RANDOMSTRING_H__
#define __RANDOMSTRING_H__

#include <random>
#include <algorithm>
using namespace std;

class RandomString {
public:
  static const char charset[];
  static const size_t max_index;
  
  // construeix un generador de string aleatories
  // es determinista en funcio de seed
  RandomString(int seed = 42);
  
  // genera un string de mida length
  string generate(size_t length);

private:
  minstd_rand rand;
  uniform_int_distribution<> dis;
  inline char randomChar() {
    return charset[dis(rand)];
  }
};
#endif