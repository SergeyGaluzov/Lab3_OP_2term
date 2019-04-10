#include "Realization.h"
#include "Queue.h"
#include <string>
#include "Node.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
void draw_path(Queue & closed, string * map, ofstream & output)
{
	Node *p = closed.tail;
	while (p != closed.head)
	{
		if (p->next == nullptr)
		{
			map[p->x][p->y] = 'S';
		}
		else
		{
			map[p->x][p->y] = 'X';
		}
		p = p->prev;
	}
	map[p->x][p->y] = 'F';
	for (int i = 0; i < closed.rows; i++)
	{
		for (int j = 0; j < closed.cols; j++)
		{
			cout << map[i][j];
			output << map[i][j];
		}
		cout << endl;
		output << endl;
	}
}
void A_star(string* map, int rows, int cols, int x_start, int y_start, int x_finish, int y_finish, ofstream & output)
{
	Node start(map, x_start, y_start, x_finish, y_finish);
	Queue closed(map, rows, cols, x_finish, y_finish, x_start, y_start);
	Queue opened(map, rows, cols, x_finish, y_finish, x_start, y_start);
	Queue temp(map, rows, cols, x_finish, y_finish, x_start, y_start);
	vector <Node *> neighboors;
	opened.insert(&start);
	Node *curr = opened.low_pr();
	while (curr->x != x_finish || curr->y != y_finish)
	{
		curr = opened.remove();
		closed.insert(curr);
		if (curr->north->data != '#')
		{
			temp.insert(curr->north);
			temp.remove();
			if (curr->north->north->data != '#')
			{
				temp.insert(curr->north->north);
				temp.remove();
				if (curr->north->north->east->data != '#')
				{
					neighboors.push_back(curr->north->north->east);
				}
				if (curr->north->north->west->data != '#')
				{
					neighboors.push_back(curr->north->north->west);
				}
			}
		}

		if (curr->east->data != '#')
		{
			temp.insert(curr->east);
			temp.remove();
			if (curr->east->east->data != '#')
			{
				temp.insert(curr->east->east);
				temp.remove();
				if (curr->east->east->north->data != '#')
				{
					neighboors.push_back(curr->east->east->north);
				}
				if (curr->east->east->south->data != '#')
				{
					neighboors.push_back(curr->east->east->south);
				}
			}
		}

		if (curr->south->data != '#')
		{
			temp.insert(curr->south);
			temp.remove();
			if (curr->south->south->data != '#')
			{
				temp.insert(curr->south->south);
				temp.remove();
				if (curr->south->south->east->data != '#')
				{
					neighboors.push_back(curr->south->south->east);
				}
				if (curr->south->south->west->data != '#')
				{
					neighboors.push_back(curr->south->south->west);
				}
			}
		}

		if (curr->west->data != '#')
		{
			temp.insert(curr->west);
			temp.remove();
			if (curr->west->west->data != '#')
			{
				temp.insert(curr->west->west);
				temp.remove();
				if (curr->west->west->north->data != '#')
				{
					neighboors.push_back(curr->west->west->north);
				}
				if (curr->west->west->south->data != '#')
				{
					neighboors.push_back(curr->west->west->south);
				}
			}
		}


		if (curr->north->data != '#')
		{
			if (curr->north->west->data != '#')
			{
				temp.insert(curr->north->west);
				temp.remove();
				if (curr->north->west->west->data != '#')
				{
					neighboors.push_back(curr->north->west->west);
				}
			}
			if (curr->north->east->data != '#')
			{
				temp.insert(curr->north->east);
				temp.remove();
				if (curr->north->east->east->data != '#')
				{
					neighboors.push_back(curr->north->east->east);
				}
			}
		}

		if (curr->east->data != '#')
		{
			if (curr->east->north->data != '#')
			{
				temp.insert(curr->east->north);
				temp.remove();
				if (curr->east->north->north->data != '#')
				{
					neighboors.push_back(curr->east->north->north);
				}
			}
			if (curr->east->south->data != '#')
			{
				temp.insert(curr->east->south);
				temp.remove();
				if (curr->east->south->south->data != '#')
				{
					neighboors.push_back(curr->east->south->south);
				}
			}
		}

		if (curr->south->data != '#')
		{
			if (curr->south->west->data != '#')
			{
				temp.insert(curr->south->west);
				temp.remove();
				if (curr->south->west->west->data != '#')
				{
					neighboors.push_back(curr->south->west->west);
				}
			}
			if (curr->south->east->data != '#')
			{
				temp.insert(curr->south->east);
				temp.remove();
				if (curr->south->east->east->data != '#')
				{
					neighboors.push_back(curr->south->east->east);
				}
			}
		}

		if (curr->west->data != '#')
		{
			if (curr->west->north->data != '#')
			{
				temp.insert(curr->west->north);
				temp.remove();
				if (curr->west->north->north->data != '#')
				{
					neighboors.push_back(curr->west->north->north);
				}
			}
			if (curr->west->south->data != '#')
			{
				temp.insert(curr->west->south);
				temp.remove();
				if (curr->west->south->south->data != '#')
				{
					neighboors.push_back(curr->west->south->south);
				}
			}
		}
		for (int i = 0; i < neighboors.size(); i++)
		{
			int cost = curr->distance + (abs(neighboors[i]->x - curr->x) + abs(neighboors[i]->y - curr->y));
			if (opened.check(neighboors[i]) && cost < neighboors[i]->distance)
			{
				opened.remove(neighboors[i]);
			}
			if (closed.check(neighboors[i]))
			{
				continue;
			}
			if (!opened.check(neighboors[i]) && !closed.check(neighboors[i]))
			{
				neighboors[i]->distance = cost;
				neighboors[i]->priority = neighboors[i]->distance + neighboors[i]->heuristic;
				opened.insert(neighboors[i]);
				neighboors[i]->parent = curr;
			}
		}
		neighboors.clear();
	}
	draw_path(closed, map, output);
}
