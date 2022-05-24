#include "DisjointSets.h"

DisjointSets::DisjointSets(int n)
{
	for (int i = 0; i < n; i++)
	{
		Element newElement;
		newElement.parent = -1;
		newElement.size = 0;
		DisjointSetsArr.push_back(newElement);
	}
}

// Make a new set with x as a representative
// Assumption: x does not belong to another set
void DisjointSets::MakeSet(int x)
{
	DisjointSetsArr[x].parent = x;
	DisjointSetsArr[x].size = 1;
}

// Return representative of the set to which x belong
// Use Path Compression
int DisjointSets::Find(int x)
{
	if (DisjointSetsArr[x].parent == x)
		return x;

	else
		return (DisjointSetsArr[x].parent = Find(DisjointSetsArr[x].parent));
}

// Assumption: repX, repY are the representatives of two disjoint sets.
// Use Unoin By Size
void DisjointSets::UnoinBySize(int repX, int repY)
{
	if (DisjointSetsArr[repX].size > DisjointSetsArr[repY].size)
	{
		DisjointSetsArr[repY].parent = repX;
		DisjointSetsArr[repX].size += DisjointSetsArr[repY].size;
	}

	else
	{
		DisjointSetsArr[repX].parent = repY;
		DisjointSetsArr[repY].size += DisjointSetsArr[repX].size;
	}
}