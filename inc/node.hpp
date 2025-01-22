#pragma once

class Node{
public:
	int *arr;
	int start;
	int end;
	Node *left;
	Node *right;

	int *merge();
	void split();
};
