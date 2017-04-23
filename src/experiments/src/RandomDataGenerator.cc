#include <string>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include "RandomDataGenerator.h"
using std::string;

RandomDataGenerator::RandomDataGenerator(string experimentFolder, unsigned int n, const vector<unsigned int> &t) {
	RandomDataGenerator::t_tests = t.size();
	RandomDataGenerator::dataFolder += experimentFolder;
	mkdir(dataFolder.c_str(), S_IRUSR | S_IWUSR);

  ofstream exp_file;
  exp_file.open(RandomDataGenerator::dataFolder + "/keys.txt");
  for (unsigned int i = 0; i < n; ++i) {
  		//exp_file << "" << endl;
  }
  exp_file.close();

  for (unsigned int i = 0; i < t.size(); ++i) {
		exp_file.open(RandomDataGenerator::dataFolder + "/test_" + to_string(i) + ".txt");
		//exp_file << "";
		exp_file.close();
  }
}

void RandomDataGenerator::getKeys(ifstream &keys) {
  keys.open(RandomDataGenerator::dataFolder + "/keys.txt");
}

void RandomDataGenerator::getTest(unsigned int t, ifstream &test) {
	test.open(RandomDataGenerator::dataFolder + "/test_" + to_string(t) + ".txt");
}

unsigned int RandomDataGenerator::size() const {
	return RandomDataGenerator::t_tests;
}