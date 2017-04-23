#include "DataGenerator.h"
#include <sys/types.h>
#include <sys/stat.h>

const string DataGenerator::dataFolder = "data";

DataGenerator::DataGenerator() {
  // create dataFolder if inexistent
  mkdir(dataFolder, S_IRUSR | S_IWUSR);
}