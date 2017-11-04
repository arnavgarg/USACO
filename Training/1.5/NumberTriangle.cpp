/*
ID: arnavga1
PROG: numtri
LANG:C++11
*/

#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int r;
vector<vector<int> > tri (1001);
vector<vector<int> > memo (1001, vector<int> (1001, -1));

int dfs(int nrow, int pos)
{
    int lnext, rnext;
    if (pos == 0)
        lnext = 0;
    else
        lnext = pos;
    rnext = pos+1;

    int sum = tri[nrow][pos];
    if (nrow != r)
    {
        int lbound, rbound;
        if (memo[nrow][lnext] != -1)
            lbound = memo[nrow][lnext];
        else
        {
            lbound = dfs(nrow+1, lnext);
            memo[nrow][lnext] = lbound;
        }
        if (memo[nrow][rnext] != -1)
            rbound = memo[nrow][rnext];
        else
        {
            rbound = dfs(nrow+1, rnext);
            memo[nrow][rnext] = rbound;
        }

        sum += max(lbound, rbound);

    }
    return sum;
}

int main()
{
    ifstream fin ("numtri.in");
    fin >> r;
    for (int i = 1; i <= r; i++)
        for (int j = 0; j < i; j++)
        {
            int tmp;
            fin >> tmp;
            tri[i].push_back(tmp);
        }

    ofstream fout ("numtri.out");
    fout << dfs(1, 0) << endl;
}
