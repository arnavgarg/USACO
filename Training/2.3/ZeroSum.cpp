/*
ID: arnavga1
TASK: zerosum
LANG: C++11
 */

#include <fstream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int n;
set<string> ans;

void dfs(int next, int sum, int num, string s, int sign) {
    if (next >= n) {
        if (sum+sign*num == 0)
            ans.insert(s);
        return;
    }

    dfs(next+1, sum, num*10+(next+1), s+" "+to_string(next+1), sign);
    dfs(next+1, sum+sign*num, next+1, s+"+"+to_string(next+1), 1);
    dfs(next+1, sum+sign*num, next+1, s+"-"+to_string(next+1), -1);
}

int main() {
    ifstream fin("zerosum.in");
    fin >> n;
    dfs(1, 0, 1, "1", 1);
    ofstream fout("zerosum.out");
    for (string s : ans)
        fout << s << endl;
}
