#include "Node.h"
#include "Queue.h"
#include "Realization.h"
#include <string>
using namespace std;
Node::Node(string *map, int x, int y, int x_start, int y_start, int x_finish, int y_finish, int x_complication, int y_complication)
{
	this->x_start = x_start;
	this->y_start = y_start;
	this->x_complication = x_complication;
	this->y_complication = y_complication;
	this->x_finish = x_finish;
	this->y_finish = y_finish;
	this->x = x;
	this->y = y;
	data = map[this->x][this->y];
	heuristic = sqrt((x_finish - this->x)*(x_finish - this->x) + (y_finish - this->y)*(y_finish - this->y));
	if (this->x == x_complication && this->y == y_complication)
	{
		distance = abs(this->x - x_start) + abs(this->y - y_start) + 1000;
	}
	else
	{
		distance = abs(this->x - x_start) + abs(this->y - y_start);
	}
	priority = distance + heuristic;
}
Node::Node(string *map, int x_start, int y_start, int x_finish, int y_finish, int x_complication, int y_complication)
{
	this->x_start = x_start;
	this->y_start = y_start;
	this->x_complication = x_complication;
	this->y_complication = y_complication;
	this->x_finish = x_finish;
	this->y_finish = y_finish;
	this->x = x_start;
	this->y = y_start;
	data = map[this->x][this->y];
	heuristic = sqrt((x_finish - this->x)*(x_finish - this->x) + (y_finish-this->y)*(y_finish - this->y));
	if (this->x == x_complication && this->y == y_complication)
	{
		distance = abs(this->x - x_start) + abs(this->y - y_start) + 1000;
	}
	else
	{
		distance = abs(this->x - x_start) + abs(this->y - y_start);
	}
	priority = distance + heuristic;
}