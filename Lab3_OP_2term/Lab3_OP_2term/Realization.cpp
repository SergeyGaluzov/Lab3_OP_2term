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
	int k = 0;
	Node *p = closed.head;
	while (p != closed.tail)
	{
		k++;
		if (p->prev == nullptr)
		{
			map[p->x][p->y] = 'F';
		}
		else
		{
			if ((abs(p->prev->x - p->x) == 1 && abs(p->prev->y - p->y) == 0) || (abs(p->prev->x - p->x) == 0 && abs(p->prev->y - p->y) == 1))
			{
				map[p->x][p->y] = 'X';
			}
			else
			{
				closed.remove(p);
				p = p->next;
				continue;
			}
		}
		p = p->next;
	}
	map[p->x][p->y] = 'S';
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
	vector <Node *> neighboors;
	opened.insert(&start);
	Node *curr = opened.low_pr();
	while (curr->x != x_finish || curr->y != y_finish)
	{
		curr = opened.remove();
		closed.insert(curr);
		neighboors.push_back(curr->north);
		neighboors.push_back(curr->east);
		neighboors.push_back(curr->south);
		neighboors.push_back(curr->west);
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
