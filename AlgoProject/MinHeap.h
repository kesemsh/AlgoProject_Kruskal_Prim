#pragma once

#include <iostream>
#include "Heap.h"

class MinHeap : public Heap
{
	Pair** vertexHeapHelpArr;

public:
	MinHeap(int n);
	~MinHeap();
	void Build(int n, int* weightMin);
	Pair* DeleteMin();
	void FixHeap(int pair);
	void DecreaseKey(int v, int newMinWeight);
};