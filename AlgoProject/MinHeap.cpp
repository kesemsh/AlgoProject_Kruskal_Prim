#include "MinHeap.h"

MinHeap::MinHeap(int n)
{
	vertexHeapHelpArr = new Pair * [n];
}

MinHeap::~MinHeap()
{
	delete[] vertexHeapHelpArr;
}

// Build by Floyd
void MinHeap::Build(int n, int* weightMin)
{
	int i;

	for (i = 0; i < n; i++)
	{
		Pair* newPair = new Pair;
		newPair->data = i;
		newPair->key = weightMin[i];
		heapVec.push_back(newPair);
		vertexHeapHelpArr[i] = heapVec[i];
	}

	for (i = n / 2 - 1; i >= 0; i--)
	{
		FixHeap(i);
	}
}

// Delete maximum which is found in the root of heap, and fix heap
Pair* MinHeap::DeleteMin()
{
	if (heapVec.size() < 1)
	{
		std::cout << "wrong input" << std::endl;
		exit(1);
	}

	Pair* min = heapVec[0];
	heapVec[0] = heapVec[heapVec.size() - 1];
	vertexHeapHelpArr[heapVec[0]->data] = heapVec[heapVec.size() - 1]; 
	heapVec.resize(heapVec.size() - 1);
	FixHeap(0);

	return(min);
}

// Fixes the heap that has node as root
void MinHeap::FixHeap(int pair)
{
	int min;
	int left = Left(pair);
	int right = Right(pair);

	// Find maximum among node, left and right
	if ((left < (int)heapVec.size()) && (heapVec[left]->key < heapVec[pair]->key))
		min = left;

	else min = pair;

	if ((right < (int)heapVec.size()) && (heapVec[right]->key < heapVec[min]->key))
		min = right;

	// Swap values if necessary, and continue
	// fixing the heap
	if (min != pair)
	{
		Swap(pair, min);
		FixHeap(min);
	}
}

void MinHeap::DecreaseKey(int v, int newMinWeight)
{
	bool notInPlace = true;
	int vertexHeapIndex, vertexParentIndex;

	vertexHeapHelpArr[v]->key = newMinWeight;

	do
	{
		auto it = find(heapVec.begin(), heapVec.end(), vertexHeapHelpArr[v]);
		vertexHeapIndex = (int)(it - heapVec.begin());
		vertexParentIndex = Parent(vertexHeapIndex);
		
		if (heapVec[vertexHeapIndex]->key < heapVec[vertexParentIndex]->key)
		{
			Swap(vertexParentIndex, vertexHeapIndex);
			vertexHeapIndex = vertexParentIndex;
		}
		else
		{
			notInPlace = false;
		}

	} while (vertexHeapIndex != 0 && notInPlace); // if current vertex is the root or it's in the right place
}