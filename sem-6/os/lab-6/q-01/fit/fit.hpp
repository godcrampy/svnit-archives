#include <list>
#include <string>
#include <unordered_set>
#include <vector>

#include "../node/node.hpp"
#pragma once

using namespace std;

class Fit {
public:
  list<Node> empty_list;
  list<Node> filled_list;
  unordered_set<int> processes_ids;
  int memory_size;
  Fit(int memory_size);
  vector<string> print_lists();
  bool remove(int pid);
  virtual bool append(int process_size, int pid) = 0;

protected:
  void merge_list(list<Node> &list);
  void print_node(Node node, bool is_empty, vector<string> &res);
};
