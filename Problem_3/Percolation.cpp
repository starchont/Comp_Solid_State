#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

void erase(std::vector<int> &v, int key)
{
    v.erase(std::remove(v.begin(), v.end(), key), v.end());
}

int main()
{
    int row = 500;
    int col = 500;
    double p_max = 0.8;
    int k = 1;
    double random_num;
    double m_max, I;
    double p_max_1, I_1;
    vector<vector<int>> grid(row, vector<int>(col, 0));
    vector<int> L(pow(row + 1, 2));
    vector<int> S(pow(row + 1, 2));
    vector<double> probability;
    double l_boundary = 0.5;
    double u_boundary = 0.6;
    vector<int>::iterator iter_1;
    vector<int>::iterator s_without_max;
    ofstream myfile;
    ofstream myfile_1;
    ofstream myfile_2;
    myfile.open("I_values_1.txt");
    myfile_1.open("p_max_values_1.txt");
    myfile_2.open("Ian_without_max_value_1.txt");

    /*Calculating the values of p*/
    for (double dp = 0.1; dp <= p_max; dp >= l_boundary &&dp <= u_boundary ? dp += 0.01 : dp += 0.1)
    {
        probability.push_back(dp);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            grid[i][j] = 0;
        }
    }

    /*CMLT Algorithm*/
    for (auto iter_1 = probability.begin(); iter_1 != probability.end(); ++iter_1)
    {
        cout << *iter_1 << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                grid[i][j] = 0;
            }
        }

        for (int j = 1; j < row; j++)
        {
            for (int i = 1; i < col; i++)
            {
                random_num = (double)rand() / RAND_MAX;
                if (random_num <= *iter_1)
                {
                    grid[i][j] = 1;
                }
            }
        }

        k = 1;

        for (int j = 1; j < row; j++)
        {
            for (int i = 1; i < col; i++)
            {
                if (grid[i][j] != 0)
                {
                    if (grid[i][j - 1] != 0)
                    {
                        grid[i][j] = L[grid[i][j - 1]];
                        S[L[grid[i][j]]] += 1;
                        if (grid[i - 1][j] != 0 && grid[i - 1][j] != L[grid[i][j - 1]])
                        {
                            for (int val = 0; val < pow(row, 2); val++)
                            {
                                if (L[val] == grid[i - 1][j])
                                {
                                    L[val] = L[grid[i][j - 1]];
                                }
                            }
                            S[L[grid[i][j - 1]]] = S[L[grid[i][j - 1]]] + S[grid[i - 1][j]];
                            S[grid[i - 1][j]] = 0;
                        }
                    }
                    else if (grid[i][j - 1] == 0)
                    { 
                        if (grid[i - 1][j] != 0)
                        { 
                            grid[i][j] = L[grid[i - 1][j]];
                            S[L[grid[i][j]]] += 1;
                        }
                        else if (grid[i - 1][j] == 0)
                        {
                            L[k] = k;
                            grid[i][j] = L[k];
                            S[L[grid[i][j]]] += 1;
                            k = k + 1;
                        }
                    }
                }
            }
        }

        m_max = *max_element(S.begin(), S.end());
        p_max_1 = m_max / (*iter_1 * pow(row, 2));
        int key = m_max;

        for (auto &n : S)
        {
            I += pow(n, 2) / (*iter_1 * pow(row, 2));
        }
        erase(S, key);
        I_1 = 0;

        for (auto &value : S)
        {
            I_1 += pow(value, 2) / (*iter_1 * pow(row, 2));
        }
        myfile << I << "  " << *iter_1 << endl;
        myfile_1 << p_max_1 << " " << *iter_1 << endl;
        myfile_2 << I_1 << " " << *iter_1 << endl;
        std::fill(S.begin(), S.end(), 0);
        std::fill(L.begin(), L.end(), 0);
    }
    myfile.close();
    myfile_1.close();
    myfile_2.close();
}