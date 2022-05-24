#include "Graph.h"

Graph::Graph(int n, int m)
{
    this->n = n;
    this->m = m;

    MakeEmptyGraph(n, m);
}

Graph::~Graph()
{
    for (int i = 0; i < n; i++)
        delete adjArr[i];

    delete[] adjArr;
    delete[] edgesArr;
}

void Graph::MakeEmptyGraph(int n, int m)
{
    adjArr = new adjNode * [n]();

    for (int i = 0; i < n; ++i)
        adjArr[i] = nullptr;

    edgesArr = new Edge[m];
}

bool Graph::IsAdjacent(int u, int v)
{
    adjNode* uAdjCurr = GetAdjList(u);

    while (uAdjCurr != nullptr)
    {
        if (uAdjCurr->vertex == v)
            return true;
        uAdjCurr = uAdjCurr->next;
    }

    return false;
}

adjNode* Graph::GetAdjList(int vertex)
{
    return adjArr[vertex];
}

void Graph::AddEdgeHelper(Edge& edge)
{
    AddEdge(edge.start_ver, edge.end_ver, edge.weight);
    AddEdge(edge.end_ver, edge.start_ver, edge.weight);
}

void Graph::AddEdge(int u, int v, int weight)
{
    adjNode* newNode = new adjNode;

    newNode->vertex = v;
    newNode->cost = weight;
    newNode->next = adjArr[u];
    adjArr[u] = newNode;
}

void Graph::RemoveEdgeHelper(Edge edge)
{
    RemoveEdge(edge.start_ver, edge.end_ver);
    RemoveEdge(edge.end_ver, edge.start_ver);

    m -= 1;
}

void Graph::RemoveEdge(int u, int v)
{
    if (!IsAdjacent(u, v))
        return;

    adjNode* prev = nullptr;
    adjNode* curr = adjArr[u];

    while (curr != nullptr)
    {
        if (curr->vertex == v)
        {
            RemoveFromAdjList(u, &curr, prev);
            break;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

void Graph::RemoveFromAdjList(int u, adjNode** pCurr, adjNode* prev)
{
    adjNode* toDelete = *pCurr;

    if (adjArr[u] == toDelete)
    {
        adjArr[u] = adjArr[u]->next;
        *pCurr = nullptr;
    }
    else if (toDelete->next == nullptr)
    {
        prev->next = nullptr;
        *pCurr = nullptr;
    }
    else
    {
        prev->next = toDelete->next;
    }

    delete toDelete;
}

bool Graph::IsRemovedEdgeABridge()
{
    bool isBridge = true;
    int numOfVertexesInDFST = 0;

    DFS(numOfVertexesInDFST, edgeToRemove.start_ver);

    if (numOfVertexesInDFST == n)
        isBridge = false;

    return isBridge;
}

void Graph::DFS(int& numOfVertexesInDFST, int vertex)
{
    int* colorArr = new int[n];

    for (int i = 0; i < n; i++)
    {
        colorArr[i] = WHITE;
    }

    numOfVertexesInDFST += 1; // count the root edgeToRemove.start_ver
    Visit(colorArr, numOfVertexesInDFST, vertex);
}

void Graph::Visit(int* colorArr, int& count, int vertex)
{
    adjNode* currV = adjArr[vertex];
    colorArr[vertex] = GRAY;

    while (currV != nullptr)
    {
        if (colorArr[currV->vertex] == WHITE)
        {
            count++;
            Visit(colorArr, count, currV->vertex);
        }
        currV = currV->next;
    }
}

void Graph::AddEdgeToEdgesArr(int u, int v, int w)
{
    static int i = 0;

    Edge newEdge;
    newEdge.start_ver = u;
    newEdge.end_ver = v;
    newEdge.weight = w;

    edgesArr[i] = newEdge;
    i++;
}
