#ifndef __TIMER_H__
#define __TIMER_H__
#include <chrono>
using std::chrono::time_point;
using std::chrono::high_resolution_clock;

class Timer {
public:
  // reset timer
  void start();
  // time elapsed since start in seconds
  double step();
private:
  time_point<high_resolution_clock> tp;
};

#endif