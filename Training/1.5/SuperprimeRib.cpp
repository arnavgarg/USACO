/*
ID: arnavga1
PROG: sprime
LANG: C++
*/

#include<fstream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int N;
vector<int> sprimes;

bool is_prime(int n)
{
    int mx = sqrt(n);
    for (int i = 2; i <= mx; i++)
        if (n % i == 0)
            return false;
    return true;
}

void solve(int curr, int num_found)
{
    for (int i = 0; i < 10; i++)
    {
        int n = curr*10 + i;
        if (is_prime(n))
        {
            if (num_found+1 != N)
            {
                solve(n, num_found+1);
            }
            else
                sprimes.push_back(n);
        }
    }
}

int main()
{
    ifstream fin ("sprime.in");
    fin >> N;

    int primes[] = {2, 3, 5, 7};
    for (int i = 0; i < 4; i++)
        solve(primes[i], 1);

    sort(sprimes.begin(), sprimes.end());
    ofstream fout ("sprime.out");
    for (int i = 0; i < sprimes.size(); i++)
        fout << sprimes[i] << endl;
}
