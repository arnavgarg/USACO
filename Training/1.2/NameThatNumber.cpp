/*
ID: arnavga1
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string serializeName(string name);

int main()
{
    ifstream fin ("namenum.in"), fdict ("dict.txt");
    ofstream fout ("namenum.out");
    string serial;
    fin >> serial;

    string dict;
    bool found = false;
    while (fdict >> dict)
        if (serializeName(dict) == serial)
        {
            fout << dict << endl;
            found = true;
        }
    if (!found) fout << "NONE" << endl;  
}

string serializeName(string name)
{
    string serial ("");
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == 'Q' || name[i] == 'Z')
            return "1";
        else if (name[i] < 'Q')
            serial += (name[i] - 'A') / 3 + '2';
        else 
            serial += (name[i] - 'Q') / 3 + '7';
    }
    return serial;
}
