#include<fstream>
#include<vector>
#include<utility>
#include<functional>
#include<iostream>
using namespace std;

struct field
{
    bool walls[4]; // N S E W
    int container;
    bool visited;
};

int n, k, r;
struct field farm[101][101];
vector<pair<int, int> > cows;
int numcontainers = 0;

void floodfill(int x, int y)
{
    if (farm[x][y].visited)
        return;
    farm[x][y].visited = true;
    farm[x][y].container = numcontainers;
    if (x != 1 && !farm[x][y].walls[0])
        floodfill(x-1, y);
    if (x != n && !farm[x][y].walls[1])
        floodfill(x+1, y);
    if (y != n && !farm[x][y].walls[2])
        floodfill(x, y+1);
    if (y != 1 && !farm[x][y].walls[3])
        floodfill(x, y-1);
}

int main()
{
    ifstream fin ("countcross.in");
    fin >> n >> k >> r;

    for (int i = 0; i < r; i++)
    {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
        {
            farm[x1][y1].walls[0] = true;
            farm[x2][y2].walls[1] = true;
        }
        if (x1 < x2)
        {
            farm[x1][y1].walls[1] = true;
            farm[x2][y2].walls[0] = true;
        }
        if (y1 < y2)
        {
            farm[x1][y1].walls[2] = true;
            farm[x2][y2].walls[3] = true;
        }
        if (y1 > y2)
        {
            farm[x1][y1].walls[3] = true;
            farm[x2][y2].walls[2] = true;
        }
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        fin >> x >> y;
        cows.push_back(make_pair(x, y));
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!farm[i][j].visited) {
                floodfill(i, j);
                numcontainers++;
            }

    int n = 0;
    for (int i = 0; i < cows.size(); i++)
    {
        int sec1 = farm[cows[i].first][cows[i].second].container;
        for (int j = 0; j < cows.size(); j++)
        {
            int sec2 = farm[cows[j].first][cows[j].second].container;
            if (sec1 != sec2)
                n++;
        }
    }
    n /= 2;

    ofstream fout ("countcross.out");
    fout << n << endl;
}
