#include <string>
#include <iostream>
#include "BloomFilter.h"
#include "Exp1.h"

#include <random>
#include <algorithm>
using std::string;

class RandomString {
public:
  static const char charset[];
  static const size_t max_index;
  
  RandomString(int seed = 42) :
    rand(seed), dis(0, max_index) {}
  
  string generate(size_t length) {
    string str(length,0);
    generate_n(str.begin(),length, [this]() -> char {
      return randomChar();
    });
    return str;
  }
  
private:
  std::minstd_rand rand;
  std::uniform_int_distribution<> dis;
  inline char randomChar() {
    return charset[dis(rand)];
  }
};

const char RandomString::charset[] =
  "abcdefghijklmnopqrstuvwxyz"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "0123456789";
const size_t RandomString::max_index = sizeof(RandomString::charset) - 1;


Exp1::Exp1(string ex) {
  exampleParam = ex;
}

void Exp1::execute() {
  std::cout << "My param is " << exampleParam << "i no controlo el temps" << std::endl;

  vector<string> conjunt(100);
  size_t m = 40, k = 1;
  res.m = m;
  res.k = k;
  RandomString rs;
  BloomFilter BF(m,k);
  for (int i = 0; i < 40; ++i) {
    string ss = rs.generate(15);
    //BF.insert("CARACOL" + std::to_string(i)); // random string (o no tan random)
    BF.insert(ss);
    if (i%4 == 0) {                // deu hi hauran de ser segur
      conjunt[i] = ss;
    }
  }
  for (int i = 0; i < 100; ++i) {
    if (not (i%4 == 0 and i < 40)) {
      conjunt[i] = rs.generate(15);
    }
  }
  int found = 0;
  for (int i = 0; i < 100; ++i) { 
    if (BF.contains(conjunt[i])) ++found;
  }
  res.false_positive_ratio = found-10; // en teoria n'hi ha de haber exactament 10 per construccio
  res.n = 100;
  std::cout << "Paraules trobades al BF: " << found << " de 100 buscades, 40 inserides i nomes 10 de les inserides en el conjunt de les buscades" << std::endl;
}

Experiment::Result Exp1::getResult() {
  return res;
}

// short description of the experiment
string Exp1::getDescription() {
  return "Experiment try 1, un sol hash ja que m/n * 0,7 no arriba a 1";
}
