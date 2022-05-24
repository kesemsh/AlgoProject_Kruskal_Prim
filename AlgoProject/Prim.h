#pragma once

#include "Graph.h"
#include "MinHeap.h"
#define NO_PARENT -1

class Prim
{
protected:
	int* MSTParentArr;
	int MSTweight = 0;

public:
	Prim(int n) { MSTParentArr = new int[n]; }
	~Prim();
	void PrimFunc(Graph& G);
	int* getParentArr() { return MSTParentArr; }
	int GetMSTweight() { return MSTweight; }
	void CalcPrimMSTweight(int* minWeightArr, int& size);
};

