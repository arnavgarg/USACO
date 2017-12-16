/*
ID: arnavga1
TASK: money
LANG: C++11
 */

#include <cstdio>
#include <vector>
using namespace std;

int main() {
    FILE* in = fopen("money.in", "r");
    FILE* out = fopen("money.out", "w");

    int v, n;
    fscanf(in, "%d %d", &v, &n);
    int coins[v];
    for (int i = 0; i < v; i++) fscanf(in, "%d", coins+i);

    long long dp[n+1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) dp[i] = 0;
    for (int i = 0; i < v; i++)
        for (int j = coins[i]; j <= n; j++)
            dp[j] += dp[j-coins[i]];

    fprintf(out, "%lld\n", dp[n]);
    fclose(out);
}
