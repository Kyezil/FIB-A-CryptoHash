#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// taken from http://stackoverflow.com/a/12468109/2645412
string random_string(size_t length ) {
  auto randchar = []() -> char {
    const char charset[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
    const size_t max_index = (sizeof(charset) - 1);
    return charset[ rand() % max_index ];
  };
  string str(length,0);
  generate_n( str.begin(), length, randchar );
  return str;
}

int main() {
  size_t d;
  while (cin >> d)
    cout << random_string(d) << endl;
}