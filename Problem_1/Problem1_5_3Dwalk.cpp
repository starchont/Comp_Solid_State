#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int row = 1000;
	int col = 1000;
	int z = 1000;
	vector<vector<vector<int>>> grid(row, vector<vector<int>>(col, vector<int>(z)));
	double a, sum, value;
	int start, start1, start2;
	srand(4396);
	start = 499;
	start1 = 499;
	start2 = 499;
	grid[start1][start][start2] = 1;
	ofstream myfile;
	myfile.open("prob_5_threedimwalk.txt");
	for (int k = 100; k <= 1000; k += 100)
	{
		for (int l = 0; l < 1000; l++)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					for (int t = 0; t < z; t++)
					{
						grid[i][j][t] = 0;
					}
				}
			}
			start = 499;
			start1 = 499;
			start2 = 499;
			grid[start1][start][start2] = 1;
			for (int m = 0; m <= k; m++)
			{
				a = (double)rand() / RAND_MAX;
				if (a > 0 && a < 0.16)
				{
					grid[start1][start++][start2] = 1;
				}
				else if (a > 0.16 && a < 0.33)
				{
					grid[start1++][start][start2] = 1;
				}
				else if (a > 0.5 && a < 0.66)
				{
					grid[start1][start--][start2] = 1;
				}
				else if (a > 0.66 && a < 0.83)
				{
					grid[start1--][start][start2] = 1;
				}
				else if (a > 0.33 && a < 0.5)
				{
					grid[start1][start][start2++] = 1;
				}
				else if (a > 0.83 && a < 1)
				{
					grid[start1][start][start2--] = 1;
				}
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					for (int t = 0; t < z; t++)
					{
						sum += grid[i][j][t];
					}
				}
			}
			value += sum;
			sum = 0;
		}
		myfile << value / 1000 << endl;
		cout << value / 1000 << endl;
		value = 0;
	}
	myfile.close();
	return 0;
}
