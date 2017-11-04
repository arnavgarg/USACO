/*
ID: arnavga1
PROG: ariprog
LANG: C++
*/

#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

bool sort_alg(vector<int> a, vector<int> b)
{
    if (a[1] < b[1])
        return true;
    else if (a[1] == b[1])
        return a[0] < b[0];
    else
        return false;
}

void print_all(vector<vector<int> > ans)
{
    ofstream fout ("ariprog.out");
    if (ans.size() == 0)
    {
        fout << "NONE" << endl;
        return;
    }
    sort(ans.begin(), ans.end(), sort_alg);
    for (int i = 0; i < ans.size(); i++)
        fout << ans[i][0] << " " << ans[i][1] << endl;
}

int main()
{
    int n, m;
    ifstream fin ("ariprog.in");
    fin >> n >> m;
    vector<bool> bi (4*m*m);
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            bi[i*i + j*j] = true;

    int num_printed = 0;
    vector<vector<int> > ans;
    for (int i = 0; i <= (4*m*m); i++)
    {
        if (!bi[i]) continue;
        for (int diff = 1; diff < (4*m*m)/n; diff++)
        {
            int num_found = 1, curr = i;
            while (num_found < n)
            {
                curr += diff;
                if (!bi[curr]) break;
                num_found++;
            }
            if (num_found < n) continue;
            vector<int> tmp;
            tmp.push_back(i); tmp.push_back(diff);
            ans.push_back(tmp);
            if (num_printed == 10000)
            {
                print_all(ans);
                return 0;
            }
        }
    }
    print_all(ans);
}
