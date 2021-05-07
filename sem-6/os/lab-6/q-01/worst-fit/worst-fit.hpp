#include <list>

#include "../fit/fit.hpp"
#include "../node/node.hpp"
#pragma once
using namespace std;

class WorstFit : public Fit {
 public:
  using Fit::Fit;
  bool append(int process_size, int pid);
};
