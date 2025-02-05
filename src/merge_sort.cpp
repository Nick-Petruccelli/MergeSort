#include "../inc/node.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

const int LEFT = 0;
const int RIGHT = 1;

void init_array(int *arr, int count) {
  for (int i = 0; i < count; i++) {
    arr[i] = rand() % 10;
  }
}

int *merge_sort(int *arr, int count) {
  Node init;
  init.arr = arr;
  init.start = 0;
  init.end = count - 1;
  return init.merge_sort();
}

int main(int argc, char *args[]) {
  int num_count = 1000;
  if (argc > 1) {
    num_count = atoi(args[1]);
  }

  int *arr = (int *)malloc(num_count * sizeof(int));
  init_array(arr, num_count);
  int start, end;
  double cpu_time_used;
  start = clock();
  int *sorted_arr_2 = merge_sort(arr, num_count);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  std::cout << num_count << ", " << cpu_time_used << std::endl;

  return 0;
}
