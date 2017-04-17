#include "Timer.h"
#include <chrono>
using std::chrono::time_point;
using std::chrono::high_resolution_clock;

void Timer::start() {
  tp = high_resolution_clock::now(); 
}

double Timer::step() {
  time_point<high_resolution_clock> end = high_resolution_clock::now();
  return std::chrono::duration<double>(end - tp).count();
}
