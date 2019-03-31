#pragma once
#include <string>
#include "Node.h"
class Queue
{
public:
	Queue(string *map, int rows, int cols, int x_finish, int y_finish, int x_start, int y_start);
	void insert(Node *temp);
	Node *low_pr();
	Node* remove();
	bool check(Node *neighboor);
	Queue *closed;
	int x_finish;
	int y_finish;
	int x_start;
	int y_start;
	int rows;
	int cols;
	string *map;
	Node *head;
	Node *tail;
	int size;
};