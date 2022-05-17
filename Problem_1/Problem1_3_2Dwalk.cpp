#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

double twodimwalk(int num, int seed)
{
	double a1;
	srand(seed);
	double R2;
	double dx1, dy1;
	dx1 = 0;
	dy1 = 0;
	for (int j = 0; j < num; j++)
	{
		a1 = (double)rand() / RAND_MAX;
		if (a1 > 0 && a1 < 0.25)
		{
			dx1 += 1;
		}
		else if (a1 > 0.25 && a1 < 0.5)
		{
			dy1 += 1;
		}
		else if (a1 > 0.5 && a1 < 0.75)
		{
			dx1 -= 1;
		}
		else if (a1 > 0.75 && a1 < 1)
		{
			dy1 -= 1;
		}
	}
	R2 = pow(dx1, 2) + pow(dy1, 2);
	return R2;
}

int main()
{
	double value;
	ofstream myfile;
	myfile.open("prob_3_twodimwalk.txt");
	for (int k = 100; k <= 1000; k += 100)
	{
		for (int i = 0; i < 10000; i++)
		{
			value += twodimwalk(k, 4396 + i);
		}
		myfile << value / 10000 << endl;
		value = 0;
	}
	myfile.close();
	return 0;
}
