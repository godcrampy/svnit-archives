#include "first-fit.hpp"

bool FirstFit::append(int process_size, int pid) {
  // returns true if new_node could be inserted
  processes_ids.insert(pid);
  for (auto i = empty_list.begin(); i != empty_list.end(); ++i) {
    if (i->size >= process_size) {
      // fill here
      // find process after it
      int empty_node_end = i->end;
      int empty_node_start = i->start;
      auto filled_node = filled_list.begin();
      while (filled_node != filled_list.end() &&
             filled_node->end <= empty_node_end) {
        ++filled_node;
      }
      Node process(empty_node_start, empty_node_start + process_size - 1, pid);
      filled_list.insert(filled_node, process);
      i->start += process_size;
      i->size -= process_size;
      if (i->size == 0) {
        empty_list.erase(i);
      }
      return true;
    }
  }

  return false;
}
