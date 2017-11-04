/*
ID: arnavga1
PROG: castle
LANG: C++11
*/

#include<fstream>
#include<vector>
#include<utility>
#include<string>
using namespace std;

struct module
{
    bool walls[4]; // W, N, E, S
    bool visited;
    int room;
};

vector<vector<struct module> > modules (50, vector<struct module> (50));
vector<vector<struct module> > rooms (2501);

int m, n;
int numrooms;
int maxsize;
pair<string, int> maxmerge;

void floodfill(int x, int y)
{
    if (modules[x][y].visited)
        return;
    modules[x][y].visited = true;
    modules[x][y].room = numrooms;

    rooms[numrooms].push_back(modules[x][y]);
    if (!modules[x][y].walls[0])
        floodfill(x, y-1);
    if (!modules[x][y].walls[1])
        floodfill(x-1, y);
    if (!modules[x][y].walls[2])
        floodfill(x, y+1);
    if (!modules[x][y].walls[3])
        floodfill(x+1, y);
}

void merge(int x, int y)
{
    if (modules[x][y].walls[1] && x != 0)
    {
        int size = rooms[modules[x][y].room].size() + rooms[modules[x-1][y].room].size();
        if (size > maxmerge.second && (modules[x][y].room != modules[x-1][y].room))
        {
            maxmerge.first = to_string(x+1) + " " + to_string(y+1) + " N";
            maxmerge.second = size;
        }
    }
    if (modules[x][y].walls[2] && y != m-1)
    {
        int size = rooms[modules[x][y].room].size() + rooms[modules[x][y+1].room].size();
        if (size > maxmerge.second && (modules[x][y].room != modules[x][y+1].room))
        {
            maxmerge.first = to_string(x+1) + " " + to_string(y+1) + " E";
            maxmerge.second = size;
        }
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!modules[i][j].visited)
            {
                floodfill(i, j);
                if (rooms[numrooms].size() > maxsize)
                    maxsize = rooms[numrooms].size();
                numrooms++;
            }

    for (int i = 0; i < m; i++)
        for (int j = n-1; j >= 0; j--)
            merge(j, i);
}

int main()
{
    ifstream fin ("castle.in");
    fin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int walls;
            fin >> walls;
            for (int k = 0; k < 4; k++)
                if ((walls >> k) & 1)
                    modules[i][j].walls[k] = true;
                else
                    modules[i][j].walls[k] = false;
        }

    solve();

    ofstream fout ("castle.out");
    fout << numrooms << endl;
    fout << maxsize << endl;
    fout << maxmerge.second << endl;
    fout << maxmerge.first << endl;
}
