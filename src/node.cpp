#include "../inc/node.hpp"
#include <cstdlib>
#include <iostream>

int *Node::merge_sort() {
  if (start == end) {
    int *out = (int *)malloc(sizeof(int));
    out[0] = arr[start];
    return out;
  }

  left = new Node();
  right = new Node();
  left->arr = arr;
  right->arr = arr;

  left->start = start;
  left->end = start + (end - start) / 2;
  right->start = left->end + 1;
  right->end = end;
  int new_size = right->end - left->start + 1;
  int *out = (int *)malloc(new_size * sizeof(int));
  int *arr_l = left->merge_sort();
  int *arr_r = right->merge_sort();
  int l = 0;
  int r = 0;
  for (int i = 0; i < new_size; i++) {
    if (l > left->end - left->start) {
      out[i] = arr_r[r];
      r++;
      continue;
    }
    if (r > right->end - right->start) {
      out[i] = arr_l[l];
      l++;
      continue;
    }
    if (arr_l[l] < arr_r[r]) {
      out[i] = arr_l[l];
      l++;
    } else {
      out[i] = arr_r[r];
      r++;
    }
  }
  free(arr_l);
  free(arr_r);

  return out;
}

void Node::split() {
  if (start == end) {
    return;
  }

  left = new Node();
  right = new Node();
  left->arr = arr;
  right->arr = arr;

  left->start = start;
  left->end = start + (end - start) / 2;
  right->start = left->end + 1;
  right->end = end;
  left->split();
  right->split();
}

int *Node::merge() {
  if (start == end) {
    int *out = (int *)malloc(sizeof(int));
    out[0] = arr[start];
    return out;
  }
  int new_size = right->end - left->start + 1;
  int *out = (int *)malloc(new_size * sizeof(int));
  int *arr_l = left->merge();
  int *arr_r = right->merge();
  int l = 0;
  int r = 0;
  for (int i = 0; i < new_size; i++) {
    if (l > left->end - left->start) {
      out[i] = arr_r[r];
      r++;
      continue;
    }
    if (r > right->end - right->start) {
      out[i] = arr_l[l];
      l++;
      continue;
    }
    if (arr_l[l] < arr_r[r]) {
      out[i] = arr_l[l];
      l++;
    } else {
      out[i] = arr_r[r];
      r++;
    }
  }
  free(arr_l);
  free(arr_r);
  return out;
}
