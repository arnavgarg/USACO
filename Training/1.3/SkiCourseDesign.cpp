/* 
ID: arnavga1
PROG: skidesign
LANG: C++
*/

#include<fstream>
using namespace std;
#define MAX_N 1000

int N, heights[MAX_N];

int main()
{
    ifstream fin ("skidesign.in");
    fin >> N;
    for (int i = 0; i < N; i++)
        fin >> heights[i];
    
    int min_cost = 10000000;
    for (int i = 0; i <= 83; i++)
    {
        int cost = 0;
        for (int j = 0; j < N; j++)
        {
            int x = 0;
            if (heights[j] < i)
                x = i - heights[j];
            else if (heights[j] > i+17)
                x = heights[j] - (i+17);
            cost += x*x;
        }
        if (cost < min_cost) min_cost = cost;
    }

    ofstream fout ("skidesign.out");
    fout << min_cost << endl;
}