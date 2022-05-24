#pragma once

#include "Graph.h"

class Node {
public:
	Edge edge;
	Node* next;

	Node()
	{
		edge.start_ver = 0;
		edge.end_ver = 0;
		edge.weight = inf;
		next = nullptr;
	}

	Node(Edge edge)
	{
		this->edge.start_ver = edge.start_ver;
		this->edge.end_ver = edge.end_ver;
		this->edge.weight = edge.weight;
		this->next = nullptr;
	}
};

class EdgesList
{
	Node* head;
	Node* tail;

public:
	EdgesList() { head = tail = nullptr; }
	~EdgesList();
	void MakeEmpty() { head = tail = nullptr; }
	bool IsEmpty();	Node* GetHead() { return head; }
	void InsertNode(Edge edge);
	void DeleteNode(Node** pCurr, Node* prev);
};