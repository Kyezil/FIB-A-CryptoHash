#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include "DataGenerator.h"
using std::string;

DataGenerator::DataGenerator(string experimentFolder, unsigned int n, vector<unsigned int> &t) {
	DataGenerator::dataFolder = "data/" + experimentFolder;
	mkdir(dataFolder.c_str(), S_IRUSR | S_IWUSR);

  ofstream exp_file;
  exp_file.open("./" + DataGenerator::dataFolder + "/keys.txt");
  for (unsigned int i = 0; i < n; ++i) {
  		//exp_file << "" << endl;
  }
  exp_file.close();

  for (unsigned int i = 0; i < t.size(); ++i) {
		exp_file.open("./" + DataGenerator::dataFolder + "/test_" + i + ".txt");
		//exp_file << "";
		exp_file.close();
  }
}

istream DataGenerator::getKeys() {
  ifstream keys_file;
  keys_file.open("./" + DataGenerator::dataFolder + "/keys.txt");
  return keys_file;
}

istream DataGenerator::getTest() {
  return "Empty experiment to be used as structure";
}