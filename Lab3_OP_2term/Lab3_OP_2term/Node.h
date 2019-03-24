#pragma once
class Node
{
	char data;
	int x, y;
	int priority;
	Node *south, *west, *north, *east;
	int distance;
	Node *parent;
};