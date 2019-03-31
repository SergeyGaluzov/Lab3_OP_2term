#include "Realization.h"
#include "Queue.h"
#include <string>
#include "Node.h"
#include <vector>
using namespace std;
void A_star(string* map, int rows, int cols, int x_start, int y_start, int x_finish, int y_finish)
{
	Node start(map, x_start, y_start, x_finish, y_finish);
	Queue closed(map, rows, cols, x_finish, y_finish, x_start, y_start);
	Queue opened(map, rows, cols, x_finish, y_finish, x_start, y_start);
	opened.insert(&start);
	Node *curr = opened.low_pr();
	while (curr->x != x_finish && curr->y != y_finish)
	{
		curr = opened.remove();
		closed.insert(curr);
		vector <Node *> neighboors;
		neighboors.push_back(curr->north);
		neighboors.push_back(curr->east);
		neighboors.push_back(curr->south);
		neighboors.push_back(curr->west);
		for (int i = 0; i < neighboors.size(); i++)
		{
			int cost = curr->distance + (abs(neighboors[i]->x - curr->x) + abs(neighboors[i]->y - curr->y));
			if (opened.check(neighboors[i]) && cost < neighboors[i]->distance)
			{
				opened.remove();
			}
			if (closed.check(neighboors[i]) && cost < neighboors[i]->distance)
			{
				closed.remove();
			}
			if (!opened.check(neighboors[i]) && !closed.check(neighboors[i]))
			{
				neighboors[i]->distance = cost;
				opened.insert(neighboors[i]);
				neighboors[i]->priority = neighboors[i]->distance + neighboors[i]->heuristic;
				neighboors[i]->parent = curr;
			}
		}
		neighboors.clear();
	}
}
