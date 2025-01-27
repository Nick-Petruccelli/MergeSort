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

int *merge_sort_split_merge(int *arr, int count) {
  Node init;
  init.arr = arr;
  init.start = 0;
  init.end = count - 1;
  init.split();
  return init.merge();
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
  int *sorted_arr = merge_sort_split_merge(arr, num_count);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << "Split And Merge" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << "Start: " << start << std::endl;
  std::cout << "End: " << end << std::endl;
  std::cout << "Time: " << cpu_time_used << std::endl;
  start = clock();

  int *sorted_arr_2 = merge_sort(arr, num_count);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << "Wambo Combo" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << "Start: " << start << std::endl;
  std::cout << "End: " << end << std::endl;
  std::cout << "Time: " << cpu_time_used << std::endl;

  return 0;
}
