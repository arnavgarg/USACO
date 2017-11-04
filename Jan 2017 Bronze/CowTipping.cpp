#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<string> flip(vector<string> cows, int rows, int cols)
{
    int n = cows.size();
    cout << "test1" << "   ";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (cows[i][j] == '0')
                cows[i][j] = '1';
            else 
                cows[i][j] = '0';
    return cows;
}

bool checkRow(string row)
{
    for (int i = 0; i < row.size(); i++)
        if (row[i] != '0')
            return false;
    return true;
}

int main()
{
    int n; 
    vector<string> cows;

    ifstream fin ("cowtip.in");
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        fin >> temp;
        cows.push_back(temp);
    }

    int moves = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (!checkRow(cows[i]))
        {
            for (int j = n-1; j >=0; j--)
            {
                if (cows[i][j] != '0')
                {
                    cows = flip(cows, i+1, j+1);
                    moves++;
                }
            }
        }
    }

    ofstream fout ("cowtip.out");
    fout << moves << endl;
}