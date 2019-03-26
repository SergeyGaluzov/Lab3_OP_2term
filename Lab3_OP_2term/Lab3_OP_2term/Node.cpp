#include "Node.h"
#include <string>
using namespace std;
Node::Node(int x_start, int y_start, string *map, int x_finish, int y_finish)
{
	this->x = x_start;
	this->y = y_start;
	data = map[x][y];
	heuristic = abs(this->x - x_finish) + abs(this->y - y_finish);
	distance = abs(this->x - x_start) + abs(this->y - y_start);
	priority = distance + heuristic;
}
Node::Node(int x, int y)
{
	this->x = x;
	this->y = y;
}