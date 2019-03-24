#include <string>
#include "Realization.h"
#include "Queue.h"
#include "Node.h"
using namespace std;
void dijkstra_algorithm(int x_start, int y_start, string * map, int x_finish, int y_finish, int rows, int cols)
{
	Queue a;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			a.insert(map[i][j], i, j, rows, cols);
		}
	}

}
