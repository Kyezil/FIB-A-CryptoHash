#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

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
  minstd_rand rand;
  uniform_int_distribution<> dis;
  inline char randomChar() {
    return charset[dis(rand)];
  }
};

const char RandomString::charset[] =
  "abcdefghijklmnopqrstuvwxyz"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "0123456789";
const size_t RandomString::max_index = sizeof(RandomString::charset) - 1;

int main() {
  RandomString rs;
  size_t d;
  while (cin >> d)
    cout << rs.generate(d) << endl;
}