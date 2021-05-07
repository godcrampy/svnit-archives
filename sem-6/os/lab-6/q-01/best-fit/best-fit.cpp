#include "best-fit.hpp"

#include <limits.h>

bool BestFit::append(int process_size, int pid) {
  // returns true if new_node could be inserted
  list<Node>::iterator best_node_it = empty_list.begin();
  int best_node_size = INT_MAX;

  for (auto i = empty_list.begin(); i != empty_list.end(); ++i) {
    if (i->size <= best_node_size && i->size >= process_size) {
      best_node_size = i->size;
      best_node_it = i;
    }
  }

  if (best_node_size >= process_size && best_node_size != INT_MAX) {
    // fill here
    // find process after it
    int empty_node_end = best_node_it->end;
    int empty_node_start = best_node_it->start;
    auto filled_node = filled_list.begin();
    while (filled_node != filled_list.end() &&
           filled_node->end <= empty_node_end) {
      ++filled_node;
    }
    Node process(empty_node_start, empty_node_start + process_size - 1, pid);
    filled_list.insert(filled_node, process);
    best_node_it->start += process_size;
    best_node_it->size -= process_size;
    if (best_node_it->size == 0) {
      empty_list.erase(best_node_it);
    }
    processes_ids.insert(pid);
    return true;
  }

  return false;
}
