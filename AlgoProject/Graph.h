#pragma once

#include <iostream>
#define inf INT32_MAX
#define WHITE 0
#define GRAY 1

struct adjNode {
    int vertex, cost;
    adjNode* next;
};

struct Edge {
    int start_ver, end_ver, weight;
};

class Graph {
protected:
    int n; // number of vertexes
    int m; // number of edges
    adjNode** adjArr;
    Edge* edgesArr = nullptr;
    Edge edgeToRemove;

public:
    Graph(int n, int m);
    ~Graph();
    Edge* GetEdgesArr() { return edgesArr; }
    int GetNumOfVertexes() { return n; }
    int GetNumOfEdges() { return m; }
    Edge GetRemovedEdge() { return edgeToRemove; }
    adjNode** GetAdjArr() { return adjArr; }
    adjNode* GetAdjList(int u);
    void MakeEmptyGraph(int n, int m);
    bool IsAdjacent(int u, int v);
    void AddEdgeHelper(Edge& edge);
    void AddEdge(int u, int v, int weight);
    void RemoveEdgeHelper(Edge edge);
    void RemoveEdge(int u, int v);
    void RemoveFromAdjList(int u, adjNode** pCurr, adjNode* prev);
    void SetEdgeToRemove(Edge edge) { edgeToRemove = edge; }
    bool IsRemovedEdgeABridge();
    void DFS(int& numOfVertexesInDFST, int vertex);
    void Visit(int* colorArr, int& count, int vertex);
    void AddEdgeToEdgesArr(int u, int v, int w);
};