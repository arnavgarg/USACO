/*
ID: arnavga1
PROG: barn1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> findGaps(vector<int> stalls, int num_gaps);

int main()
{
    ifstream fin ("barn1.in");
    ofstream fout ("barn1.out");
    int num_boards, num_stalls, num_cows;
    fin >> num_boards >> ws >> num_stalls >> ws >> num_cows;

    vector<int> stalls;
    for (int i = 0; i < num_cows; i++)
    {
        int temp;
        fin >> temp;
        stalls.push_back(temp);
    }
    sort(stalls.begin(), stalls.end());

    vector<int> gaps = findGaps(stalls, num_boards - 1);
    for (int i = 0; i < gaps.size(); i++)
        cout << gaps[i] << endl;

    int counter = num_stalls;
    for (int i = 0; i < gaps.size(); i++)
        counter -= gaps[i] - 1;
    cout << counter << endl;
    counter -= (stalls[0] - 1) + (num_stalls - stalls[stalls.size() - 1]);
    cout << counter << endl;
    fout << counter << endl;
}

vector<int> findGaps(vector<int> stalls, int num_gaps) 
{
    vector<int> gaps;
    if (num_gaps == 0) return gaps;
    for (int i = 0; i < stalls.size()-1; i++)
    {
        if (gaps.size() < num_gaps)
        {
            gaps.push_back(stalls[i+1] - stalls[i]);
            sort(gaps.begin(), gaps.end());
        }
        else 
        {
            if (stalls[i+1] - stalls[i] > gaps[0])
            {
                gaps.erase(gaps.begin());
                gaps.insert(gaps.begin(), stalls[i+1] - stalls[i]);
                sort(gaps.begin(), gaps.end());
            }
        }
    }
    return gaps;
}