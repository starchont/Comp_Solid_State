#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double onedimwalk(int number, int seed)
{
	double a;
	srand(seed);
	double dx, R1;
	dx = 0;
	for (int i = 0; i < number; i++)
	{
		a = (double)rand() / RAND_MAX;
		if (a < 0.5 && a > 0)
		{
			dx += 1;
		}
		else if (a > 0.5 && a < 1)
		{
			dx -= 1;
		}
	}
	R1 = pow(dx, 2);
	return R1;
}

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
	double value, value1;
	int lmax = 10000;

	/*Running the program for one dimension walk*/
	for (int q = 0; q < lmax; q++)
	{
		onedimwalk(1000, 4396 + q);
		value1 += onedimwalk(1000, 4396 + q);
	}
	cout << "The mean value for 1D walk is: " << (value1 / lmax) << endl;

	/*Running the program for two dimension walk*/
	for (int l = 0; l < lmax; l++)
	{
		twodimwalk(1000, 4396 + l);
		value += twodimwalk(1000, 4396 + l);
	}
	cout << "The mean value for 2D walk is: " << (value / lmax) << endl;
	return 0;
}
