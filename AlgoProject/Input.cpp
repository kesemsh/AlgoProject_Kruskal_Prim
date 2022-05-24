#include "Input.h"

int getValidNumber(ifstream& infile, ofstream& outfile)
{
	string line;
	getline(infile, line);
	istringstream iss(line);
	int num;

	// if there's more/less then one input or that number is not positive
	if (!(iss >> num) || num <= 0) 
	{
		wrongInput(outfile);
	}

	if (!iss.eof())
	{
		wrongInput(outfile);
	}

	return num;
}

void getEdges(Graph& graph, ifstream& infile, ofstream& outfile)
{
	string line, weightSrt;
	int start, end;
	int n = graph.GetNumOfVertexes(), m = graph.GetNumOfEdges();

	for (int i = 0; i < m && infile.peek() != EOF; ++i)
	{
		getline(infile, line);
		istringstream iss(line);

		// if there're more/less then 3 inputs or the start and end vertexes are not in range [0,n-1] or there're self loops
		if (!(iss >> start >> end >> weightSrt) || start <= 0 || end <= 0 || start > n | end > n || start == end)
		{
			wrongInput(outfile);
		}

		if (!iss.eof())
		{
			wrongInput(outfile);
		}

		int weight = getValidWeight(weightSrt, outfile);

		Edge currEdge;
		currEdge.start_ver = start - 1;
		currEdge.end_ver = end - 1;
		currEdge.weight = weight;

		graph.AddEdgeHelper(currEdge); // add edge to graph
		graph.AddEdgeToEdgesArr(currEdge.start_ver, currEdge.end_ver, currEdge.weight); // add edge to edges array for kruskal
	}

	// if there's no input of edge to be removed
	if (infile.peek() == EOF) 
	{
		wrongInput(outfile);
	}
}

int getValidWeight(string weight, ofstream& outfile)
{
	int res;

	// if the weight number isn't whole
	if (weight.find('.', sizeof(char)) != string::npos) 
	{
		wrongInput(outfile);
	}

	stringstream str;
	str << weight;
	str >> res;

	return res;
}

void getEdgeToRemove(Graph& graph, ifstream& infile, ofstream& outfile)
{
	string line;
	getline(infile, line);
	istringstream iss(line);
	int start, end;
	int n = graph.GetNumOfVertexes();

	// if there're more/less then 2 inputs or the start and end vertexes are not in range [0,n-1] or there're self loops
	if (!(iss >> start >> end) || start <= 0 || end <= 0 || start > n | end > n || start == end)
	{
		wrongInput(outfile);
	}

	if (!iss.eof())
	{
		wrongInput(outfile);
	}

	Edge edgeToRemove;
	edgeToRemove.start_ver = start - 1;
	edgeToRemove.end_ver = end - 1;

	// if the edge to be removed is in the graph
	if (graph.IsAdjacent(edgeToRemove.start_ver, edgeToRemove.end_ver))
	{
		graph.SetEdgeToRemove(edgeToRemove);
	}
	else
	{
		wrongInput(outfile); // if it's not in the graph
	}
}

void wrongInput(ofstream& outfile)
{
	cout << "input invalid" << endl;
	outfile << "input invalid";
	exit(1);
}

void printNoMST(ofstream& outfile)
{
	cout << "no MST" << endl;
	outfile << "no MST";
	exit(0);
}