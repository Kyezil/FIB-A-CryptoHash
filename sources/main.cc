#include <iostream>
#include <bitset>
#include "BloomFilter.h"
#include "sha256.h"
using namespace std;

int main() {
  BloomFilter BF(10,1);
  string input;
  cout << "insert in bloom filter (0 to end): " << endl;
  while (cin >> input and input != "0") BF.insert(input);
  cout << "check contains (0 to end): " << endl;
  while (cin >> input and input != "0")
    cout << (BF.contains(input) ? "maybe in" : "not in") << endl;
}