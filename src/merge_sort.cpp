#include <iostream>
#include <cstdlib>
#include "../inc/node.hpp"

const int LEFT = 0;
const int RIGHT = 1;

void init_array(int *arr, int count){
	for(int i=0; i<count; i++){
		arr[i] = rand() % 10;
	}
}

int *merge_sort(int *arr, int count){
	Node init;
	init.arr = arr;
	init.start = 0;
	init.end = count-1;
	init.split();
	return init.merge();
}

int main(int argc, char* args[]){
	std::cout << "argc = " << argc <<std::endl;
	int num_count = 10;
	if(argc >  1){
		num_count = atoi(args[1]);
	}

	int *arr = (int*)malloc(num_count*sizeof(int));
	init_array(arr, num_count);
	std::cout << "INITIAL: " << std::endl;
	for(int i=0; i<num_count; i++){
		std::cout << arr[i] << std::endl;
	}
	int *sorted_arr = merge_sort(arr, num_count);
	std::cout << "SORTED: " << std::endl;
	for(int i=0; i<num_count; i++){
		std::cout << sorted_arr[i] << std::endl;
	}

	return 0;
}
