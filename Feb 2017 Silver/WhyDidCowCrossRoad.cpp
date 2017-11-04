#include<fstream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int c, n;
vector<int> cs (20000);
vector<pair<int, int> > ns (20000);
vector<vector<int> > pairings(20000);
vector<int> paircount (20000);

void removeFromAll(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < pairings[i].size(); j++)
            if (pairings[i][j] == n)
                pairings[i].erase(pairings[i].begin()+j);
}

int main()
{
    ifstream fin ("helpcross.in");
    fin >> c >> n;

    for (int i = 0; i < c; i++)
        fin >> cs[i];
    for (int i = 0; i < n; i++)
        fin >> ns[i].first >> ns[i].second;


    for (int i = 0; i < n; i++)
        for (int j = 0; j < c; j++)
            if (ns[i].first <= cs[j] && ns[i].second >= cs[j])
            {
                pairings[i].push_back(j);
                paircount[j]++;
            }

    int numpairs = 0;
    for (int i = 0; i < n; i++)
        if (pairings[i].size() == 1)
        {
            numpairs++;
            removeFromAll(pairings[i][0]);
        }

    for (int i = 0; i < n; i++)
        if (pairings[i].size() != 0)
        {
            numpairs++;
        }

    ofstream fout ("helpcross.out");
    fout << numpairs << endl;
}
