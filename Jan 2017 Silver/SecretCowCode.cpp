#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string shift(string s)
{
    string str = "";
    str += s[s.size()-1];
    for (int i = 0; i < s.size()-1; i++)
        str += s[i];
    return str;
}

int main()
{
    string s;
    long long n;
    ifstream fin ("cowcode.in");
    ofstream fout("cowcode.out");

    fin >> s >> n;
    while (s.size() < n)
        s += shift(s);
    fout << s[n-1] << endl;
}