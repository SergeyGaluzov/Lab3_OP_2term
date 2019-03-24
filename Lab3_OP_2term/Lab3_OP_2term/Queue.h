#pragma once
#include "Node.h"
class Queue
{
public:
	void insert(char symbol, int x, int y, int rows, int cols);
	void remove();
};
void Queue::insert(char symbol, int x, int y, int rows, int cols)
{
	if (symbol != '#')
	{
		Node *temp = new Node(x, y);
		temp->data = symbol;
		if (x == 0 && y == 0)
		{
			temp->north = nullptr;
			temp->west = nullptr;
			temp->south = new Node(x+1, y);
			temp->east = new Node(x, y+1);
		}
		else
		if (x == 0 && y == cols-1)
		{
			temp->north = nullptr;
			temp->east = nullptr;
			temp->south = new Node(x+1, y);
			temp->west = new Node(x, y-1);
		}
		else
		if (x == 0 && y != cols - 1)
		{
			temp->north = nullptr;
			temp->south = new Node(x+1, y);
			temp->west = new Node(x, y-1);
			temp->east = new Node(x, y+1);
		}
		else
		if (x != 0 && y == 0)
		{
			temp->north = new Node(x-1, y);
			temp->south = new Node(x+1, y);
			temp->west = nullptr;
			temp->east = new Node(x, y+1);
		}
		else
		if (x != 0 && y != 0)
		{
			temp->north = new Node(x-1, y);
			temp->south = new Node(x+1, y);
			temp->west = new Node(x, y-1);
			temp->east = new Node(x, y+1);
		}
		else
		if (x != 0 && y == 0)
		{
			temp->north = new Node(x-1, y);
			temp->south = new Node(x+1, y);
			temp->west = new Node(x, y-1);
			temp->east = nullptr;
		}
		else
		if (x == rows - 1 && y == 0)
		{
			temp->south = nullptr;
			temp->west = nullptr;
			temp->east = new Node(x, y+1);
			temp->north = new Node(x - 1, y);
		}
		else
		if (x == rows - 1 && y != 0)
		{
			temp->north = new Node(x - 1, y);
			temp->south = nullptr;
			temp->west = new Node(x, y - 1);
			temp->east = new Node(x, y + 1);
		}
		else
		if (x == rows - 1 && y == cols - 1)
		{
			temp->north = new Node(x - 1, y);
			temp->south = nullptr;
			temp->west = new Node(x, y - 1);
			temp->east = nullptr;
		}
	}
}
