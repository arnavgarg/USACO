/*
ID: arnavga1
PROG: pprime
LANG:C++
*/

#include<fstream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int a, b;
vector<int> pprimes;

bool isPrime(int n)
{
    int mx = sqrt(n);
    for (int i = 2;  i <= mx; i++)
        if (n % i == 0)
            return false;
    return true;
}

void solve()
{
    // 1/2 digits
    for (int i = 1; i < 10; i++)
    {
        int n1 = i;
        int n2 = i*10 + i;
        if (n1 != 1 && n1 >= a && n1 <= b && isPrime(n1))
            pprimes.push_back(n1);
        if (n2 >= a && n2 <= b && isPrime(n2))
            pprimes.push_back(n2);
    }

    // for 3/4 digits
    if (a < 10000)
        for (int i = 1; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                int n3 = i*100 + j*10 + i;
                int n4 = i*1000 + j*100 + j*10 + i;
                if (n3 >= a && n3 <= b && isPrime(n3))
                    pprimes.push_back(n3);
                if (n4 >= a && n4 <= b && isPrime(n4))
                    pprimes.push_back(n4);
            }

    // for 5/6 digits
    if (a < 1000000)
        for (int i = 1; i < 10; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++)
                {
                    int n5 = i*10000 + j*1000 + k*100 + j*10 + i;
                    int n6 = i*100000 + j*10000 + k*1000 + k*100 + j*10 + i;
                    if (n5 >= a && n5 <= b && isPrime(n5))
                        pprimes.push_back(n5);
                    if (n6 >= a && n6 <= b && isPrime(n6))
                        pprimes.push_back(n6);
                }

    // for 7/8 digits
    if (a < 100000000)
        for (int i = 1; i < 10; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++)
                    for (int m = 0; m < 10; m++)
                    {
                        int n7 = i*1000000 + j*100000 + k*10000 + m*1000 + k*100 + j*10 + i;
                        int n8 = i*10000000 + j*1000000 + k*100000 + m*10000 + m*1000 + k*100 + j*10 + i;
                        if (n7 >= a && n7 <= b && isPrime(n7))
                            pprimes.push_back(n7);
                        if (n8 >= a && n8 <= b && isPrime(n8))
                            pprimes.push_back(n8);
                    }
}

int main()
{
    ifstream fin ("pprime.in");
    fin >> a >> b;

    solve();
    sort(pprimes.begin(), pprimes.end());

    ofstream fout ("pprime.out");
    for (int i = 0; i < pprimes.size(); i++)
        fout << pprimes[i] << endl;
}
