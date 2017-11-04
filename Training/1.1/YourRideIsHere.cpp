/*
ID: arnavga1
PROG: ride
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int computeValue(string input);
bool canGo(int cometVal, int groupVal);

int main()
{
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    string comet, group;
    fin >> comet >> group;

    bool isGoing = canGo(computeValue(comet), computeValue(group));
    if (isGoing)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
}

int computeValue(string input)
{
    int total = 1;
    for (int i = 0; i < input.size(); i++)
        total *= input.at(i) - 'A' + 1;
    return total;
}

bool canGo(int cometVal, int groupVal)
{
    if ((cometVal % 47) == (groupVal % 47))
        return true;
    return false;
}
