/*
ID: arnavga1
TASK: lamps
LANG: C++11
 */

#include <cstdio>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>

int n, c;
std::vector<int> on;
std::vector<int> off;

void apply(int change, std::vector<int> &lamps) {
    if (change == 0) {
        for (int i = 1; i < n+1; i++)
            lamps[i] = !lamps[i];
    } else if (change == 1) {
        for (int i = 1; i < n+1; i += 2)
            lamps[i] = !lamps[i];
    } else if (change == 2) {
        for (int i = 2; i < n+1; i += 2)
            lamps[i] = !lamps[i];
    } else if (change == 3) {
        for (int i = 1; i < n+1; i += 3)
            lamps[i] = !lamps[i];
    }
}

bool check(std::vector<int> &lamps) {
    for (int i : on)
        if (!lamps[i])
            return false;
    for (int i : off)
        if (lamps[i])
            return false;
    return true;
}

long long calc(std::vector<int> &lamps) {
    long long num = 0;
    for (int i = n; i > 0; i--)
        num += lamps[i] * pow(2, n-i);
    return num;
}

int main() {
    FILE* in = fopen("lamps.in", "r");
    fscanf(in, "%d\n%d", &n, &c);
    while (true) {
        int num;
        fscanf(in, "%d", &num);
        if (num == -1) break;
        on.push_back(num);
    }
    while (true) {
        int num;
        fscanf(in, "%d", &num);
        if (num == -1) break;
        off.push_back(num);
    }
    fclose(in);

    std::vector<std::vector<int>> ans;
    for (int i = 0; i < 16; i++) {
        std::vector<int> lamps(n+1, true);
        int changes = 0;
        for (int j = 0; j < 4; j++)
            if ((i >> j) & 1) {
                apply(j, lamps);
                changes++;
            }
        if (c < changes || (c - changes) % 2 != 0) continue;
        if (check(lamps)) ans.push_back(lamps);
    }
    std::sort(ans.begin(), ans.end(), [](std::vector<int> a, std::vector<int> b) {
        for (int i = 1; i < n+1; i++)
            if (a[i] != b[i])
                return a[i] < b[i];
        return false;
    });

    FILE* out = fopen("lamps.out", "w");
    for (std::vector<int> lamps : ans) {
        for (int j = 1; j < n+1; j++)
            fprintf(out, "%d", (int)lamps[j]);
        fprintf(out, "\n");
    }
    if (ans.size() == 0)
        fprintf(out, "IMPOSSIBLE\n");
    fclose(out);
}
