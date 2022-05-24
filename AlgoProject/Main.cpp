#pragma once

#include "Input.h"
#include "Prim.h"
#include "Kruskal.h"

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "No arguments" << endl;
		exit(1);
	}

	string inFileName = argv[1], outFileName = argv[2];
	ifstream infile;
	ofstream outfile;
	infile.open(inFileName);
	outfile.open(outFileName);

	int n = getValidNumber(infile, outfile);
	int m = getValidNumber(infile, outfile);

	Graph graph(n, m);
	getEdges(graph, infile, outfile);
	getEdgeToRemove(graph, infile, outfile);

	// check if the graph is connected
	int numberOfVertexesFound = 0;
	graph.DFS(numberOfVertexesFound, 0); // run DFS on the graph from vertex 0
	if (numberOfVertexesFound != n) // if DFS doesn't find all vertexes 
	{
		printNoMST(outfile); // then there's no MST
	}

	Kruskal k;
	k.KruskalFunc(graph);
	cout << "Kruskal <" << k.GetMSTweight() << ">" << endl;
	outfile << "Kruskal <" << k.GetMSTweight() << ">\n";

	Prim p(graph.GetNumOfVertexes());
	p.PrimFunc(graph);
	cout << "Prim <" << p.GetMSTweight() << ">" << endl;
	outfile << "Prim <" << p.GetMSTweight() << ">\n";

	if (k.IsEdgeInMST(graph.GetRemovedEdge())) // check if the edge to be removed was in the MST
	{
		graph.RemoveEdgeHelper(graph.GetRemovedEdge()); // remove edge from graph
		if (graph.IsRemovedEdgeABridge()) // if edge was a bridge in the graph
		{
			printNoMST(outfile); // then there's no MST
		}
		k.KruskalFunc(graph); // else find MST with kruskal
	}

	cout << "Kruskal <" << k.GetMSTweight() << ">" << endl;
	outfile << "Kruskal <" << k.GetMSTweight() << ">";

	infile.close();
	outfile.close();
}