#include <string>
#include <fstream>
using namespace std;
void generate_map(ifstream & input)
{
	string s;
	getline(input, s);
	int rows = s[0] - '0';
	int cols = s[s.length() - 1] - '0';
	string *str = new string[rows];
	for (int i = 0; i < rows; i++)
	{
		getline(input, str[i]);
	}
}