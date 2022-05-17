#include <iostream>
#include <cstdlib>
#include <fstream>
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

int main()
{
	double value;
	ofstream myfile;
	myfile.open("prob_3_onedimwalk.txt");
	for (int k = 100; k <= 1000; k += 100)
	{
		for (int i = 0; i < 10000; i++)
		{
			value += onedimwalk(k, 4396 + i);
		}
		myfile << value / 10000 << endl;
		value = 0;
	}
	myfile.close();
	return 0;
}
