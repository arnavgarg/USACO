/*
ID: arnavga1
PROG: gift1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int getNameIndex(vector<string> names, string nameToFind);

int main()
{
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    int NP;
    fin >> NP;

    vector<string> names;
    for (int i = 0; i < NP; i++)
    {
        string name;
        fin >> name;
        names.push_back(name);
    }

    vector<int> money;
    for (int i = 0; i < NP; i++)
        money.push_back(0);

    for (int i = 0; i < NP; i++)
    {
        string curName;
        fin >> curName;
        int index = getNameIndex(names, curName);
        
        int amountToGiveTotal, numPeopleToGive, amountToGiveEach, amountRemaining;
        fin >> amountToGiveTotal >> ws >> numPeopleToGive;
        if (numPeopleToGive != 0)
            amountToGiveEach = amountToGiveTotal / numPeopleToGive;
        else 
            amountToGiveEach = 0;
        amountRemaining = amountToGiveTotal - (amountToGiveEach * numPeopleToGive);

        money[index] -= amountToGiveTotal - amountRemaining;
        for (int j = 0; j < numPeopleToGive; j++)
        {
            string recipientName;
            fin >> recipientName;
            index = getNameIndex(names, recipientName);
            money[index] += amountToGiveEach;
        }
    }

    for (int i = 0; i < NP; i++)
    {
        fout << names[i] << " " << money[i] << endl;
    }
}

int getNameIndex(vector<string> names, string nameToFind)
{
    for (int i = 0; i < names.size(); i++)
    {
        if (names[i] == nameToFind)
            return i;
    }
}