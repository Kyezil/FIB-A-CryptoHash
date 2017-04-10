#include <iostream>
#include <bitset>
#include "BloomFilter.h"
#include "sha256.h"
using namespace std;

int main() {
  
  size_t m, k;
  cout << "give m and k :" << endl;
  cin >> m >> k;
  BloomFilter BF(m,k);
  cout << "insert (+) or contains (?), (q) to quit" << endl;
  char op;
  string input;
  while (cin >> op && op != 'q') {
    cin >> input;
    if (op == '+') BF.insert(input);
    else if (op == '?')
      cout << (BF.contains(input) ? "maybe in" : "not in") << endl;
    else
      cout << "wrong command" << endl;
  }
}