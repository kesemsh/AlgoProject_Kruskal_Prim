#pragma once

#include "EdgesList.h"
#include "DisjointSets.h"

class Kruskal
{
protected:
	std::vector<Edge> MSTedgesVec;
	int MSTweight = 0;
	EdgesList edgesList;

public:
	void KruskalFunc(Graph& G);
	void EdgesArrToList(Edge* edgesArr, int& size);
	void QuickSort(Edge* edgesArr, int start, int end);
	int Partition(Edge* edgesArr, int& start, int& end);
	void SwapEdges(Edge& e1, Edge& e2);
	void CalcKruskalMSTweight();
	int GetMSTweight() { return MSTweight; }
	void removeEdgeFromList(Edge edge);
	bool IsEdgeInMST(Edge edge);
};