#include "fit.hpp"

#include <iostream>
#include <list>
#include <vector>
#include <string>

#include "stdio.h"

using namespace std;

void Fit::merge_list(list<Node> &list) {
  if (list.empty())
    return;
  auto it = list.begin();
  ++it;
  while (it != list.end()) {
    auto prev = --it;
    ++it;
    if (prev->end + 1 == it->start) {
      // delete
      prev->end += it->size;
      prev->size += it->size;
      list.erase(it);
      it = prev;
    } else {
      ++it;
    }
  }
}

Fit::Fit(int memory_size) : memory_size(memory_size) {
  Node node(0, memory_size - 1, -1);
  empty_list.push_back(node);
}

void Fit::print_node(Node node, bool is_empty, vector<string> &res) {
  for (int i = node.start; i <= node.end; ++i) {
    if (is_empty) {
      char buff[100];
      snprintf(buff, sizeof(buff), "|%.2d   |", i);
      string s = buff;
      res.push_back(s);
    } else {
      char buff[100];
      snprintf(buff, sizeof(buff), "|%.2d \033[1;32m%.2d\033[0m|", i, node.id);
      string s = buff;
      res.push_back(s);
    }
  }
}

vector<string> Fit::print_lists() {
  vector<string> res;
  auto it1 = empty_list.begin();
  auto it2 = filled_list.begin();

  while (it1 != empty_list.end() && it2 != filled_list.end()) {
    if (it1->start < it2->start) {
      print_node(*it1, true, res);
      ++it1;
    } else {
      print_node(*it2, false, res);
      ++it2;
    }
  }

  while (it1 != empty_list.end()) {
    print_node(*it1, true, res);
    ++it1;
  }

  while (it2 != filled_list.end()) {
    print_node(*it2, false, res);
    ++it2;
  }
  return res;
}

bool Fit::remove(int pid) {
  if (processes_ids.find(pid) == processes_ids.end()) {
    return false;
  }
  processes_ids.erase(pid);
  auto it = filled_list.begin();
  while (it != filled_list.end() && it->id != pid) {
    ++it;
  }

  int start = it->start;
  int size = it->size;
  int end = it->end;

  filled_list.erase(it);

  Node empty_node(start, end, -1);

  it = empty_list.begin();
  while (it != empty_list.end() && it->start <= start) {
    ++it;
  }
  empty_list.insert(it, empty_node);
  merge_list(empty_list);
  return true;
}
