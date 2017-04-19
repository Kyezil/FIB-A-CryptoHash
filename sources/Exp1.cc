#include <string>
#include <iostream>
#include "BloomFilter.h"
#include "Exp1.h"
using std::string;

Exp1::Exp1(string ex) {
  exampleParam = ex;
}

void Exp1::execute() {
  std::cout << "My param is " << exampleParam << "i no controlo el temps" << std::endl;

  vector<string> conjunt(100);
  size_t m = 40, k = 1;
  res.m = m;
  res.k = k;
  BloomFilter BF(m,k);
  for (int i = 0; i < 40; ++i) {
    BF.insert("CARACOL" + std::to_string(i)); // random string (o no tan random)
    if (i%4 == 0) {                // deu hi hauran de ser segur
      conjunt[i] = "CARACOL" + std::to_string(i);
    }
  }
  /*for (int i = 0; i < 100; ++i) {
    if (not (i%4 == 0 and i < 40)) {
      string input;
      //generate, com podem fer servir la classe que has creat de generacio aleatoria de coses?
      conjunt[i] = input;
    }
  }*/
  int found = 0;
  for (int i = 0; i < 100; ++i) { // paraules del conjunt quan estigui el conjunt ple
    if (i%4 == 0 and i < 40) {
      if (BF.contains(conjunt[i])) ++found;

    }
    else if (BF.contains("BANANAS" + std::to_string(i))) ++found;
  }
  res.false_positive_ratio = found-10; // en teoria n'hi ha de haber exactament 10 per construccio
  res.n = 100;
  std::cout << "Paraules trobades al BF: " << found << " de 100 buscades, 40 inserides i nomes 10 de les inserides en el conjunt d eles buscades :(" << std::endl;
}

Experiment::Result Exp1::getResult() {
  return res;
}

// short description of the experiment
string Exp1::getDescription() {
  return "Experiment try 1, funciona millor amb un unic hash que amb mes d un";
}
