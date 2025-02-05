#pragma once

#include <cstddef>

class Node {
public:
  int *arr;
  std::size_t start;
  std::size_t end;
  Node *left;
  Node *right;

  int *merge_sort();
};
