#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int row = 1;
	int col = 2000;
	vector<vector<int>> grid(row, vector<int>(col, 0));

	double a, sum, value;
	int start;
	srand(4396);
	start = 999;
	grid[row - 1][start] = 1;
	ofstream myfile;
	myfile.open("prob_5_onedimwalk.txt");
	for (int k = 100; k <= 1000; k += 100)
	{
		for (int l = 0; l < 10000; l++)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					grid[i][j] = 0;
				}
			}
			start = 999;
			grid[row - 1][start] = 1;
			for (int m = 0; m <= k; m++)
			{
				a = (double)rand() / RAND_MAX;
				if (a < 0.5 && a > 0)
				{
					grid[row - 1][start++] = 1;
				}
				else if (a > 0.5 && a < 1)
				{
					grid[row - 1][start--] = 1;
				}
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					sum += grid[i][j];
				}
			}
			value += sum;
			sum = 0;
		}
		myfile << value / 10000 << endl;
		cout << value / 10000 << endl;
		value = 0;
	}
	myfile.close();
	return 0;
}
