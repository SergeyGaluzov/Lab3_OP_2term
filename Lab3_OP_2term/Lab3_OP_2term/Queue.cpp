#include "Queue.h"
Queue::Queue(string *map, int rows, int cols, int x_finish, int y_finish, int x_start, int y_start, int x_complication, int y_complication)
{
	this->x_finish = x_finish;
	this->y_finish = y_finish;
	this->x_start = x_start;
	this->y_start = y_start;
	this->map = map;
	this->rows = rows;
	this->cols = cols;
}
void Queue::insert(Node *temp, int x_complication, int y_complication)
{
	if (temp->data != '#')
	{
		if (temp->x == 0 && temp->y == 0)
		{
			temp->north = nullptr;
			temp->west = nullptr;
			temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
			temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
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
				temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
				temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
				temp->north->parent = temp;
				temp->west->parent = temp;
				temp->south->parent = temp;
				temp->east->parent = temp;
			}
			else
				if (temp->x == 0 && temp->y != cols - 1)
				{
					temp->north = nullptr;
					temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
					temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
					temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
					temp->north->parent = temp;
					temp->west->parent = temp;
					temp->south->parent = temp;
					temp->east->parent = temp;
				}
				else
					if (temp->x != 0 && temp->y == 0)
					{
						temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
						temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
						temp->west = nullptr;
						temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
						temp->north->parent = temp;
						temp->west->parent = temp;
						temp->south->parent = temp;
						temp->east->parent = temp;
					}
					else
						if (temp->x != 0 && temp->y != 0)
						{
							temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
							temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
							temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
							temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
							temp->north->parent = temp;
							temp->west->parent = temp;
							temp->south->parent = temp;
							temp->east->parent = temp;
						}
						else
							if (temp->x != 0 && temp->y == cols - 1)
							{
								temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
								temp->south = new Node(map, temp->x + 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
								temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
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
									temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
									temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
									temp->north->parent = temp;
									temp->west->parent = temp;
									temp->south->parent = temp;
									temp->east->parent = temp;
								}
								else
									if (temp->x == rows - 1 && temp->y != 0)
									{
										temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
										temp->south = nullptr;
										temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
										temp->east = new Node(map, temp->x, temp->y + 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
										temp->north->parent = temp;
										temp->west->parent = temp;
										temp->south->parent = temp;
										temp->east->parent = temp;
									}
									else
										if (temp->x == rows - 1 && temp->y == cols - 1)
										{
											temp->north = new Node(map, temp->x - 1, temp->y, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
											temp->south = nullptr;
											temp->west = new Node(map, temp->x, temp->y - 1, x_start, y_start, x_finish, y_finish, x_complication, y_complication);
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
			temp->prev = nullptr;
		}
		else
			if (size == 1)
			{
				if (temp->priority >= head->priority)
				{
					temp->next = head;
					temp->prev = nullptr;
					head->prev = temp;
					head = temp;
				}
				else
				{
					temp->prev = tail;
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
					insertion->prev = head;
					head->prev = nullptr;
				}
				else
				{
					if (insertion == tail)
					{
						if (temp->priority >= insertion->priority)
						{
							temp->next = tail;
							temp->prev = tail->prev;
							tail->prev->next = temp;
							tail->prev = temp;
						}
						else
						{
							temp->prev = tail;
							tail->next = temp;
							tail = temp;
							tail->next = nullptr;
						}
					}
					else
					{
						insertion->prev->next = temp;
						temp->prev = insertion->prev;
						temp->next = insertion;
						insertion->prev = temp;
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
		tail = tail->prev;
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
void Queue::remove(Node *temp)
{
	Node *del = tail;
	if (size > 0)
	{
		if (temp->x == tail->x && temp->y == tail->y)
		{
			tail = tail->prev;
			tail->next = nullptr;
			size--;
			return;
		}
		while (tail != head)
		{
			tail = tail->prev;
			if (temp->x == tail->x && temp->y == tail->y)
			{
				tail->prev->next = tail->next;
				tail->next->prev = tail->prev;
				tail = del; 
				return;
			}
		}
		if (temp->x == head->x && temp->y == head->y)
		{
			head = head->next;
			head->prev = nullptr;
			size--;
			return;
		}
	}
}
Node* Queue::low_pr()
{
		if (size)
		{
			return tail;
		}
		else
		{
			return nullptr;
		}
}
bool Queue::check(Node *neighboor)
{
	if (!size) return false;
	Node *k = head;
	while (head != nullptr)
	{
		if (neighboor->x == head->x && neighboor->y == head->y)
		{
			head = k;
			return true;
		}
		head = head->next;
	}
	head = k;
	return false;
}
