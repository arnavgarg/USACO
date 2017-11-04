/*
ID: arnavga1
PROG: milk2
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

bool wayToSort(vector<int> i, vector<int> j) { return i[0] < j[0]; }
int findLongestMilking(vector<vector<int> >);
int findLongestMilkless(vector<vector<int> >);

int main()
{
    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");
    int N;
    fin >> N;

    vector<vector<int> > times;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
		int n1, n2;
        fin >> n1 >> ws >> n2;
		temp.push_back(n1); temp.push_back(n2);
		times.push_back(temp);
    }
    sort(times.begin(), times.end(), wayToSort);  

    int start = times[0][0];
    int end = times[0][1];
    int length_milking = end - start;
    int max_length_milking = length_milking;
    int length_break = 0, max_length_break = 0;

    for (int i = 1; i < times.size(); i++)
    {
        if (end >= times[i][0])
        {
            if (end < times[i][1]) end = times[i][1];
            length_milking = end - start;
            if (length_milking > max_length_milking) max_length_milking = length_milking;
        }
        else
        {
            length_break = times[i][0] - end;
            if (length_break > max_length_break) max_length_break = length_break;
            start = times[i][0];
            end = times[i][1];
            length_milking = end - start;
        }
    }
    fout << max_length_milking << " " << max_length_break << endl;
}

