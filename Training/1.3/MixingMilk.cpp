/*
ID: arnavga1
PROG: milk
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

bool compareFarmers(vector<int> f1, vector<int> f2) {return f1[0] < f2[0];}

int main()
{
    ifstream fin ("milk.in");
    ofstream fout ("milk.out");
    int N, M;
    fin >> N >> M;

    vector<vector<int> > farmers;
    for (int i = 0; i < M; i++)
    {
        int temp_1, temp_2;
        vector<int> temp;
        fin >> temp_1 >> ws >> temp_2;
        temp.push_back(temp_1);
        temp.push_back(temp_2);
        farmers.push_back(temp);
    }
    sort(farmers.begin(), farmers.end(), compareFarmers);

    int total_milk = 0, i = 0, cost = 0;
    while (total_milk != N)
    {
        if (total_milk + farmers[i][1] < N)
        {
            cost += farmers[i][0] * farmers[i][1];
            total_milk += farmers[i][1];
            i++;
        }
        else
        {
            cost += (N - total_milk) * farmers[i][0];
            total_milk = N;
        }
    }
    fout << cost << endl;
}
