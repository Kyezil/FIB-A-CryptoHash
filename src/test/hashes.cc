#include <iostream>
#include "sha256.h"
#include "fnv1a.h"
#include "murmur3.h"
#include "jenkins1.h"
using namespace std;

int main() {
  string s;
  while (cin >> s) {
    cout << "sha256  \t" << sha256(s) << endl;
    cout << "fnv1a   \t" << fnv1a(s) << endl;
    cout << "murmur3 \t" << murmur3(s) << endl;
    cout << "jenkins1\t" << jenkins1(s) << endl;
  }
}