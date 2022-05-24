#pragma once

#include <vector>

typedef struct
{
	int data; // vertex
	int key; // weight
} Pair;

class Heap
{
protected:
	std::vector<Pair*> heapVec; // Points to data array
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);

public:
	std::vector<Pair*> GetHeapVec() { return heapVec; }
	int GetHeapVecSize() { return (int)heapVec.size(); }
	void Swap(int i, int j);
};