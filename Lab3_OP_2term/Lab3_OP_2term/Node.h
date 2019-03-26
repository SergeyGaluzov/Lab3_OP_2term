#pragma once
#include <string>
using namespace std;
class Node
{
public:
	char data;
	int x, y;
	int priority;
	int heuristic;
	Node *south, *west, *north, *east;
	int distance;
	Node *parent;
	Node *next;
	Node *prev;
	Node(int x, int y);
	Node(int x, int y, string *map, int x_finish, int y_finish);
};

