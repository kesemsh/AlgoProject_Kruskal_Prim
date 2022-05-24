#include "Prim.h"

Prim::~Prim()
{
	delete[] MSTParentArr;
}

void Prim::PrimFunc(Graph& G)
{
	int n = G.GetNumOfVertexes();
	Pair* u;
	adjNode* currV;
	MinHeap Q(n);
	bool* isInMSTArr = new bool[n]();
	int* minWeightArr = new int[n];

	minWeightArr[0] = 0;
	MSTParentArr[0] = NO_PARENT;

	for (int i = 1; i < n; i++)
	{
		minWeightArr[i] = inf;
		MSTParentArr[i] = NO_PARENT;
	}

	Q.Build(n, minWeightArr);

	while (Q.GetHeapVecSize() != 0)
	{
		u = Q.DeleteMin();
		isInMSTArr[u->data] = true;
		currV = G.GetAdjList(u->data);

		while (currV != nullptr)
		{
			if (isInMSTArr[currV->vertex] == false && currV->cost < minWeightArr[currV->vertex])
			{
				minWeightArr[currV->vertex] = currV->cost;
				MSTParentArr[currV->vertex] = u->data;
				Q.DecreaseKey(currV->vertex, minWeightArr[currV->vertex]);
			}
			currV = currV->next;
		}
	}

	CalcPrimMSTweight(minWeightArr, n);

	delete[] isInMSTArr;
	delete[] minWeightArr;
}

void Prim::CalcPrimMSTweight(int* minWeightArr, int& size)
{
	for (int i = 0; i < size; i++)
	{
		MSTweight += minWeightArr[i];
	}
}