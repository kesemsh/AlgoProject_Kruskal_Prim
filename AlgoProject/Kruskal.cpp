#include "Kruskal.h"

void Kruskal::KruskalFunc(Graph& G)
{
	int u, v;
	int n = G.GetNumOfVertexes();
	int m = G.GetNumOfEdges();
	DisjointSets UF(n);

	if (edgesList.IsEmpty()) // first time we do Kruskal
	{
		QuickSort(G.GetEdgesArr(), 0, m - 1); // sort edges 
		EdgesArrToList(G.GetEdgesArr(), m);
	}

	else // else there's no need to sort edges again
	{
		removeEdgeFromList(G.GetRemovedEdge()); // remove edge from edges
		MSTedgesVec.clear();
	}
	

	for (int i = 0; i < n; i++)
	{
		UF.MakeSet(i);
	}

	Node* currEdge = edgesList.GetHead();

	while (currEdge != nullptr)
	{
		u = UF.Find(currEdge->edge.start_ver);
		v = UF.Find(currEdge->edge.end_ver);

		if (u != v)
		{
			MSTedgesVec.push_back(currEdge->edge);
			UF.UnoinBySize(u, v);
		}

		currEdge = currEdge->next;
	}

	CalcKruskalMSTweight();
}

void Kruskal::QuickSort(Edge* edgesArr, int start, int end)
{
	if (start >= end)
		return;

	// partitioning the array
	int p = Partition(edgesArr, start, end);

	// Sorting the left part
	QuickSort(edgesArr, start, p - 1);

	// Sorting the right part
	QuickSort(edgesArr, p + 1, end);
}

int Kruskal::Partition(Edge* edgesArr, int& start, int& end)
{
	int i, j, count = 0;
	int pivotIndex;
	int pivot = edgesArr[start].weight;

	for (int i = start + 1; i <= end; i++)
	{
		if (edgesArr[i].weight <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	pivotIndex = start + count;
	SwapEdges(edgesArr[pivotIndex], edgesArr[start]);

	// Sorting left and right parts of the pivot element
	i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (edgesArr[i].weight <= pivot)
		{
			i++;
		}

		while (edgesArr[j].weight > pivot)
		{
			j--;
		}

		if (i < pivotIndex && j > pivotIndex)
		{
			SwapEdges(edgesArr[i++], edgesArr[j--]);
		}
	}

	return pivotIndex;
}

void Kruskal::SwapEdges(Edge& e1, Edge& e2)
{
	Edge temp;

	temp = e1;
	e1 = e2;
	e2 = temp;
}

void Kruskal::CalcKruskalMSTweight()
{
	MSTweight = 0;

	for (int i = 0; i < (int)MSTedgesVec.size(); i++)
	{
		MSTweight += MSTedgesVec[i].weight;
	}
}

void Kruskal::EdgesArrToList(Edge* edgesArr, int& size)
{
	for (int i = 0; i < size; i++)
	{
		edgesList.InsertNode(edgesArr[i]);
	}
}

void Kruskal::removeEdgeFromList(Edge edge)
{
	bool wasRemoved = false;
	Node* prev = nullptr;
	Node* curr = edgesList.GetHead();

	while (curr != nullptr && wasRemoved == false)
	{
		if (curr->edge.start_ver == edge.start_ver && curr->edge.end_ver == edge.end_ver)
		{
			edgesList.DeleteNode(&curr, prev);
			wasRemoved = true;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

bool Kruskal::IsEdgeInMST(Edge edge)
{
	int u = edge.start_ver, v = edge.end_ver;

	for (int i = 0; i < (int)MSTedgesVec.size(); i++)
	{
		// if edge is in the MST
		if (MSTedgesVec[i].start_ver == u && MSTedgesVec[i].end_ver == v
			|| MSTedgesVec[i].start_ver == v && MSTedgesVec[i].end_ver == u)
		{
			return true;
		}
	}

	return false;
}