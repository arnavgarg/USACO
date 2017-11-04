/*
ID: arnavga1
PROG: friday
LANG: C++
*/

#include<iostream>
#include<fstream>
using namespace std;

bool isLeapYear(int year);

int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int numYears;
    fin >> numYears;

    int calenderDays = 0;
    int counter[7] = {0, 0, 0, 0, 0, 0, 0};
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leapDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int end = 1900 + numYears;
    for (int i = 1900; i < end; i++)
    {
       for (int j = 0; j < 12; j++)
       {
           int day = (calenderDays + 12) % 7;
           counter[day]++;
           calenderDays += isLeapYear(i) ? leapDays[j] : days[j]; 
       }
    }

    fout << counter[5] << " ";
    fout << counter[6] << " ";
    fout << counter[0] << " ";
    fout << counter[1] << " ";
    fout << counter[2] << " ";
    fout << counter[3] << " ";
    fout << counter[4] << endl;
}

bool isLeapYear(int year)
{
    if (year % 100 == 0)
        return year % 400 == 0;
    else
        return year % 4 == 0;
}