#include "RandomDataGenerator.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    vector<unsigned int> ks;
    ks.push_back(5);
    ks.push_back(2);
    RandomDataGenerator rdg = RandomDataGenerator("test", 3, ks);
    string s;
    ifstream keys_stream;
    rdg.getKeys(keys_stream);
    cout << "KEYS: \n";
    while (keys_stream >> s) {
        cout << s << endl;
    }
    cout << "Ks: \n";
    for (unsigned int i = 0; i < rdg.size(); ++i) {
        cout << "\tK " << i << endl;
        string s;
        ifstream test_stream; 
        rdg.getTest(i, test_stream);
        while (test_stream >> s) {
            cout << s << endl;
        }
        cout << endl;        
    }
}