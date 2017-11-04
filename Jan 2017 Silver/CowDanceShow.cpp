#include<iostream>
#include<fstream>
using namespace std;

void shift(int* &curr, int times[], int k, int a, int cows_used, int n, int &b)
{
    for (int i = a; i < k-1; i++)
        curr[i] = curr[i+1];
    if (cows_used != n)
        curr[k-1] = times[cows_used-1];
    else
    { 
        curr[k-1] = 0;
        b++;
    }
}

int main()
{
    ifstream fin ("cowdance.in");
    int n, tmax;
    fin >> n >> tmax;
    int times[n];
    for (int i = 0; i < n; i++)
        fin >> times[i];
    
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k = i;
        int curr[k];
        for (int j = 0; j < k; j++)
            curr[j] = times[j];
        int t = 0, cows_used = n - k, b;
        while (t < tmax)
        {
            t++;
            for (int a = 0; a < k; a++)
                curr[a]--;
            for (int a = 0; a < k; a++)
            {
                if (curr[a] == 0 && k-a < b)
                    shift(curr, times, k, a, cows_used, n, b);
                cows_used++;
            }
        }
        if (t == tmax) break;
    }

    ofstream fout ("cowdance.out");
    fout << k << endl;
}