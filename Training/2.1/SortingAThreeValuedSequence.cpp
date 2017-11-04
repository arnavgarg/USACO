/*
ID: arnavga1
PROG: sort3
LANG: C++11
*/

#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int n;
    ifstream fin ("sort3.in");
    fin >> n;

    int c[4] = {0}, s[n];
    for (int i = 0; i < n; i++)
    {
        fin >> s[i];
        c[s[i]]++;
    }

    int s12 = 0, s21 = 0, s23 = 0, s32 = 0, s13 = 0, s31 = 0;

    for (int i = 0; i < c[1]; i++)
    {
        if (s[i] == 2) s12++;
        if (s[i] == 3) s13++;
    }
    for (int i = c[1]; i < c[1]+c[2]; i++)
    {
        if (s[i] == 1) s21++;
        if (s[i] == 3) s23++;
    }
    for (int i = c[1]+c[2]; i < n; i++)
    {
        if (s[i] == 1) s31++;
        if (s[i] == 2) s32++;
    }

    ofstream fout ("sort3.out");
    fout << min(s12, s21) + min(s13, s31) + min(s23, s32) + 2*(max(s12, s21) - min(s12, s21)) << endl;
}
