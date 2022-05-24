#pragma once

#include <vector>

typedef struct {
	int parent;
	int size;
} Element;

class DisjointSets
{
protected:
	std::vector<Element> DisjointSetsArr;

public:
	DisjointSets(int n);
	void MakeSet(int x);
	int Find(int x);
	void UnoinBySize(int repX, int repY);
};

