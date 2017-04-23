#include "RandomDataGenerator.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

int main() {
    vector<unsigned int> ks = {5,2};
    RandomDataGenerator dg("test", 3, ks);
    string s;
    ifstream keys_stream;
    dg.getKeys(keys_stream);
    cout << "KEYS: \n";
    while (keys_stream >> s) {
        cout << s << endl;
    }
    cout << "Ks: \n";
    for (unsigned int i = 0; i < dg.size(); ++i) {
        cout << "\tK " << i << endl;
        string s;
        ifstream test_stream; 
        dg.getTest(i, test_stream);
        while (test_stream >> s) {
            cout << s << endl;
        }
        cout << endl;        
    }
}