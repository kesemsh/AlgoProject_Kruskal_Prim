#pragma once

#include "Graph.h"

#include <fstream>
#include <sstream>

using namespace std;

int getValidNumber(ifstream& infile, ofstream& outfile);
void getEdges(Graph& graph, ifstream& infile, ofstream& outfile);
int getValidWeight(string weight, ofstream& outfile);
void getEdgeToRemove(Graph& graph, ifstream& infile, ofstream& outfile);
void wrongInput(ofstream& outfile);
void printNoMST(ofstream& outfile);