/*
ID: arnavga1
PROG: transform
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

vector<string> rotate(vector<string> original, int N);
vector<string> reflect(vector<string> original, int N);
bool compareVectors(vector<string> vec_1, vector<string> vec_2, int N);

int main()
{
    ifstream fin ("transform.in");
    ofstream fout ("transform.out");
    int N;
    fin >> N;

    vector<string> original;
    vector<string> transformed;
    for (int i = 0; i < N; i++)
    {
        string temp;
        fin >> temp;
        original.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        string temp;
        fin >> temp;
        transformed.push_back(temp);
    }

    int trans_id;
    if (compareVectors(rotate(original, N), transformed, N)) // 90° rotation
        trans_id = 1; 
    else if (compareVectors(rotate(rotate(original, N), N), transformed, N)) // 180° rotation
        trans_id = 2; 
    else if (compareVectors(rotate(rotate(rotate(original, N), N), N), transformed, N)) // 270° rotation
        trans_id = 3;
    else if (compareVectors(reflect(original, N), transformed, N)) // horizontal rotation
        trans_id = 4;
    else if (compareVectors(reflect(rotate(original, N), N), transformed, N)) // combination case 1
        trans_id = 5;
    else if (compareVectors(reflect(rotate(rotate(original, N), N), N), transformed, N)) // combination case 2
        trans_id = 5;
    else if(compareVectors(reflect(rotate(rotate(rotate(original, N), N), N), N), transformed, N)) // combination case 2
        trans_id = 5;
    else if(compareVectors(original, transformed, N))  // no change
        trans_id = 6;
    else 
        trans_id = 7;
    fout << trans_id << endl;
    
}

vector<string> rotate(vector<string> original, int N)
{
    vector<string> transform (N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            transform[i][j] = original[N-j-1][i];
    return transform;
}

vector<string> reflect(vector<string> original, int N)
{
    vector<string> transform (N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            transform[i][j] = original[i][N-j-1];
    return transform;
}

bool compareVectors(vector<string> vec_1, vector<string> vec_2, int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (vec_1[i][j] != vec_2[i][j]) return false;
    return true;
}