#include <iostream>
#include <fstream>
#include <string>
#include "Generate_map.h"
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
		generate_map(input);
	}
	input.close();
	output.close();
}