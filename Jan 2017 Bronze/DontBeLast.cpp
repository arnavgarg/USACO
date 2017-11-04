#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int findName(string name, string names[])
{
    for (int i = 0; i < 7; i++)
        if (names[i] == name)
            return i;
}

int main()
{
    string names[] = {
        "Bessie",
        "Elsie",
        "Daisy",
        "Gertie",
        "Annabelle",
        "Maggie",
        "Henrietta"    
    };
    int n;
    int milk[] = {0, 0, 0, 0, 0, 0, 0};

    ifstream fin ("notlast.in");
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int amt_milk;
        fin >> name >> amt_milk;
        milk[findName(name, names)] += amt_milk;
    }

    int min = milk[0];
    int sec_min = 10001;
    for (int i = 0; i < 7; i++)
    {
        if (milk[i] < min) 
        {
            sec_min = min;
            min = milk[i];
        }
        if (milk[i] > min && milk[i] < sec_min) 
            sec_min = milk[i];
    }

    int count = 0;
    string name;
    for (int i = 0; i < 7; i++)
        if (milk[i] == sec_min)
        {
            count++;
            name = names[i];
        }

    ofstream fout ("notlast.out");
    if (count == 1)
        fout << name << endl;
    else 
        fout << "Tie" << endl;
}