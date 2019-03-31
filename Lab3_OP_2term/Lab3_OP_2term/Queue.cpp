#include "Queue.h"
Queue::Queue(string *map, int rows, int cols, int x_finish, int y_finish, int x_start, int y_start)
{
	this->x_finish = x_finish;
	this->y_finish = y_finish;
	this->x_start = x_start;
	this->y_start = y_start;
	this->map = map;
	this->rows = rows;
	this->cols = cols;
}
void Queue::insert(Node *temp)
{
	if (temp->data != '#')
	{
		if (temp->x == 0 && temp->y == 0)
		{
			temp->north = nullptr;
			temp->west = nullptr;
			temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish);
			temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish);
			temp->north->parent = temp;
			temp->west->parent = temp;
			temp->south->parent = temp;
			temp->east->parent = temp;
		}
		else
			if (temp->x == 0 && temp->y == cols - 1)
			{
				temp->north = nullptr;
				temp->east = nullptr;
				temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish);
				temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish);
				temp->north->parent = temp;
				temp->west->parent = temp;
				temp->south->parent = temp;
				temp->east->parent = temp;
			}
			else
				if (temp->x == 0 && temp->y != cols - 1)
				{
					temp->north = nullptr;
					temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish);
					temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish);
					temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish);
					temp->north->parent = temp;
					temp->west->parent = temp;
					temp->south->parent = temp;
					temp->east->parent = temp;
				}
				else
					if (temp->x != 0 && temp->y == 0)
					{
						temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish);
						temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish);
						temp->west = nullptr;
						temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish);
						temp->north->parent = temp;
						temp->west->parent = temp;
						temp->south->parent = temp;
						temp->east->parent = temp;
					}
					else
						if (temp->x != 0 && temp->y != 0)
						{
							temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish);
							temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish);
							temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish);
							temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish);
							temp->north->parent = temp;
							temp->west->parent = temp;
							temp->south->parent = temp;
							temp->east->parent = temp;
						}
						else
							if (temp->x != 0 && temp->y == cols - 1)
							{
								temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish);
								temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish);
								temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish);
								temp->east = nullptr;
								temp->north->parent = temp;
								temp->west->parent = temp;
								temp->south->parent = temp;
								temp->east->parent = temp;
							}
							else
								if (temp->x == rows - 1 && temp->y == 0)
								{
									temp->south = nullptr;
									temp->west = nullptr;
									temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish);
									temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish);
									temp->north->parent = temp;
									temp->west->parent = temp;
									temp->south->parent = temp;
									temp->east->parent = temp;
								}
								else
									if (temp->x == rows - 1 && temp->y != 0)
									{
										temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish);
										temp->south = nullptr;
										temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish);
										temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish);
										temp->north->parent = temp;
										temp->west->parent = temp;
										temp->south->parent = temp;
										temp->east->parent = temp;
									}
									else
										if (temp->x == rows - 1 && temp->y == cols - 1)
										{
											temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish);
											temp->south = nullptr;
											temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish);
											temp->east = nullptr;
											temp->north->parent = temp;
											temp->west->parent = temp;
											temp->south->parent = temp;
											temp->east->parent = temp;
										}
		if (!size)
		{
			head = tail = temp;
			temp->next = nullptr;
		}
		else
			if (size == 1)
			{
				if (temp->priority >= head->priority)
				{
					temp->next = head;
					temp->parent = nullptr;
					head->parent = temp;
					head = temp;
				}
				else
				{
					temp->parent = tail;
					temp->next = nullptr;
					tail->next = temp;
					tail = temp;
				}
			}
			else
			{
				temp->next = head;
				Node *insertion = head;
				while (temp->priority < insertion->priority && (insertion != tail))
				{
					insertion = insertion->next;
				}
				if (insertion == head)
				{
					head = temp;
					insertion->parent = head;
					head->parent = nullptr;
				}
				else
				{
					if (insertion == tail)
					{
						if (temp->priority >= insertion->priority)
						{
							temp->next = tail;
							temp->parent = tail->parent;
							tail->parent->next = temp;
							tail->parent = temp;
						}
						else
						{
							temp->parent = tail;
							tail->next = temp;
							tail = temp;
							tail->next = nullptr;
						}
					}
					else
					{
						insertion->parent->next = temp;
						temp->parent = insertion->parent;
						temp->next = insertion;
						insertion->parent = temp;
					}
				}
			}
		size++;
	}
}
Node *Queue::remove()
{
	Node *del = tail;
	if (size > 1)
	{
		tail = tail->parent;
		tail->next = nullptr;
		size--;
		return del;
	}
	else
	{
		tail = head = nullptr;
		size--;
		return del;
	}
}
Node* Queue::low_pr()
{
		Node *p = head;
		if (size == 1)
		{
			return p;
		}
		else
		{
			if (size)
			{
				double min_pr = head->priority;
				Node *k = head;
				while (head->next != nullptr)
				{
					if (head->next->priority < head->priority)
					{
						p = head->next;
					}
					head = head->next;
				}
				head = k;
				return p;
			}
			else 
			return nullptr;
		}
}
bool Queue::check(Node *neighboor)
{
	if (!size) return false;
	Node *k = head;
	while (head->next != nullptr)
	{
		if (neighboor->x == k->x && neighboor->y == k->y)
		{
			head = k;
			return true;
		}
		head = head->next;
	}
	head = k;
	return false;
}
