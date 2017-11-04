/*
ID: arnavga1
PROG: milk3
LANG: C++11
*/

#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int a, b, c;
bool searched[21][21];
vector<int> amounts;

void dfs(int x, int y, int z)
{
    if (searched[x][y]) return;
    searched[x][y] = true;
    if (x == 0) amounts.push_back(z);
    // a into b
    if (x > 0 && y < b)
        dfs(max(0, x+y-b), min(b, x+y), z);
    // a into c
    if (x > 0 && z < c)
        dfs(max(0, x+z-c), y, min(c, x+z));
    // b into a
    if (y > 0 && x < a)
        dfs(min(a, x+y), max(0, x+y-a), z);
    // b into c
    if (y > 0 && z < c)
        dfs(x, max(0, x+z-c), min(c, x+z));
    // c into a
    if (z > 0 && x < a)
        dfs(min(a, x+z), y, max(0, x+z-a));
    // c into b
    if (z > 0 && y < b)
        dfs(x, min(b, y+z), max(0, y+z-b));
}

int main()
{
    ifstream fin ("milk3.in");
    fin >> a >> b >> c;

    dfs(0, 0, c);

    ofstream fout ("milk3.out");
    sort(amounts.begin(), amounts.end());
    fout << amounts[0];
    for (int i = 1; i < amounts.size(); i++)
        if (amounts[i])
            fout << " " << amounts[i];
    fout << endl;
}
