#include "node.hpp"

Node::Node(int start, int end, int id)
    : start(start), end(end), size(end - start + 1), id(id) {}
