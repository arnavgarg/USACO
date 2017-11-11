/*
ID: arnavga1
TASK: holstein
LANG: C++
 */

#include <cstdio>
#include <cmath>
#include <algorithm>

int main()
{
    int v, g, reqs[25], feeds[15][25];

    FILE* in = fopen("holstein.in", "r");
    fscanf(in, "%d", &v);
    for (int i = 0; i < v; i++)
        fscanf(in, "%d", reqs+i);
    fscanf(in, "%d", &g);
    for (int i = 0; i < g; i++)
        for (int j = 0; j < v; j++)
            fscanf(in, "%d", feeds[i]+j);
    fclose(in);

    int minfeeds = 16;
    bool ans[15] = {true};

    int combos = pow(2, g);
    for (int i = 1; i < combos; i++) {
        bool used[15] = {false};
        int n = 0;
        int sum[25] = {0};
        for (int j = 0; j < g; j++) {
            if ((i >> j) & 1) {
                for (int k = 0; k < v; k++)
                    sum[k] += feeds[j][k];
                used[j] = true;
                n++;
            }
        }
        bool done = true;
        for (int j = 0; j < v; j++)
            if (sum[j] < reqs[j]) {
                done = false;
                break;
            }
        if (n < minfeeds && done) {
            minfeeds = n;
            std::copy(used, used+15, ans);
        }
    }

    FILE* out = fopen("holstein.out", "w");
    fprintf(out, "%d", minfeeds);
    for (int i = 0; i < g; i++)
        if (ans[i])
            fprintf(out, " %d", i+1);
    fprintf(out, "\n");
    fclose(out);
}
