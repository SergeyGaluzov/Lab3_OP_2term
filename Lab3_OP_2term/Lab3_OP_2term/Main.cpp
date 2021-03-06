#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include "Generate_map.h"
#include "Realization.h"
#include "Node.h"
using namespace std;
int main()
{
	ifstream input;
	ofstream output;
	input.open("Input.txt");
	output.open("Output.txt");
	if (!input.is_open())
	{
		output << "The input file can not be opened" << endl;
	}
	else
	{
		string s;
		getline(input, s);
		int rows = s[0] - '0';
		int cols = s[s.length() - 1] - '0';
		string *map = generate_map(input, rows);
		int x_start, y_start;
		int x_finish, y_finish;
		int x_complication, y_complication;
		cout << "Please, input the coordinates of the start: ";
		cin >> x_start >> y_start;
		cout << "Please, input the coordinates of the complication: ";
		cin >> x_complication >> y_complication;
		cout << "Please, input the coordinates of the finish: ";
		cin >> x_finish >> y_finish;
		A_star(map, rows, cols, x_start, y_start, x_finish, y_finish, x_complication, y_complication, output);
	}
	input.close();
	output.close();
}