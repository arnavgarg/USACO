/*
ID: arnavga1
PROG: frac1
LANG: C++
*/

#include<fstream>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

int n;
vector<pair<int, int> > fracs;

bool sortFracs(pair<int, int> a, pair<int, int> b) { return ((double)a.first/(double)a.second < (double)b.first/(double)b.second); }

int lcf(int a, int b)
{
    int mx = max(a,b)/2;
    for (int i = 2; i <= mx; i++)
        if (a % i == 0 && b % i == 0)
            return i;
    return 0;
}

pair<int, int> simplify(pair<int, int> frac)
{
    while (lcf(frac.first, frac.second) != 0)
    {
        int div = lcf(frac.first, frac.second);
        frac.first /= div;
        frac.second /= div;
    }
    return frac;
}

bool inFracs(pair<int, int> frac)
{
    for (int i = 0; i < fracs.size(); i++)
        if (frac.first == fracs[i].first && frac.second == fracs[i].second)
            return true;
    return false;
}

int main()
{
     ifstream fin ("frac1.in");
     fin >> n;

     for (int den = 1; den <= n; den++)
        for (int num = 1; num <= n; num++)
        {
            pair<int, int> frac;
            frac.first = num;
            frac.second = den;
            frac = simplify(frac);
            if (!inFracs(frac) && (frac.first/frac.second < 1))
                fracs.push_back(frac);
        }

    sort(fracs.begin(), fracs.end(), sortFracs);

    ofstream fout ("frac1.out");
    fout << "0/1" << endl;
    for (int i = 0; i < fracs.size(); i++)
        fout << fracs[i].first << "/" << fracs[i].second << endl;
    fout << "1/1" << endl;
}
