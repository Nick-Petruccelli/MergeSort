#include <iostream>
#include <cstdlib>
#include "../inc/node.hpp"

const int LEFT = 0;
const int RIGHT = 1;

void init_array(int *arr, int count){
	for(int i=0; i<count; i++){
		arr[i] = rand();
	}
}

int *merge_sort(int *arr, int count){
	Node init;
	init.arr = arr;
	init.start = 0;
	init.end = count-1;
	return init.merge();
}

int main(int argc, char* args[]){
	int num_count = 10;
	if(argc != 0){
		num_count = atoi(args[0]);
	}

	int *arr = (int*)malloc(num_count*sizeof(int));
	init_array(arr, num_count);
	int *sorted_arr = merge_sort(arr, num_count);
	for(int i=0; i<num_count; i++){
		std::cout << sorted_arr[i] << std::endl;
	}

	return 0;
}
