#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>

#include "RandomDataGenerator.h"
#include "RandomString.h"
using std::string;

RandomDataGenerator::RandomDataGenerator(string experimentFolder, unsigned int n, const vector<unsigned int> &t) {
	t_tests = t.size();
	folder = dataFolder + "/" + experimentFolder;
	mkdir(folder.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	RandomString rs;

  ofstream exp_file;
  exp_file.open(folder + "/keys.txt");
  for (unsigned int i = 0; i < n; ++i)
  		exp_file << rs.generate(10) << endl;
  exp_file.close();

  for (unsigned int i = 0; i < t.size(); ++i) {
		exp_file.open(folder + "/test_" + to_string(i) + ".txt");
		for (unsigned int i = 0; i < n; ++i)
  		exp_file << rs.generate(10) << endl;
		exp_file.close();
  }
}

void RandomDataGenerator::getKeys(ifstream &keys) {
  keys.open(folder + "/keys.txt");
}

void RandomDataGenerator::getTest(unsigned int t, ifstream &test) {
	test.open(folder + "/test_" + to_string(t) + ".txt");
}

unsigned int RandomDataGenerator::size() const {
	return t_tests;
}