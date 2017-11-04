#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int findWins(string one, string two, string three, vector<vector<int> > games)
{
    int wins = 0;
    for (int i = 0; i < games.size(); i++)
    {
        string p1, p2;
        switch(games[i][0])
        {
            case 1: p1 = one;
                    break;
            case 2: p1 = two;
                    break;
            case 3: p1 = three;
                    break;
        }
        switch(games[i][1])
        {
            case 1: p2 = one;
                    break;
            case 2: p2 = two;
                    break;
            case 3: p2 = three;
                    break;
        }
        if ((p1 == "hoof" && p2 == "scissors") || (p1 == "paper" && p2 == "hoof") || (p1 == "scissors" && p2 == "paper"))
            wins++;
    }
    return wins;
}

int main()
{
    int n;
    vector<vector<int> > games;
    
    ifstream fin ("hps.in");
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int t1, t2;
        fin >> t1 >> t2;
        temp.push_back(t1);
        temp.push_back(t2);
        games.push_back(temp);
    }

    int max = findWins("hoof", "paper", "scissors", games);
    if (findWins("hoof", "scissors", "paper", games) > max) 
        max = findWins("hoof", "scissors", "paper", games);
    if (findWins("paper", "hoof", "scissors", games) > max) 
        max = findWins("paper", "hoof", "scissors", games);
    if (findWins("paper", "scissors", "hoof", games) > max) 
        max = findWins("paper", "scissors", "hoof", games);
    if (findWins("scissors", "hoof", "paper", games) > max) 
        max = findWins("scissors", "hoof", "paper", games);
    if (findWins("scissors", "paper", "hoof", games) > max) 
        max = findWins("scissors", "paper", "hoof", games);
    
    ofstream fout ("hps.out");
    fout << max << endl;
}