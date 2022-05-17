#include <iostream>
#include <cstdlib>
#include <fstream>

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
	R1 = dx;
	return R1;
}

int main()
{
	double value, value1;
	int lmax = 10000;
	ofstream myfile;
	myfile.open("R_for_1000steps.txt");

	/*Running the program for 1000 steps*/
	for (int q = 0; q < lmax; q++)
	{
		value = onedimwalk(1000, 4396 + q);
		myfile << value << endl;
	}
	myfile.close();

	/*for 2000 steps*/
	myfile.open("R_for_2000steps.txt");
	for (int q = 0; q < lmax; q++)
	{
		value1 = onedimwalk(2000, 4396 + q);
		myfile << value1 << endl;
	}
	myfile.close();
	return 0;
}
