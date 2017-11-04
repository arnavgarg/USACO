/*
ID: arnavga1
PROG: palsquare
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

string convBase(int n, int b);
bool checkPal(string n);

int main()
{
    ifstream fin ("palsquare.in");
    ofstream fout ("palsquare.out");
    int B;
    fin >> B;

    for (int i = 1; i <= 300; i++)
    {
        string n = convBase(i, B);
        string n2 = convBase(i*i, B);
        if (checkPal(n2))
            fout << n << " " << n2 << endl;
    }
}

string convBase(int n, int b)
{
    string ans = "";
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    while (n != 0)
    {
        int a = n/b;
        int rem = n - (a * b);
        ans.insert(ans.begin(), digits[rem]);
        n = a;
    }
    return ans;
}

bool checkPal(string n)
{
    string half_1, half_2;
    if (n.size() % 2 == 0)
    {
        half_1 = n.substr(0, n.size()/2);
        half_2 = n.substr(n.size()/2, n.size()/2);
        reverse(half_2.begin(), half_2.end());
        if (half_1 == half_2) return true;
    }
    else 
    {
        half_1 = n.substr(0, n.size()/2);
        half_2 = n.substr(n.size()/2 + 1, n.size()/2);
        reverse(half_2.begin(), half_2.end());
        if (half_1 == half_2) return true;
    }
    return false;
}