
#pragma once
#include <string>
using namespace std;
class Node
{
public:
	char data;
	int x_start, y_start;
	int x_finish, y_finish;
	int x_complication, y_complication;
	int x, y;
	double priority;
	double heuristic;
	Node *south, *west, *north, *east;
	int distance;
	Node *parent;
	Node *next;
	Node *prev;
	Node(string *map, int x_start, int y_start, int x_finish, int y_finish, int x_complication, int y_complication);
	Node(string *map, int x, int y, int x_start, int y_start, int x_finish, int y_finish, int x_complication, int y_complication);
};

