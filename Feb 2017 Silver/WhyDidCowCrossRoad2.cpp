#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int n, k, b;
    vector<int> broken;

    ifstream fin ("maxcross.in");
    fin >> n >> k >> b;
    for (int i = 0; i < b; i++)
    {
        int tmp;
        fin >> tmp;
        broken.push_back(tmp);
    }

    int min = 1000001;
    for (int i = 1; i <= n-k+1; i++)
    {
        int end = i+k-1;
        int n = 0;
        for (int j = 0; j < broken.size(); j++)
            if (broken[j] >= i && broken[j] <= end)
                n++;
        if (n < min) min = n;
    }

    ofstream fout ("maxcross.out");
    fout << min << endl;
}
