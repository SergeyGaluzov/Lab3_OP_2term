#pragma once
#include <string>
#include "Node.h"
class Queue
{
public:
	void insert(Node *temp);
	Queue();
	Node* remove();
	int size;
	Node *first;
	Node *second;
	Node *third;
	Node *fourth;
	Node *head;
	Node *tail;
};
Queue::Queue()
{
	size = 0;
}
//void Queue::insert(Queue &visited, Queue a, Node *temp, int x, int y, int rows, int cols, string * map, int x_finish, int y_finish)
//{
//	temp->data = map[x][y];
//	if (!size)
//	{
//		head = temp;
//		first = nullptr;
//		second = nullptr;
//		third = nullptr;
//		fourth = nullptr;
//	if (temp->data != '#')
//	{
//		if (temp->x == 0 && temp->y == 0)
//		{
//			temp->north = nullptr;
//			temp->west = nullptr;
//			temp->south = new Node(x+1, y);
//			temp->east = new Node(x, y+1);
//			temp->north->parent = temp;
//			temp->west->parent = temp;
//			temp->south->parent = temp;
//			temp->east->parent = temp;
//		}
//		else
//		if (x == 0 && y == cols-1)
//		{
//			temp->north = nullptr;
//			temp->east = nullptr;
//			temp->south = new Node(x+1, y);
//			temp->west = new Node(x, y-1);
//			temp->north->parent = temp;
//			temp->west->parent = temp;
//			temp->south->parent = temp;
//			temp->east->parent = temp;
//		}
//		else
//		if (x == 0 && y != cols - 1)
//		{
//			temp->north = nullptr;
//			temp->south = new Node(x+1, y);
//			temp->west = new Node(x, y-1);
//			temp->east = new Node(x, y+1);
//			temp->north->parent = temp;
//			temp->west->parent = temp;
//			temp->south->parent = temp;
//			temp->east->parent = temp;
//		}
//		else
//		if (x != 0 && y == 0)
//		{
//			temp->north = new Node(x-1, y);
//			temp->south = new Node(x+1, y);
//			temp->west = nullptr;
//			temp->east = new Node(x, y+1);
//			temp->north->parent = temp;
//			temp->west->parent = temp;
//			temp->south->parent = temp;
//			temp->east->parent = temp;
//		}
//		else
//		if (x != 0 && y != 0)
//		{
//			temp->north = new Node(x-1, y);
//			temp->south = new Node(x+1, y);
//			temp->west = new Node(x, y-1);
//			temp->east = new Node(x, y+1);
//			temp->north->parent = temp;
//			temp->west->parent = temp;
//			temp->south->parent = temp;
//			temp->east->parent = temp;
//		}
//		else
//		if (x != 0 && y == 0)
//		{
//			temp->north = new Node(x-1, y);
//			temp->south = new Node(x+1, y);
//			temp->west = new Node(x, y-1);
//			temp->east = nullptr;
//			temp->north->parent = temp;
//			temp->west->parent = temp;
//			temp->south->parent = temp;
//			temp->east->parent = temp;
//		}
//		else
//		if (x == rows - 1 && y == 0)
//		{
//			temp->south = nullptr;
//			temp->west = nullptr;
//			temp->east = new Node(x, y+1);
//			temp->north = new Node(x - 1, y);
//			temp->north->parent = temp;
//			temp->west->parent = temp;
//			temp->south->parent = temp;
//			temp->east->parent = temp;
//		}
//		else
//		if (x == rows - 1 && y != 0)
//		{
//			temp->north = new Node(x - 1, y);
//			temp->south = nullptr;
//			temp->west = new Node(x, y - 1);
//			temp->east = new Node(x, y + 1);
//			temp->north->parent = temp;
//			temp->west->parent = temp;
//			temp->south->parent = temp;
//			temp->east->parent = temp;
//		}
//		else
//		if (x == rows - 1 && y == cols - 1)
//		{
//			temp->north = new Node(x - 1, y);
//			temp->south = nullptr;
//			temp->west = new Node(x, y - 1);
//			temp->east = nullptr;
//			temp->north->parent = temp;
//			temp->west->parent = temp;
//			temp->south->parent = temp;
//			temp->east->parent = temp;
//		}
//	}
//	if (!temp->north)
//	{
//		a.insert(visited, a, temp->north, x, y, rows, cols, map, x_finish, y_finish);
//	}
//	if (!temp->east)
//	{
//		a.insert(visited, a, temp->east, x, y, rows, cols, map, x_finish, y_finish);
//	}
//	if (!temp->south)
//	{
//		a.insert(visited, a, temp->south, x, y, rows, cols, map, x_finish, y_finish);
//	}
//	if (!temp->west)
//	{
//		a.insert(visited, a, temp->west, x, y, rows, cols, map, x_finish, y_finish);
//	}
//	size++;
//}
void Queue::insert(Node *temp)
{
	if (!size)
	{
		head = tail = temp;
		temp->next = nullptr;
	}
	else
	{
			if (size == 1)
			{
				if (temp->priority >= head->priority)
				{
					temp->next = head;
					temp->prev = nullptr;
					head->prev = temp;
					head = temp;
				}
				else
				{
					temp->prev = tail;
					temp->next = nullptr;
					tail->next = temp;
					tail = temp;
				}
			}
			else
			{
				temp->next = head;
				Node *insertion = head;
				while (temp->priority < insertion->priority && (insertion != tail))
				{
					insertion = insertion->next;
				}
				if (insertion == head)
				{
					head = temp;
					insertion->prev = head;
					head->prev = nullptr;
				}
				else
				{
					if (insertion == tail)
					{
						if (temp->priority >= insertion->priority)
						{
							temp->next = tail;
							temp->prev = tail->prev;
							tail->prev->next = temp;
							tail->prev = temp;
						}
						else
						{
							temp->prev = tail;
							tail->next = temp;
							tail = temp;
							tail->next = nullptr;
						}
					}
					else
					{
						insertion->prev->next = temp;
						temp->prev = insertion->prev;
						temp->next = insertion;
						insertion->prev = temp;
					}
				}
			}
	}
	size++;
}
Node* Queue::remove()
{
		if (size > 1)
		{
			Node *del = tail;
			tail = tail->prev;
			tail->next = nullptr;
			size--;
			return del;
		}
		else
		{
			return head;
			size--;
		}
}