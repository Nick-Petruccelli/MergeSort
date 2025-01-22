#include "../inc/node.hpp"
#include <cstdlib>

void Node::split(){
	if(start == end)
		return;

	left->arr = arr;
	left->arr = arr;

	left->start = start;
	left->end = start + (end - start)/2;
	right->start = left->end + 1;
	right->end = end;
	left->split();
	right->split();
}

int* Node::merge(){
	if(start == end){
		int *out = (int*)malloc(sizeof(int));
		out[0] = start;
		return out;
	}
	int new_size = right->end - left->start + 1;
	int *out = (int*)malloc(new_size * sizeof(int));
	int *arr_l = left->merge();
	int *arr_r = right->merge();
	int l = left->start;
	int r = right->start;
	int i = 0;
	while(i < new_size){
		if(arr_l[l] < arr_r[r]){
			out[i] = arr_l[l];
			l++;
		}else{
			out[i] = arr_r[r];
			r++;
		}
		i++;
	}
	return out;
}
