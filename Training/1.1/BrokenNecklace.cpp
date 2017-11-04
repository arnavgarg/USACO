/*
ID: arnavga1
PROG: beads
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int numBeads;
    string pattern;
    fin >> numBeads >> pattern;
    int max = 0;
    for (int i = 0; i < numBeads; i++)
    {
        string sample_str;
        if (i != 0)
        {
            string str_1 = pattern.substr(i, numBeads - i);
            string str_2 = pattern.substr(0, i);
            sample_str = str_1 + str_2;
        }
        else 
            sample_str = pattern;
        int count = 0;
        // counts beads at the front 
        char frontcolor; int n=0;
        do 
        {
            frontcolor = sample_str.at(n); n++;
        } while (frontcolor == 'w' && n < numBeads-1);
        if (frontcolor == ' ') frontcolor = 'w';
        for (int j = 0; j < numBeads-1; j++)
        {
            char bead = sample_str.at(j);
            if (bead == frontcolor || bead == 'w')
            {
                count++;
            }
            else 
                break;
        } 
        // counts beads at the back 
        char backcolor; n=numBeads-1;
        do 
        {
            if (n == 0) frontcolor = 'w';
            backcolor = sample_str.at(n); n--;
        } while (backcolor == 'w' && n != 0);
        if (backcolor == ' ') backcolor = 'w';
        for (int j = numBeads - 1; j > 0; j--)
        {
            char bead = sample_str.at(j);
            if (bead == backcolor || bead == 'w')
            {
                count++;
            }
            else
                break;
        }
        if (count > max) max = count;
        if (max > numBeads) max = numBeads;
    }
    fout << max << endl;
}
