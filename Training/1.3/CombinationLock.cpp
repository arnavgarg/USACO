/*
ID: arnavga1
PROG: combo
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

bool check(int i, int j, int k, int a, int b, int c);
bool check1(int a, int b);

int n;
int main()
{
    ifstream fin ("combo.in");
    ofstream fout ("combo.out");
    fin >> n;
    int j_1, j_2, j_3;
    fin >> j_1 >> j_2 >> j_3;
    int m_1, m_2, m_3;
    fin >> m_1 >> m_2 >> m_3;

    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (check(i, j, k, j_1, j_2, j_3) || check(i, j, k, m_1, m_2, m_3))
                    count++;
    fout << count << endl;
}

bool check(int i, int j, int k, int a, int b, int c)
{
    return (check1(i, a) && check1(j, b) && check1(k, c));
}

bool check1(int a, int b)
{
    if (abs(a - b) <= 2) return true;
    if (abs(a - b) >= n-2) return true;
    return false;
}