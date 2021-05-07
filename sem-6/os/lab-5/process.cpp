#include "process.hpp"
#include <iostream>

using namespace std;

Process::Process(int pid, int cpu_time, int arrival_time) {
  this->pid = pid;
  this->cpu_time = cpu_time;
  this->arrival_time = arrival_time;
}

bool Process::operator<(const Process &rhs) const {
  if (this->arrival_time == rhs.arrival_time)
    return this->cpu_time < rhs.cpu_time;
  return this->arrival_time < rhs.arrival_time;
}

void print_process(const Process &p) {
  cout << "P" << p.pid << ": { AT = " << p.arrival_time
       << ", BT = " << p.cpu_time << "}\n";
}
