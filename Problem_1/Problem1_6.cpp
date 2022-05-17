#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

double random_num(int LO, int HI)
{
	double r;
	//	srand(seed);
	r = LO + (double)(rand()) / ((double)(RAND_MAX / (HI - LO)));
	return r;
}

int random_num1(int min, int max)
{
	return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}

int main()
{
	int row = 500;
	int col = 500;
	vector<vector<int>> grid(row, vector<int>(col, 0));
	double den = 0.001;
	int num1, num2, size, num3, num4, t;
	int start, start1;
	int b;
	double a;
	size = round(den * col * row);
	/*Filling grid with zeros*/
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			grid[i][j] = 0;
		}
	}

	/*fill the grid with traps*/
	for (int k = 0; k <= size; k++)
	{
		num1 = random_num1(0, 499);
		num2 = random_num1(0, 499);
		/*printf("%d\t, %d, %d\n",k,num1,num2);*/
		if (grid[num1][num2] == 0)
		{
			grid[num1][num2] = 1;
			/*printf("%d",grid[num1][num2]);*/
		}
		else
		{
			k = k--;
		}
	}
	num3 = random_num1(0, 499);
	num4 = random_num1(0, 499);
	grid[num3][num4];

	/*place a particle in random position*/
	/*	do{
			num3 = random_num1(0,500);
			num4=random_num1(0,500);
			grid[num3][num4];
		}
		while(grid[num3][num4]==1);
	*/
	ofstream myfile;
	myfile.open("prob_6_trap.txt");

	for (int g = 0; g < 100000; g++)
	{
		do
		{
			num3 = random_num1(0, 499);
			num4 = random_num1(0, 499);
			grid[num3][num4];
		} while (grid[num3][num4] == 1);
		t = 0;
		start = num3;
		start1 = num4;
		b = grid[start][start1];

		do
		{
			a = random_num(0, 1);
			t += 1;
			if (a > 0 && a < 0.25)
			{
				if (start1 == 500)
				{
					start1 -= 1;
				}
				else if (start == 500)
				{
					start -= 1;
				}
				else if (start == 0)
				{
					start += 1;
				}
				else if (start1 == 0)
				{
					start1 += 1;
				}
				b = grid[start][start1++];
				if (b == 1)
				{
					myfile << t << endl;
					break;
				}
				else
				{
					continue;
				}
			}
			if (a > 0.25 && a < 0.50)
			{
				if (start1 == 500)
				{
					start1 -= 1;
				}
				else if (start == 500)
				{
					start -= 1;
				}
				else if (start == 0)
				{
					start += 1;
				}
				else if (start1 == 0)
				{
					start1 += 1;
				}
				b = grid[start++][start1];
				if (b == 1)
				{
					myfile << t << endl;
					break;
				}
				else
				{
					continue;
				}
			}
			if (a > 0.50 && a < 0.75)
			{
				if (start1 == 500)
				{
					start1 -= 1;
				}
				else if (start == 500)
				{
					start -= 1;
				}
				else if (start == 0)
				{
					start += 1;
				}
				else if (start1 == 0)
				{
					start1 += 1;
				}
				b = grid[start][start1--];
				if (b == 1)
				{
					myfile << t << endl;
					break;
				}
				else
				{
					continue;
				}
			}
			if (a > 0.75 && a < 1)
			{
				if (start1 == 500)
				{
					start1 -= 1;
				}
				else if (start == 500)
				{
					start -= 1;
				}
				else if (start == 0)
				{
					start += 1;
				}
				else if (start1 == 0)
				{
					start1 += 1;
				}
				b = grid[start--][start1];
				if (b == 1)
				{
					myfile << t << endl;
					break;
				}
				else
				{
					continue;
				}
			}
			/*		if(start1==500 ){
						start1-=1;
					}
					else if(start==500 ){
						start-=1;
					}
					else if(start==0){
						start+=1;
					}
					else if(start1==0 ){
						start1+=1;
					}*/
		} while (b == 0);
	}
	myfile.close();
}