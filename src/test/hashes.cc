#include <iostream>
#include "sha256.h"
#include "fnv1a.h"
using namespace std;

int main() {
  string s;
  while (cin >> s) {
    cout << "sha256  \t" << sha256(s) << endl;
    cout << "fnv1a_32\t" << fnv1a_32(s) << endl;
    cout << "fnv1a_64\t" << fnv1a_64(s) << endl;
  }
}