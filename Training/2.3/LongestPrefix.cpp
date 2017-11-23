/*
ID: arnavga1
TASK: prefix
LANG: C++11
 */

#include <fstream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> prims;
    ifstream fin("prefix.in");

    string tmp;
    fin >> tmp;
    while (tmp != ".") {
        prims.insert(tmp);
        fin >> tmp;
    }
    string s = "";
    char c;
    while (fin.get(c))
        if (c != '\n')
            s += c;

    bool ans[s.length()+1];
    ans[0] = true;
    int last = 0;
    for (int i = 1; i <= s.length(); i++) {
        ans[i] = false;
        for (string prim : prims)
            if (prim.length() <= i && ans[i-prim.length()] && prim == s.substr(i-prim.length(), prim.length())) {
                ans[i] = true;
                last = i;
                break;
            }
    }

    ofstream fout("prefix.out");
    fout << last << endl;
}
