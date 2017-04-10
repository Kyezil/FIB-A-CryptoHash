#include <iostream>
#include "sha256.h"
using namespace std;

 
int main() {
	string input;
	cin >> input;
    string output = sha256(input);
    cout << input << " hashed in sha256 is " << output << endl;
}