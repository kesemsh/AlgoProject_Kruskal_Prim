#include "Heap.h"

// private member fanction of heap class
int Heap::Parent(int node)
{
	return (node - 1) / 2;
}

int Heap::Left(int node)
{
	return (2 * node + 1);
}

int Heap::Right(int node)
{
	return (2 * node + 2);
}

// A function to swap two elements
void Heap::Swap(int i, int j)
{
	Pair* temp = heapVec[i];
	heapVec[i] = heapVec[j];
	heapVec[j] = temp;
}