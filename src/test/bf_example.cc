#include <iostream>
#include "BloomFilter.h"
using namespace std;

int main() {
  size_t m, k;
  cout << "give m and k :" << endl;
  cin >> m >> k;
  cout << "use sha256 ? (y/n)" << endl;
  char ch;
  cin >> ch;  
  BloomFilter BF(m,k, ch == 'y');
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
  return 0;
}