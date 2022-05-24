#include "EdgesList.h"

EdgesList::~EdgesList()
{
	Node* curr = head, *temp;

	while (curr != nullptr)
	{
		temp = curr->next;
		delete curr;
		curr = temp;
	}
}

bool EdgesList::IsEmpty()
{
	return (head == nullptr);
}

// Function to delete node in the list
void EdgesList::DeleteNode(Node** pCurr, Node* prev)
{
	Node* toDelete = *pCurr;

	if (this->head == this->tail)
	{
		this->head = this->tail = nullptr;
		*pCurr = nullptr;
	}
	else if (this->head == toDelete)
	{
		this->head = this->head->next;
		*pCurr = this->head;
	}
	else if (this->tail == toDelete)
	{
		this->tail = prev;
		this->tail->next = nullptr;
		*pCurr = nullptr;
	}
	else
	{
		prev->next = toDelete->next;
		*pCurr = prev->next;
	}

	delete toDelete;
}

// Function to insert a new node
void EdgesList::InsertNode(Edge edge)
{
	Node* newNode = new Node(edge);

	if (head == nullptr) // the list was empty
	{
		head = tail = newNode;
		return;
	}

	Node* temp = head;

	while (temp->next != nullptr)
	{
		temp = temp->next;
	}

	temp->next = newNode;
	tail = newNode;
}