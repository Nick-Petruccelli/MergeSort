#pragma once

class Node {
public:
  int *arr;
  int start;
  int end;
  Node *left;
  Node *right;

  int *merge_sort();
  int *merge();
  void split();
};
