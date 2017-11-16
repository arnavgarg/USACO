/*
ID: arnavga1
TASK: subset
LANG: C++11
 */

#include <cstdio>

int main() {
    int n;
    FILE* in = fopen("subset.in", "r");
    fscanf(in, "%d", &n);
    fclose(in);

    int sum = 0;
    for (int i = 0; i < n+1; i++)
        sum += i;

    long long ans = 0;
    if (sum % 2 == 0) {
        sum /= 2;
        int subsets[n+1][sum+1];
        for (int i = 0; i < n+1; i++)
            subsets[i][0] = 0;
        for (int i = 0; i < sum+1; i++)
            subsets[0][i] = 0;

        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < sum+1; j++) {
                subsets[i][j] = 0;
                if (!(i > j)) {
                    if (i == j) {
                        subsets[i][j] = 1;
                        continue;
                    }
                    for (int k = 1; k < i; k++) {
                        subsets[i][j] += subsets[k][j-i];
                    }
                }
            }
        }

        for (int i = 1; i < n+1; i++)
            ans += subsets[i][sum];
    }

    FILE* out = fopen("subset.out", "w");
    fprintf(out, "%llu\n", ans/2);
    fclose(out);
}
