#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

double sum_rand_num(int number)
{
	double a, sum;
	srand(4396);
	for (int i = 0; i < number; i++)
	{
		a = (double)rand() / RAND_MAX;
		sum += a;
	}
	return sum;
}

int main()
{
	int max, l;
	double mean_val;
	cout << ("Enter the max value for random number generator: ");
	cin >> max;
	l = 0;
	ofstream myfile;
	myfile.open("Problem_1.txt");
	for (l = 10; l <= max; l *= 10)
	{
		mean_val = sum_rand_num(l) / l;
		myfile << mean_val << endl;
		cout << "N=" << l << " and mean value= " << mean_val << endl;
	}
	myfile.close();
	return 0;
}
