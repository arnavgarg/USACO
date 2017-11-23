/*
ID: arnavga1
TASK: nocows
LANG: C++11
 */

#include <cstdio>

int main() {
    int n, k;
    FILE* in = fopen("nocows.in", "r");
    fscanf(in, "%d %d", &n, &k);

    long long dp[201][101] = {{0}};
    for (int j = 1; j <= k; j++)
        dp[1][j] = 1;
    for (int i = 3; i <= n; i += 2)
        for (int j = 1; j <= k; j++)
            for (int t = 1; t <= i-2; t += 2) {
                dp[i][j] += dp[t][j-1] * dp[i-1-t][j-1];
                dp[i][j] %= 9901;
            }

    FILE* out = fopen("nocows.out", "w");
    fprintf(out, "%lld\n", (dp[n][k] - dp[n][k-1] + 9901) % 9901);
    fclose(out);
}
