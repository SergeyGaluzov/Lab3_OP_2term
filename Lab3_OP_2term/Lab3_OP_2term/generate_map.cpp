#include <string>
#include <fstream>
using namespace std;
string* generate_map(ifstream & input, int rows)
{
	string *str = new string[rows];
	for (int i = 0; i < rows; i++)
	{
		getline(input, str[i]);
	}
	return str;
}