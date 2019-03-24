#pragma once
class Node
{
public:
	char data;
	int x, y;
	int priority;
	Node *south, *west, *north, *east;
	int distance;
	Node *parent;
	Node(int x, int y);
};

