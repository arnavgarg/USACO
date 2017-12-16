/*
ID: your id
PROG: ride
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int compute(string input) {
    int total = 1;
    for (int i = 0; i < input.size(); i++)
        total *= input[i]-'A'+1;
    return total;
}

int main() {
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    string comet, group;
    fin >> comet >> group;

    if (compute(comet) % 47 == compute(group) % 47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
}
