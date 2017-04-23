#include "DataRandomGenerator.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> ks;
    ks.push_back(5);
    ks.push_back(2);
    DataGenerator dg = DataRandomGenerator("test", 3, ks);
    string s;
    istream keys = dg.getKeys();
    cout << "KEYS: \n";
    while (keys >> s) {
        cout << s << endl;
    }
    cout << "Ks: \n";
    for (int i = 0; i < dg.size(); ++i) {
        cout << "\tK " << i << endl;
        string s;
        istream test = dg.getTest(i);
        while (test >> s) {
            cout << s << endl;
        }
        cout << endl;        
    }
}