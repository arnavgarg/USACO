/*
ID: arnavga1
PROG: crypt1
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool checkInVector(string s, vector<int> vec);

int main()
{
    ifstream fin ("crypt1.in");
    ofstream fout ("crypt1.out");
    int N;
    fin >> N;
    vector<int> digits;
    for (int i = 0; i < N; i++)
    {
        int temp;
        fin >> temp >> ws;
        digits.push_back(temp);
    }

    int count = 0;
    int r1, r2;
    for (int i = 100; i < 1000; i++)
    {
        if (!checkInVector(to_string(i), digits)) continue;
        for (int j = 10; j < 100; j++)
        {
            string j_str = to_string(j);
            if (!checkInVector(j_str, digits)) continue;
            int j_1 = j_str[0] - '0';
            int j_2 = j_str[1] - '0';
            if ((!checkInVector(to_string(j_1 * i), digits)) || to_string(j_1 * i).size() != 3) continue;
            if ((!checkInVector(to_string(j_2 * i), digits)) || to_string(j_2 * i).size() != 3) continue;
            if (checkInVector(to_string(i * j), digits) && to_string(i*j).size() == 4) 
            {
                count++;
            }
        }
    }
    fout << count << endl;
}

bool checkInVector(string s, vector<int> vec)
{
    int match_count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (find(vec.begin(), vec.end(), s[i] - '0') != vec.end())
            match_count++;
    }
    if (match_count == s.size()) {return true;}
    else return false;
}