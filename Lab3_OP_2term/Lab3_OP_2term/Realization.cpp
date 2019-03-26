#include <string>
#include "Realization.h"
#include "Queue.h"
#include "Node.h"
using namespace std;
void dijkstra_algorithm(int &x_start, int &y_start, string * map, int x_finish, int y_finish, int rows, int cols)
{
	Queue opened;
	Queue closed;
	Node start(x_start, y_start, map, x_finish, y_finish);
	opened.insert(&start);
	Node south(x_start, ++y_start, map, x_finish, y_finish);
	Node east(--x_start, y_start, map, x_finish, y_finish);
	Node west(++x_start, y_start, map, x_finish, y_finish);
	Node north(x_start, --y_start, map, x_finish, y_finish);

	opened.insert(&south);
	closed.insert(opened.remove());
}
