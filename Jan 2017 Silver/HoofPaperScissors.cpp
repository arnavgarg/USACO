#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

void check(char move, int &h, int &p, int &s)
{
    if (move == 'H')
        h++;
    else if (move == 'P')
        p++;
    else if (move == 'S')
        s++;
}

int main()
{
    ifstream fin ("hps.in");
    ofstream fout ("hps.out");

    int n;
    fin >> n;
    char moves[n];
    for (int i = 0; i < n; i++)
        fin >> moves[i];

    int max_wins = 0;
    for (int i = 1; i < n; i++)
    {
        int h1 = 0, p1 = 0, s1 = 0;
        int h2 = 0, p2 = 0, s2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (j < i)
                check(moves[j], h1, p1, s1);
            else
                check(moves[j], h2, p2, s2);
        }
        cout << h1 << " " << p1 << " " << s1 << "   " << h2 << " " << p2 << " " << s2 << endl;
        int wins = max(max(h1, p1), max(p1, s1)) + max(max(h2, p2), max(p2, s2));
        if (wins > max_wins) max_wins = wins;
    } 
    fout << max_wins << endl;
}