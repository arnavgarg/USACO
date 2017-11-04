/*
ID: arnavga1
PROG: dualpal
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

string convBase(int n, int b);
bool checkPal(string s);

int main()
{
    ifstream fin ("dualpal.in");
    ofstream fout ("dualpal.out");
    int N, S;
    fin >> N >> ws >> S;

    int count = 0;
    for (int i = S + 1; count != N; i++)
    {
        int numBases = 0;
        for (int j = 2; j < 11; j++)
            if (checkPal(convBase(i, j)))
                numBases++;
        if (numBases >= 2)
        {
            count++;
            fout << i << endl;
        }
    }
}

string convBase(int n, int b)
{
    string ans = "";
    char digits[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    while (n != 0)
    {
        int rem = n % b;
        ans.insert(ans.begin(), digits[rem]);
        n /= b;
    }
    return ans;
}

bool checkPal(string s)
{
    string half_1 = s.substr(0, s.size()/2);
    string half_2 = s.size() % 2 == 0 ? s.substr(s.size()/2, s.size()/2) : s.substr(s.size()/2 + 1, s.size()/2);
    reverse(half_2.begin(), half_2.end());
    if (half_1 == half_2)
        return true;
    else 
        return false;
}